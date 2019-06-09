/**
 * @file Audio_Clip.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief A clip with the information of an audio file
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_AUDIO_CLIP_H_
#define LOCALIZATION_TOOL_AUDIO_CLIP_H_

#include <Clip.hpp>

namespace prz
{

	/**
	 * @brief A clip with the information of an audio file
	 * 
	 */
	class Audio_Clip : public Clip
	{
	public:

		/**
		 * @brief Construct a new Audio_Clip
		 * 
		 * @param name 
		 * @param audioFilePath 
		 * @param startTime 
		 * @param duration 
		 * @param startCutTime 
		 */
		Audio_Clip
		(
			const string& name,
			const string& audioFilePath,
			float startTime,
			float duration = -1.f,
			float startCutTime = 0.f
		);

		/**
		 * @brief Construct a new Audio_Clip by copy
		 * 
		 * @param other 
		 */
		Audio_Clip(const Audio_Clip& other);

	public:
		
		/**
		 * @brief Put the start cut time to 0. To cut 
		 * 
		 */
		void remove_start_cut_time();

	public:
		
		/**
		 * @brief Set the path
		 * 
		 * @param path 
		 */
		void set_file_path(const string& path);

		/**
		 * @brief Set the start cut time
		 * 
		 * @param startCutTime 
		 */
		void set_start_cut_time(float startCutTime);

		/**
		 * @brief Set the file length
		 * 
		 * @param fileLength 
		 */
		void set_file_length(float fileLength);

	public:

		/**
		 * @brief Get the file path 
		 * 
		 * @return const PString& 
		 */
		const PString& get_file_path() const { return m_filePath; }

		/**
		 * @brief Get the file name 
		 * 
		 * @return const PString& 
		 */
		const PString& get_file_name() const { return m_fileName; }
		
		/**
		 * @brief Get the start cut time 
		 * 
		 * @return float 
		 */
		float get_start_cut_time() const { return m_startCutTime; }

		/**
		 * @brief Get the file length 
		 * 
		 * @return float 
		 */
		float get_file_length() const { return m_fileLength; }

	public:

		/**
		 * @brief create a json object with this audio clip attributes
		 * 
		 * @return json 
		 */
		json to_json()final override;

	private:

		PString m_filePath;
		PString m_fileName;

	private:

		float m_startCutTime;
		float m_fileLength;

		//uint8_t m_audioFileBytes[]; // It's better to copy the assets with standard library filesystem API for the moment 

	};

	#pragma region AUDIO CLIP EXPORT

	extern "C"
	{
		/**
		 * @brief Set the audio clip name 
		 * 
		 * @param audioClip 
		 * @param name 
		 * @return true 
		 * @return false 
		 */
		LOCALIZATION_TOOL_API bool set_audio_clip_name(Audio_Clip* audioClip, const char* name);

		/**
		 * @brief Set the audio clip start time 
		 * 
		 * @param audioClip 
		 * @param startTime 
		 * @return true 
		 * @return false 
		 */
		LOCALIZATION_TOOL_API bool set_audio_clip_start_time(Audio_Clip* audioClip, float startTime);

		/**
		 * @brief Set the audio clip duration 
		 * 
		 * @param audioClip 
		 * @param duration 
		 * @return true 
		 * @return false 
		 */
		LOCALIZATION_TOOL_API bool set_audio_clip_duration(Audio_Clip* audioClip, float duration);

		/**
		 * @brief set the audio file path of the input audio clip
		 * 
		 * @param audioClip 
		 * @return bool
		 */
		LOCALIZATION_TOOL_API bool set_audio_clip_file_path(Audio_Clip* audioClip, const char* filePath);
		
		/**
		 * @brief set the start cut time of the input audio clip
		 * 
		 * @param startCutTime 
		 * @return bool
		 */
		LOCALIZATION_TOOL_API bool set_audio_clip_start_cut_time(Audio_Clip*, float startCutTime);

		/**
		 * @brief set the start cut time of the input audio clip
		 * 
		 * @param audioClip 
		 * @return bool
		 */
		LOCALIZATION_TOOL_API bool set_audio_clip_file_length(Audio_Clip* audioClip, float fileLength);

		/**
		 * @brief Get the audio clip name 
		 * 
		 * @param audioClip 
		 * @return const PString* 
		 */
		LOCALIZATION_TOOL_API const PString* get_audio_clip_name(Audio_Clip* audioClip);

		/**
		 * @brief Get the audio clip start time 
		 * 
		 * @param audioClip 
		 * @return float 
		 */
		LOCALIZATION_TOOL_API float get_audio_clip_start_time(Audio_Clip* audioClip);

		/**
		 * @brief Get the audio clip end time 
		 * 
		 * @param audioClip 
		 * @return float 
		 */
		LOCALIZATION_TOOL_API float get_audio_clip_end_time(Audio_Clip* audioClip);

		/**
		 * @brief Get the audio clip duration 
		 * 
		 * @param audioClip 
		 * @return float 
		 */
		LOCALIZATION_TOOL_API float get_audio_clip_duration(Audio_Clip* audioClip);

		/**
		 * @brief Get the audio clip file path 
		 * 
		 * @param audioClip 
		 * @return const PString* 
		 */
		LOCALIZATION_TOOL_API const PString* get_audio_clip_file_path(Audio_Clip* audioClip);
		
		/**
		 * @brief get the file path of an audio clip
		 * 
		 * @param audioClip 
		 * @return const char*
		 */
		LOCALIZATION_TOOL_API const PString* get_audio_clip_file_name(Audio_Clip* audioClip);

		/**
		 * @brief get the start cut time of an audio clip
		 * 
		 * @param audioClip 
		 * @return float
		 */
		LOCALIZATION_TOOL_API float get_audio_clip_start_cut_time(Audio_Clip* audioClip);
		
		/**
		 * @brief get the audio file length of an audio clip
		 * 
		 * @param audioClip 
		 * @return float
		 */
		LOCALIZATION_TOOL_API float get_audio_clip_file_length(Audio_Clip* audioClip);

	}

	#pragma endregion

} // !namespace prz

#endif // !LOCALIZATION_TOOL_AUDIO_CLIP_H_
