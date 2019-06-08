#include <pch.h>
#include <Audio_Clip.hpp>

#include <Utilities.hpp>

namespace prz
{
	Audio_Clip::Audio_Clip
	(
		const string& name,
		const string& audioFilePath,
		float startTime,
		float duration,
		float startCutTime
	) :
		Clip(name, startTime, duration),
		m_filePath(to_char_array(audioFilePath)),
		m_startCutTime(startCutTime)
	{}

	Audio_Clip::Audio_Clip(const Audio_Clip& other) :
		Clip(other),
		m_fileName(get_copy_of(other.m_fileName))
	{}

	Audio_Clip::~Audio_Clip()
	{
		delete[] m_fileName;
	}

	void Audio_Clip::remove_start_cut_time()
	{
		m_startCutTime = 0.f;
	}

	void Audio_Clip::set_file_path(const char* path)
	{
		copy(path, m_filePath);
		extract_name_from(path);
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

		j["Name"] = m_name;
		j["Path"] = m_filePath;
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

	#pragma region AUDIO CLIP EXPORT

	extern "C"
	{

		bool set_audio_clip_file_path(Audio_Clip* audioClip, const char* filePath)
		{
			if (audioClip)
			{
				audioClip->set_file_path(filePath);
				return true;
			}

			return false;
		}

		bool set_audio_clip_start_cut_time(Audio_Clip* audioClip, float startCutTime)
		{
			if (audioClip)
			{
				audioClip->set_start_cut_time(startCutTime);
				return true;
			}

			return false;
		}

		bool set_audio_clip_file_length(Audio_Clip* audioClip, float fileLength)
		{
			if (audioClip)
			{
				audioClip->set_file_length(fileLength);
				return true;
			}

			return false;
		}

		const char* get_audio_clip_file_path(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return audioClip->get_file_path();
			}

			return nullptr;
		}

		const char* get_audio_clip_file_name(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				audioClip->get_file_name();
			}

			return nullptr;
		}

		float get_audio_clip_start_cut_time(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				audioClip->get_start_cut_time();
			}

			return float::MinValue;
		}

		float get_audio_clip_file_length(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				audioClip->get_file_length();
			}

			return float::MinValue;
		}

	}

	#pragma endregion

}
