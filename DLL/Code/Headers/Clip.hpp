/**
 * @file Clip.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 06-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_CLIP_H_
#define LOCALIZATION_TOOL_CLIP_H_

#include <Declarations.hpp>

namespace prz
{

	class Clip
	{
	public:

		Clip(float startTime, float duration);
		Clip(const Clip& other);
		Clip() = delete;

	public:

		void set_start_time(float startTime)
		{
			m_startTime = startTime;
		}

		void set_duration(float duration)
		{
			m_duration = duration;
		}

	public:

		float get_start_time(){ return m_startTime; }
		float get_duration(){ return m_duration; }

	protected:

		float m_startTime;
		float m_duration;

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_CLIP_H_
