#include <pch.h>
#include <Text_Clip.hpp>

#include <Utilities.hpp>

namespace prz
{

	Text_Clip::Text_Clip(const string& text, const string& name, float startTime, float duration) :
		Clip(name, startTime, duration),
		m_text(text)
	{}

	Text_Clip::Text_Clip(Text_Clip& other) :
		Clip(other)
	{}

	void Text_Clip::set_text(const string& textStr)
	{
		m_text = textStr;
	}

	json Text_Clip::to_json()
	{
		json j;

		j["Name"] = m_name;
		j["Start"] = m_startTime;
		j["End"] = m_endTime;
		j["Duration"] = m_duration;

		return j;
	}

	#pragma region TextClipExport
	extern "C"
	{

		bool set_text_clip_name(Text_Clip* textClip, const char* name)
		{
			if (textClip)
			{
				textClip->set_name(name);
				return true;
			}

			return false;
		}

		bool set_text_clip_start_time(Text_Clip* textClip, float startTime)
		{
			if (textClip)
			{
				textClip->set_start_time(startTime);
				return true;
			}

			return false;
		}

		bool set_text_clip_duration(Text_Clip* textClip, float duration)
		{
			if (textClip)
			{
				textClip->set_duration(duration);
				return true;
			}

			return false;
		}

		bool set_text_clip_text(Text_Clip* textClip, const char* text)
		{
			if (textClip)
			{
				textClip->set_text(get_string_from(text));
				return true;
			}

			return false;
		}

		const PString* get_text_clip_name(Text_Clip* textClip)
		{
			if (textClip)
			{
				return &textClip->get_name();
			}

			return nullptr;
		}

		float get_text_clip_start_time(Text_Clip* textClip)
		{
			if (textClip)
			{
				return textClip->get_start_time();
			}

			return float::MinValue;
		}

		float get_text_clip_end_time(Text_Clip* textClip)
		{
			if (textClip)
			{
				return textClip->get_end_time();
			}

			return float::MinValue;
		}

		float get_text_clip_duration(Text_Clip* textClip)
		{
			if (textClip)
			{
				return textClip->get_duration();
			}

			return float::MinValue;
		}

		const PString* get_text_clip_text(Text_Clip* textClip)
		{
			if (textClip)
			{
				return &textClip->get_text();
			}

			return nullptr;
		}

	}
	#pragma endregion TextClipExport

}