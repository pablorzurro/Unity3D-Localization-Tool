/**
 * @file Audio_Track.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 06-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_AUDIO_TRACK_H_
#define LOCALIZATION_TOOL_AUDIO_TRACK_H_

#include <Track.hpp>
#include <Audio_Clip.hpp>

namespace prz
{

	class Audio_Track : public Track<Audio_Clip>
	{
	public:
	
		Audio_Track();
		~Audio_Track();

	private:

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_AUDIO_TRACK_H_
