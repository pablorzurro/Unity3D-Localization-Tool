#include <pch.h>
#include <Audio_Clip.hpp>

#include <Utilities.hpp>

namespace prz
{
	Audio_Clip::Audio_Clip
	(
		const string& audioFilePath,
		float startTime,
		float duration,
		float startClippingTime
	) :
		Clip(startTime, duration),
		m_filePath(to_char_array(audioFilePath)),
		m_startCutTime(startClippingTime)
	{}

	Audio_Clip::Audio_Clip(const Audio_Clip& other) :
		Clip(other),
		m_fileName(get_copy_of(other.m_fileName))
	{}

	Audio_Clip::~Audio_Clip()
	{
		delete[] m_fileName;
	}

	void Audio_Clip::remove_clipping()
	{
		m_duration = -1.f;
		m_startCutTime = 0.f;
	}

	void Audio_Clip::set_path(const char* path)
	{
		copy(path, m_filePath);
	}

	void Audio_Clip::set_start_cut_time(float startCutTime)
	{
		m_startCutTime = startCutTime;
	}

	void Audio_Clip::set_file_length(float fileLength)
	{
		m_fileLength = fileLength;
	}

	json Audio_Clip::to_json()
	{
		json j;

		j["Name"] = get_string_from(m_name);
		j["Path"] = get_string_from(m_filePath);
		j["Start"] = m_startTime;
		j["End"] = m_endTime;
		j["Duration"] = m_duration;

		if (m_fileLength != -1.f)
		{
			j["Length"] = m_fileLength;
		}

		if (m_startCutTime == 0.f)
		{
			j["Start_cut"] = m_startCutTime;
		}

		return j;
	}

	void Audio_Clip::extract_name_from(const char* path)
	{
		copy(to_char_array(split_string_by_separator(get_string_from(path), "/")), m_fileName);
	}
}


