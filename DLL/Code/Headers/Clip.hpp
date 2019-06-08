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

		Clip(const string& name, float startTime, float duration);
		Clip(const Clip& other);
		Clip() = delete;

		~Clip();

	public:

		bool collides_with(const Clip& other) const;

	public:

		void set_name(const string& name);
		void set_start_time(float startTime);
		void set_duration(float duration);
		
	public:

		const PString& get_name() { return m_name; }
		float get_start_time() { return m_startTime; }
		float get_end_time() { return m_endTime; }
		float get_duration() { return m_duration; }

	public:

		virtual json to_json() = 0;
		
	protected:

		void refresh_end_time();

	protected:

		PString m_name;
		float m_startTime;
		float m_endTime;
		float m_duration;

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_CLIP_H_
