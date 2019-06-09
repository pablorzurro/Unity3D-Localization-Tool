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

	/**
	 * @brief Clip that stores a text. It may contain font size aand style information in a future
	 * 
	 */
	class Text_Clip : public Clip
	{
	public:

		/**
		 * @brief Construct a new Text_Clip
		 * 
		 * @param text 
		 * @param startTime 
		 * @param duration 
		 */
		Text_Clip
		(
			const string& text,
			const string& name,
			float startTime,
			float duration
		);

		/**
		 * @brief Construct a new Text_Clip by copy
		 * 
		 * @param other 
		 */
		Text_Clip(Text_Clip& other);

	public:

		/**
		 * @brief Set the text
		 * 
		 * @param text 
		 */
		void set_text(const string& textStr);

	public:

		/**
		 * @brief Return the text
		 * 
		 * @return const PString& 
		 */
		const PString& get_text() const { return m_text; }

	public:

		/**
		 * @brief 
		 * 
		 * @return json 
		 */
		json to_json() final override;

	private:

		PString m_text;

	};

	#pragma region TEXT CLIP EXPORT

	extern "C"
	{
		/**
		 * @brief Set the text clip name 
		 * 
		 * @param textClip 
		 * @param name 
		 * @return true 
		 * @return false 
		 */
		/*LOCALIZATION_TOOL_API*/ bool set_text_clip_name(Text_Clip* textClip, const char* name);

		/**
		 * @brief Set the text clip start time 
		 * 
		 * @param textClip 
		 * @param startTime 
		 * @return true 
		 * @return false 
		 */
		/*LOCALIZATION_TOOL_API*/ bool set_text_clip_start_time(Text_Clip* textClip, float startTime);

		/**
		 * @brief Set the text clip duration 
		 * 
		 * @param textClip 
		 * @param duration 
		 * @return true 
		 * @return false 
		 */
		/*LOCALIZATION_TOOL_API*/ bool set_text_clip_duration(Text_Clip* textClip, float duration);

		/**
		 * @brief Set the text clip text 
		 * 
		 * @param textClip 
		 * @param text 
		 * @return true 
		 * @return false 
		 */
		/*LOCALIZATION_TOOL_API*/ bool set_text_clip_text(Text_Clip* textClip, const char* text);

		/**
		 * @brief Get the text clip name 
		 * 
		 * @param textClip 
		 * @return const PString* 
		 */
		/*LOCALIZATION_TOOL_API*/ const PString* get_text_clip_name(Text_Clip* textClip);

		/**
		 * @brief Get the text clip start time 
		 * 
		 * @param textClip 
		 * @return float 
		 */
		/*LOCALIZATION_TOOL_API*/ float get_text_clip_start_time(Text_Clip* textClip);

		/**
		 * @brief Get the text clip end time 
		 * 
		 * @param textClip 
		 * @return float 
		 */
		/*LOCALIZATION_TOOL_API*/ float get_text_clip_end_time(Text_Clip* textClip);

		/**
		 * @brief Get the text clip duration 
		 * 
		 * @param textClip 
		 * @return float 
		 */
		/*LOCALIZATION_TOOL_API*/ float get_text_clip_duration(Text_Clip* textClip);

		/**
		 * @brief Get the text clip text 
		 * 
		 * @param textClip 
		 * @return const PString* 
		 */
		/*LOCALIZATION_TOOL_API*/ const PString* get_text_clip_text(Text_Clip* textClip);

	}

	#pragma endregion


} // !namespace prz

#endif // !LOCALIZATION_TOOL_TEXT_CLIP_H_
