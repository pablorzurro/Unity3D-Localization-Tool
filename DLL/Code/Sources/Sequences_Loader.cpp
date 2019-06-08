#include <pch.h>
#include <Sequences_Loader.hpp>

#include <Sequence.hpp>

#include <Utilities.hpp>

namespace prz
{
	void Sequences_Loader::load_file_sequences(const string& filePath)
	{
		json j = load_json_file(filePath);

		if (j.size() != 0)
		{
			auto iEnd = j.end();
			for (auto it = j.begin(); it != iEnd; ++it)
			{
				string itKey = it.key();
				value_json& itValue = it.value();

				if (string_contains(itKey, "Sequences"))
				{
					create_sequence(itValue);
				}
			}
		}
	}

	Sequence* Sequences_Loader::create_sequence(const value_json& sequenceItem)
	{
		if (sequenceItem.is_array() && sequenceItem.contains("Name") 
			&& (sequenceItem.contains("Sound_Clips") || sequenceItem.contains("Subtitle_Clips")))
		{
			Sequence* s = new Sequence();

			value_json soundClipsRoot = sequenceItem.at("Sound_Clips");

			if (!soundClipsRoot.is_null())
			{
				if (soundClipsRoot.is_array())
				{
					/*soundClipsRoot.get();*/
				}
			}
		}

		return nullptr;
	}

	bool Sequences_Loader::is_file_loaded(const string& fileName)
	{
		return m_sequencesByFile.find(fileName) != m_sequencesByFile.end();
	}

	Sequences_Loader::~Sequences_Loader()
	{
	}

}
