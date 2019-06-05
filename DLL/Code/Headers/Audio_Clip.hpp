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
		 * @param duration. If the value is -1.0, this audio clip has the same duration as its corresponding file.
		 * @param startClippingTime. If the start clipping time is 0.0, there is no clipping
		 */
		Audio_Clip
		(
			const string& audioFilePath,
			float startTime,
			float duration = -1.f,
			float startClippingTime = 0.f
		) :
			Clip(startTime, duration),
			m_filePath(new char[audioFilePath.length() + 1]),
			m_startClippingTime(startClippingTime)
		{}

		~Audio_Clip();

	private:

		char* m_filePath;
		char* m_fileName;
		char* m_completeFilePath; // File path + name

	private:

		float m_startClippingTime;

		//uint8_t m_audioFileBytes[];

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_AUDIO_CLIP_H_
