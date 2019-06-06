/**
 * @file Sequence.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_SEQUENCE_H_
#define LOCALIZATION_TOOL_SEQUENCE_H_

#include <Declarations.hpp>

namespace prz
{

	class Audio_Track;
	class Text_Track;

	class Sequence
	{
	public:

		Sequence(){}

	public:

		unsigned int get_number_of_audio_tracks()
		{

		}
		unsigned int get_number_of_text_tracks()
		{

		}

	private:

		vector <shared_ptr<Audio_Track>> m_audioTracks;
		vector <shared_ptr<Text_Track>> m_textTracks;
	};

} // !namespace prz


#endif // !LOCALIZATION_TOOL_SEQUENCE_H_
