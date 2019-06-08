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

	const char* get_text_clip_text(Text_Clip* textClip)
	{
		if (textClip)
		{
			return textClip->get_text().c_str();
		}

		return nullptr;
	}

}