/**
 * @file Audio_Clip.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
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

	class Audio_Clip : public Clip
	{

		/**
		 * @brief Construct a new Audio_Clip
		 *
		 * @param audioFilePath
		 * @param startTime
		 * @param duration. If the value is -1.0, this audio clip has the same duration as the length of the corresponding file.
		 * @param startClippingTime. If the start clipping time is 0.0, there is no clipping
		 */
		Audio_Clip
		(
			const string& audioFilePath,
			float startTime,
			float duration = -1.f,
			float startClippingTime = 0.f
		);

		Audio_Clip(const Audio_Clip& other);
		~Audio_Clip();

	public:

		void remove_clipping();

	public:

		void set_path(const char* path);
		void set_start_cut_time(float startClippingTime);
		void set_file_length(float fileLength);

	public:

		const char* get_file_path() const { return m_filePath; }
		const char* get_file_name() const { return m_fileName; }
		float get_start_clipping_time() const { return m_startCutTime; }

	public:

		json to_json()final override;

	private:

		void extract_name_from(const char* path);

	private:

		char* m_filePath;
		char* m_fileName;

	private:

		float m_startCutTime;
		float m_fileLength;

		//uint8_t m_audioFileBytes[];

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_AUDIO_CLIP_H_
