#include <pch.h>
#include <File_Manager.hpp>

#include <Sequence.hpp>
#include <Text_Clip.hpp>
#include <Text_Track.hpp>
#include <Audio_Track.hpp>
#include <Audio_Clip.hpp>

#include <Utilities.hpp>

namespace prz
{

	int File_Manager::load_file(const string& filePath, bool forceReimport)
	{
		string fileName = split_string_by_separator(filePath, "/");
		bool isFileLoaded = is_file_loaded_by_name(fileName);

		int nSequencesLoaded = 0;

		if (isFileLoaded && forceReimport)
		{
			clear_file_sequences(fileName);
			isFileLoaded = is_file_loaded_by_name(filePath); // Check that has been succesfully deleted 
		}

		if (!isFileLoaded)
		{
			nSequencesLoaded = load_file_sequences(filePath);
		}
		else
		{
			nSequencesLoaded = get_file_number_of_sequences_by_path(filePath); // The file is loaded
		}

		return nSequencesLoaded;
	}

	int File_Manager::load_file_sequences(const string& filePath)
	{
		json json1 = load_json_file(filePath);
		string fileName = split_string_by_separator(filePath, "/");

		int nSequencesLoaded = 0;

		if (json1.size() != 0)
		{
			for (const auto& item : json1["sequences"])
			{
				Sequence* sequence = create_sequence(item);
				
				if (sequence)
				{
					++nSequencesLoaded;
					m_sequencesByFile[fileName].push_back(sequence);
				}
			}
		}

		return nSequencesLoaded;
	}

	bool File_Manager::copy_all_audio_clip_files_of_file(const string& fileName, const string& destination)
	{
		if (is_file_loaded_by_name(fileName))
		{
			auto& sequences = m_sequencesByFile[fileName];

			for (auto& iSequence :  sequences)
			{
				auto& audioTracks = iSequence->get_audio_tracks();

				for (auto& iAudioTrack : audioTracks)
				{
					auto& audioClips = iAudioTrack->get_clips();

					for (auto& iAudioClip : audioClips)
					{
						// If the file to copy exists and the file to copy doesn't exist in the destination path... 

						string iAudioClipFilePath = iAudioClip->get_file_path();
						string iAudioClipFileName = iAudioClip->get_file_name();
						if (filesystem::exists(iAudioClipFilePath)
							&& !filesystem::exists(destination + iAudioClipFileName))
						{
							filesystem::copy_file(iAudioClipFilePath, destination);
						}
					}
				}
			}

			return true;
		}

		return false;
	}

	Sequence* File_Manager::create_sequence(const value_json& sequenceItem)
	{
		if (sequenceItem.find("clips") != sequenceItem.end() && 
			sequenceItem.find("name") != sequenceItem.end())
		{
			Sequence* sequence = new Sequence(sequenceItem["name"]);

			// Load audio clips
			if (sequenceItem["clips"].find("audio") != sequenceItem["clips"].end())
			{
				for (const auto& iAudioClip : sequenceItem["clips"]["audio"])
				{
					sequence->create_audio_clip
					(
						iAudioClip["name"],
						iAudioClip["path"],
						iAudioClip["start"],
						iAudioClip["duration"],
						iAudioClip["start_cut"]
					);
				}
			}

			// Load text clips
			if (sequenceItem["clips"].find("text") != sequenceItem["clips"].end())
			{
				for (const auto& iTextClip : sequenceItem["clips"]["text"])
				{
					sequence->create_text_clip
					(
						iTextClip["text"],
						iTextClip["name"],
						iTextClip["start"],
						iTextClip["duration"]
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

	bool File_Manager::is_file_loaded_by_name(const string& fileName)
	{
		return m_sequencesByFile.find(fileName) != m_sequencesByFile.end();
	}

	bool File_Manager::is_file_loaded_by_path(const string& filePath)
	{
		return is_file_loaded_by_name(split_string_by_separator(filePath, "/"));
	}

	Sequence** File_Manager::get_file_sequences_by_name(const string& fileName)
	{
		if (is_file_loaded_by_name(fileName))
		{
			return m_sequencesByFile[fileName].data();
		}

		return nullptr;
	}

	Sequence** File_Manager::get_file_sequences_by_path(const string& filePath)
	{
		return get_file_sequences_by_name(split_string_by_separator(filePath, "/"));
	}

	int File_Manager::get_file_number_of_sequences_by_name(const string& fileName)
	{
		if (is_file_loaded_by_name(fileName))
		{
			return (int)m_sequencesByFile[fileName].size();
		}

		return 0;
	}

	int File_Manager::get_file_number_of_sequences_by_path(const string& filePath)
	{
		return get_file_number_of_sequences_by_name(split_string_by_separator(filePath, "/"));
	}

	File_Manager::~File_Manager()
	{
		for (auto& pair : m_sequencesByFile)
		{
			clear_file_sequences(pair.first);
		}
	}

	void File_Manager::clear_file_sequences(const string& fileName)
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
		int load_file(const char* jsonFilePath, bool forceReimport)
		{
			return File_Manager::instance().load_file(jsonFilePath,forceReimport);
		}

		Sequence** load_file_and_get_sequences(const char* jsonFilePath, bool forceReimport)
		{
			string path = get_string_from(jsonFilePath);
			File_Manager::instance().load_file(path, forceReimport);

			return File_Manager::instance().get_file_sequences_by_path(path);
		}

		bool is_file_loaded_by_path(const char* filePath)
		{
			string path = get_string_from(filePath);
			return File_Manager::instance().is_file_loaded_by_path(path);
		}

		bool is_file_loaded_by_name(const char* fileName)
		{
			string name = get_string_from(fileName);
			return File_Manager::instance().is_file_loaded_by_name(name);
		}

		Sequence** get_file_sequences_by_name(const char* fileName)
		{
			string name = get_string_from(fileName);
			return File_Manager::instance().get_file_sequences_by_name(name);
		}

		Sequence** get_file_sequences_by_path(const char* filePath)
		{
			string path = get_string_from(filePath);
			return File_Manager::instance().get_file_sequences_by_path(path);
		}

		int get_file_number_of_sequences_by_name(const char* fileName)
		{
			string name = get_string_from(fileName);
			return File_Manager::instance().get_file_number_of_sequences_by_name(name);
		}

		int get_file_number_of_sequences_by_path(const char* filePath)
		{
			string path = get_string_from(filePath);
			return File_Manager::instance().get_file_number_of_sequences_by_path(path);
		}

	}	
	#pragma endregion SequencesLoaderExport

}
