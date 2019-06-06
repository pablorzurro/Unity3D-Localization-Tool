/**
 * @file Text_Clip.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Clip that stores a text
 * @version 0.1
 * @date 06-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_TEXT_CLIP_H_
#define LOCALIZATION_TOOL_TEXT_CLIP_H_

#include <Clip.hpp>

namespace prz
{

	class Text_Clip : public Clip
	{
	public:

		Text_Clip
		(
			const string& text,
			float startTime,
			float duration
		);

		Text_Clip(Text_Clip& other) :
			Clip(other)
		{}

	public:

		void set_text(const char* text);
		void set_text(const string& text);

	public:

		const char* get_text() const { return m_text; }
		string get_text_as_string() const;

	private:

		char* m_text;

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_TEXT_CLIP_H_
