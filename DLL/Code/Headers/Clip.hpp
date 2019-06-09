/**
 * @file Clip.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Store the basic information of any object of a timeline
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
	/**
	 * @brief Store the basic information of any object of a timeline
	 * 
	 */
	class Clip
	{
	public:
		
		/**
		 * @brief Construct a new Clip
		 * 
		 * @param name 
		 * @param startTime 
		 * @param duration 
		 */
		Clip(const string& name, float startTime, float duration);

		/**
		 * @brief Construct a new Clip
		 * 
		 * @param other 
		 */
		Clip(const Clip& other);

		/**
		 * @brief Construct a new Clip
		 * 
		 */
		Clip() = delete;

		/**
		 * @brief Destroy the Clip
		 * 
		 */
		~Clip();

	public:

		/**
		 * @brief return true if this clip is is overlapping with the other
		 * 
		 * @param other 
		 * @return true 
		 * @return false 
		 */
		bool collides_with(const Clip& other) const;

	public:

		/**
		 * @brief Set the name 
		 * 
		 * @param name 
		 */
		void set_name(const string& name);

		/**
		 * @brief Set the start time 
		 * 
		 * @param startTime 
		 */
		void set_start_time(float startTime);

		/**
		 * @brief Set the duration 
		 * 
		 * @param duration 
		 */
		void set_duration(float duration);
		
	public:

		/**
		 * @brief Get the name 
		 * 
		 * @return const PString& 
		 */
		const PString& get_name() { return m_name; }

		/**
		 * @brief Get the start time 
		 * 
		 * @return float 
		 */
		float get_start_time() { return m_startTime; }

		/**
		 * @brief Get the end time 
		 * 
		 * @return float 
		 */
		float get_end_time() { return m_endTime; }
		
		/**
		 * @brief Get the duration 
		 * 
		 * @return float 
		 */
		float get_duration() { return m_duration; }

	public:

		/**
		 * @brief Method to convert the information of this clip to a json object
		 * 
		 * @return json 
		 */
		virtual json to_json() = 0;
		
	protected:

		/**
		 * @brief 
		 * 
		 */
		void refresh_end_time();

	protected:

		PString m_name;
		float m_startTime;
		float m_endTime;
		float m_duration;

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_CLIP_H_
