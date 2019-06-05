#include "pch.h"
#include <Text_Clip.hpp>

#include <Utilities.hpp>

namespace prz
{

	Text_Clip::Text_Clip(const string& text, float startTime, float duration) :
		Clip(startTime, duration),
		m_text(new char[text.length() + 1])
	{}

	void Text_Clip::set_text(const char* text)
	{
		copy(text, m_text);
	}

	void Text_Clip::set_text(const string& text)
	{
	}

	string Text_Clip::get_text_as_string() const
	{
		return get_string_from(m_text);
	}

}