#include <pch.h>
#include <Sequences_Loader.hpp>

#include <Sequence.hpp>

#include <Utilities.hpp>

namespace prz
{

	void Sequences_Loader::load_file(const string& filePath, bool forceReimport)
	{
		string fileName = split_string_by_separator(filePath, "/");
		bool isFileLoaded = is_file_loaded_by_name(filePath);

		if (isFileLoaded && forceReimport)
		{
			clear_file_sequences(fileName);
			isFileLoaded = is_file_loaded_by_name(filePath); // Check that has been succesfully deleted 
		}

		if (!isFileLoaded)
		{
			load_file_sequences(filePath);
		}
	}

	void Sequences_Loader::load_file_sequences(const string& filePath)
	{
		json json1 = load_json_file(filePath);

		if (json1.size() != 0)
		{
			auto iEnd = json1.end();
			for (auto it = json1.begin(); it != iEnd; ++it)
			{
				string itKey = it.key();
				value_json& itValue = it.value();

				for (const auto& item : json1["sequences"]["sequence"])
				{
					create_sequence(item);
				}
			}
		}
	}

	Sequence* Sequences_Loader::create_sequence(const value_json& sequenceItem)
	{
		if (sequenceItem.find("clips") != sequenceItem.end())
		{
			Sequence* sequence = new Sequence();

			if (sequenceItem["clips"].find("audio") != sequenceItem["clips"].end())
			{
				for (const auto& iAudioClip : sequenceItem["clips"]["audio"])
				{
					sequence->create_audio_clip
					(
						iAudioClip.at("name"),
						iAudioClip.at("path"),
						iAudioClip.at("start"),
						iAudioClip.at("duration"),
						iAudioClip.at("start_cut")
					);
				}
			}

			if (sequenceItem["clips"].find("text") != sequenceItem["clips"].end())
			{
				for (const auto& iTextClip : sequenceItem["clips"]["text"])
				{

					vector<uint8_t> textClipText = iTextClip.at("text");

					sequence->create_text_clip
					(
						iTextClip.at("name"),
						iTextClip.at("start"),
						iTextClip.at("duration"),
						iTextClip.at("text")
					);
				}
			}

			// If the sequence is empty, delete it
			if (sequence->get_number_of_audio_tracks() > 0 || sequence->get_number_of_text_tracks() > 0)
			{
				return sequence;
			}
			else
			{
				delete sequence;
			}
		}

		return nullptr;
	}

	bool Sequences_Loader::is_file_loaded_by_name(const string& fileName)
	{
		return m_sequencesByFile.find(fileName) != m_sequencesByFile.end();
	}

	bool Sequences_Loader::is_file_loaded_by_path(const string& filePath)
	{
		return is_file_loaded_by_name(split_string_by_separator(filePath, "/"));
	}


	Sequence** Sequences_Loader::get_file_sequences_by_name(const string& fileName)
	{
		if (is_file_loaded_by_name(fileName))
		{
			return m_sequencesByFile[fileName].data();
		}

		return nullptr;
	}

	Sequence** Sequences_Loader::get_file_sequences_by_path(const string& filePath)
	{
		return get_file_sequences_by_name(split_string_by_separator(filePath, "/"));
	}

	int Sequences_Loader::get_file_number_of_sequences_by_name(const string& fileName)
	{
		if (is_file_loaded_by_name(fileName))
		{
			(int)m_sequencesByFile[fileName].size();
		}

		return 0;
	}

	int Sequences_Loader::get_file_number_of_sequences_by_path(const string& filePath)
	{
		return get_file_number_of_sequences_by_name(split_string_by_separator(filePath, "/"));
	}

	Sequences_Loader::~Sequences_Loader()
	{
		for (auto& pair : m_sequencesByFile)
		{
			clear_file_sequences(pair.first);
		}
	}

	void Sequences_Loader::clear_file_sequences(const string& fileName)
	{
		auto& vectorToClear = m_sequencesByFile[fileName];
		size_t nSequences = get_file_number_of_sequences_by_name(fileName);

		for (size_t i = 0; i < nSequences; ++i)
		{
			delete vectorToClear[i];
		}

		m_sequencesByFile.erase(fileName);
	}

#pragma region SequencesLoaderExport

	extern "C"
	{

		Sequence** load_file(const char* jsonFilePath, bool forceReimport)
		{
			Sequences_Loader::instance().load_file(jsonFilePath, forceReimport);

			return get_file_sequences_by_path(jsonFilePath);
		}

		bool is_file_loaded_by_path(const string& filePath)
		{
			return Sequences_Loader::instance().is_file_loaded_by_path(filePath);
		}

		bool is_file_loaded_by_name(const string& fileName)
		{
			return Sequences_Loader::instance().is_file_loaded_by_name(fileName);
		}

		Sequence** get_file_sequences_by_name(const string& fileName)
		{
			return Sequences_Loader::instance().get_file_sequences_by_name(fileName);
		}

		Sequence** get_file_sequences_by_path(const string& filePath)
		{
			return get_file_sequences_by_path(filePath);
		}

		int get_file_number_of_sequences_by_name(const string& fileName)
		{
			return Sequences_Loader::instance().get_file_number_of_sequences_by_name(fileName);
		}

		int get_file_number_of_sequences_by_path(const string& filePath)
		{
			return Sequences_Loader::instance().get_file_number_of_sequences_by_path(filePath);
		}

	}

#pragma endregion SequencesLoaderExport

}
