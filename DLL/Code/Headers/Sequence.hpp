/**
 * @file Sequence.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief c
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

	class Audio_Clip;
	class Text_Clip;
	class Audio_Track;
	class Text_Track;

	class Sequence
	{
	public:

		/**
		 * @brief Construct a new Sequence
		 * 
		 * @param name 
		 * @param audioTracks 
		 * @param textTracks 
		 */
		Sequence
		(
			const string& name = "Unnamed_Sequence"
		);
		
		/**
		 * @brief Destroy the Sequence
		 * 
		 */
		~Sequence();


	public:

		/**
		 * @brief Add an audio clip to the first available track
		 * 
		 * @param audioClip 
		 * @return Audio_Clip* 
		 */
		Audio_Clip* add_audio_clip(Audio_Clip* audioClip);

		/**
		 * @brief Add a text clip to the first available track
		 * 
		 * @param textClip 
		 * @return Text_Clip* 
		 */
		Text_Clip* add_text_clip(Text_Clip* textClip);

	public:

		/**
		 * @brief Create a new audio clip and save it in the first available track 
		 * 
		 * @param name 
		 * @param audioFilePath 
		 * @param startTime 
		 * @param duration 
		 * @param startCutTime 
		 * @return true 
		 * @return false 
		 */
		Audio_Clip* create_audio_clip
		(
			const string& name,
			const string& audioFilePath,
			const string& startTime,
			const string& duration,
			const string & startCutTime
		);

		/**
		 * @brief Create a text clip and save it in the first available track, if there aren't any tracks available, create a new one
		 * 
		 * @param text 
		 * @param name 
		 * @param startTime 
		 * @param duration
		 * @return true 
		 * @return false 
		 */
		Text_Clip* create_text_clip
		(	
			const string& text,
			const string& name,
			const string& startTime,
			const string& duration
		);

	public:

		/**
		 * @brief Return the number of audio tracks
		 * 
		 * @return unsigned int 
		 */
		unsigned int get_number_of_audio_tracks();

		/**
		 * @brief Return the number of text tracks
		 * 
		 * @return unsigned int 
		 */
		unsigned int get_number_of_text_tracks();

	public:

		/**
		 * @brief Return the audio tracks
		 * 
		 * @return vector<Audio_Track*>& 
		 */
		vector<Audio_Track*>& get_audio_tracks() { return m_audioTracks; }

		/**
		 * @brief Return the text tracks
		 * 
		 * @return vector<Text_Track*>& 
		 */
		vector<Text_Track*>& get_text_tracks() { return m_textTracks; }

		/**
		 * @brief Return the audio tracks as array
		 * 
		 * @return Audio_Track** 
		 */
		Audio_Track** get_audio_tracks_ptr() { return m_audioTracks.data(); }

		/**
		 * @brief Return the text tracks as array
		 * 
		 * @return Text_Track** 
		 */
		Text_Track** get_text_tracks_ptr() { return m_textTracks.data(); }


		const string& get_name() const { return m_name; }

	private:

		/**
		 * @brief Register a new audio clip in the first available track. If there is not any available, create a new one and register the clip
		 * 
		 * @param audioClip 
		 */
		void register_audio_clip(Audio_Clip* audioClip);

		/**
		 * @brief Register a new text clip in the first available track. If there is not any available, create a new one and register the clip
		 * 
		 * @param textClip 
		 */
		void register_text_clip(Text_Clip* textClip);
		
	private:

		vector<Audio_Track*> m_audioTracks;
		vector<Text_Track*> m_textTracks;

	private:

		string m_name;

	};

	#pragma region SequenceExport

	extern "C"
	{

		LOCALIZATION_TOOL_API const char* get_sequence_name(Sequence* sequence);
		LOCALIZATION_TOOL_API int get_sequence_number_of_audio_tracks(Sequence* sequence);
		LOCALIZATION_TOOL_API int get_sequence_number_of_text_tracks(Sequence* sequence);
		LOCALIZATION_TOOL_API Audio_Track** get_sequence_audio_tracks(Sequence* sequence);
		LOCALIZATION_TOOL_API Text_Track** get_sequence_text_tracks(Sequence* sequence);

	}

	#pragma endregion SequenceExport

} // !namespace prz

#endif // !LOCALIZATION_TOOL_SEQUENCE_H_
