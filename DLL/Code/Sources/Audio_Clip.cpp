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
		m_filePath(audioFilePath),
		m_fileName(split_string_by_separator(m_filePath, "/")),
		m_startCutTime(startCutTime)
	{}

	Audio_Clip::Audio_Clip(const Audio_Clip& other) :
		Clip(other),
		m_fileName(other.m_fileName)
	{}

	void Audio_Clip::remove_start_cut_time()
	{
		m_startCutTime = 0.f;
	}

	void Audio_Clip::set_file_path(const string& path)
	{
		m_filePath = path;
		m_fileName = split_string_by_separator(path, "/");
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

	#pragma region AUDIO CLIP EXPORT

	extern "C"
	{

		bool set_audio_clip_name(Audio_Clip* audioClip, const char* name)
		{
			if (audioClip)
			{
				audioClip->set_name(name);
				return true;
			}

			return false;
		}

		bool set_audio_clip_start_time(Audio_Clip* audioClip, float startTime)
		{
			if (audioClip)
			{
				audioClip->set_start_time(startTime);
				return true;
			}

			return false;
		}

		bool set_audio_clip_duration(Audio_Clip* audioClip, float duration)
		{
			if (audioClip)
			{
				audioClip->set_duration(duration);
				return true;
			}

			return false;
		}

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

		const PString* get_audio_clip_name(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return &audioClip->get_name();
			}

			return nullptr;
		}

		float get_audio_clip_start_time(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return audioClip->get_start_time();
			}

			return float::MinValue;
		}

		float get_audio_clip_end_time(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return audioClip->get_end_time();
			}

			return float::MinValue;
		}

		float get_audio_clip_duration(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return audioClip->get_duration();
			}

			return float::MinValue;
		}

		const PString* get_audio_clip_file_path(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return &audioClip->get_file_path();
			}

			return nullptr;
		}

		const PString* get_audio_clip_file_name(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return &audioClip->get_file_name();
			}

			return nullptr;
		}

		float get_audio_clip_start_cut_time(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return audioClip->get_start_cut_time();
			}

			return float::MinValue;
		}

		float get_audio_clip_file_length(Audio_Clip* audioClip)
		{
			if (audioClip)
			{
				return audioClip->get_file_length();
			}

			return float::MinValue;
		}

	}

	#pragma endregion

}
