/**
 * @file Text_Track.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief A track of text clips
 * @version 0.1
 * @date 06-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_TEXT_TRACK_H_
#define LOCALIZATION_TOOL_TEXT_TRACK_H_

#include <Track.hpp>
#include <Text_Clip.hpp>

namespace prz
{

	/**
	 * @brief A track of text clips
	 * 
	 */
	class Text_Track : public Track<Text_Clip>
	{
	public:

		/**
		 * @brief Construct a new Text_Track
		 * 
		 */
		Text_Track(){}

		/**
		 * @brief Destroy the Text_Track
		 * 
		 */
		~Text_Track(){}

	public:

		bool conflicts_with_clip(Text_Clip* textClip) final override;

	};

	#pragma region TextTrackExport

	extern "C"
	{
		/**
		 * @brief Get the text track number of clips 
		 * 
		 * @param textTrack 
		 * @return int 
		 */
		LOCALIZATION_TOOL_API int get_text_track_number_of_clips(Text_Track* textTrack);

		/**
		 * @brief Get the text track clips 
		 * 
		 * @param audioTrack 
		 * @return Text_Clip** 
		 */
		LOCALIZATION_TOOL_API Text_Clip** get_text_track_clips(Text_Track* audioTrack);

	}

	#pragma endregion TextTrackExport

} // !namespace prz

#endif // !LOCALIZATION_TOOL_TEXT_TRACK_H_
