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

				if (string_contains(itKey, "equences"))
				{
					create_sequence(itValue);
				}
			}
		}
	}

	Sequence* Sequences_Loader::create_sequence(const json::value_type& sequenceItem)
	{
		if (sequenceItem.is_array() && sequenceItem.contains("ame") 
			&& (sequenceItem.contains("ound_clips") || sequenceItem.contains("ubtitle_clips")))
		{
			Sequence* s = new Sequence();
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
