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

		Sequence
		(
			const string& name,
			vector<shared_ptr<Audio_Track>>& audioTracks,
			vector<shared_ptr<Text_Track>>& textTracks
		);

		~Sequence();

	public:

		unsigned int get_number_of_audio_tracks()
		{
			return m_audioTracks.size();
		}

		unsigned int get_number_of_text_tracks()
		{
			return m_textTracks.size();
		}

	public:

		vector<shared_ptr<Audio_Track>> get_audio_tracks() { return m_audioTracks; }
		vector<shared_ptr<Text_Track>> get_text_tracks() { return m_textTracks; }

	private:

		vector<shared_ptr<Audio_Track>> m_audioTracks;
		vector<shared_ptr<Text_Track>> m_textTracks;

	private:

		char* m_name;

	};

} // !namespace prz


#endif // !LOCALIZATION_TOOL_SEQUENCE_H_
