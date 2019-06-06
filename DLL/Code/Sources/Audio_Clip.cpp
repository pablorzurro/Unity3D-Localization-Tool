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
		m_originalFilePath(to_char_array(audioFilePath)),
		m_startClippingTime(startClippingTime)
	{}

	Audio_Clip::Audio_Clip(const Audio_Clip& other) :
		Clip(other),
		m_originalFilePath(get_copy_of(other.m_originalFilePath)),
		m_fileName(get_copy_of(other.m_fileName))
	{}

	Audio_Clip::~Audio_Clip()
	{
		delete[] m_originalFilePath;
		delete[] m_fileName;
	}

	void Audio_Clip::remove_clipping()
	{
		m_duration = -1.f;
		m_startClippingTime = 0.f;
	}

	void Audio_Clip::set_path(const char* path)
	{
		copy(path, m_originalFilePath);
	}

	void Audio_Clip::set_start_clipping_time(float startClippingTime)
	{
		m_startClippingTime = startClippingTime;
	}

	void Audio_Clip::set_file_length(float fileLength)
	{
		m_fileLength = fileLength;
	}

	void Audio_Clip::set(float startClippingTime, float fileLength)
	{
	}

	void Audio_Clip::extract_name_from(const char* path)
	{
		copy(to_char_array(split_string_by_separator(get_string_from(path), "/")), m_fileName);
	}
}


