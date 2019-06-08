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
			const vector<uint8_t>& text,
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
		void set_text(const vector<uint8_t>& textStr);

	public:

		/**
		 * @brief Get the text
		 * 
		 * @return const char* 
		 */
		const uint8_t* get_text() const { return m_text.data(); }
		const unsigned int get_text_size() const { return (unsigned int)m_text.size(); }

	public:

		json to_json() final override;

	private:

		vector<uint8_t> m_text;

	};

	#pragma region TEXT CLIP EXPORT

	extern "C"
	{
		/**
		 * @brief get the text clip content
		 * 
		 * @param textClip 
		 * @return const char* 
		 */
		LOCALIZATION_TOOL_API const uint8_t* get_text_clip_text(Text_Clip* textClip);
	}

	#pragma endregion


} // !namespace prz

#endif // !LOCALIZATION_TOOL_TEXT_CLIP_H_
