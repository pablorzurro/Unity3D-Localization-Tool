/**
 * @file Track.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Set of clips(of any kind) aligned in time 
 * @version 0.1
 * @date 07-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_TRACK_H_
#define LOCALIZATION_TOOL_TRACK_H_

#include <Declarations.hpp>

#include <Clip.hpp>


namespace prz
{
	/**
	 * @brief Set of clips(of any kind) aligned in time 
	 * 
	 * @tparam ClipClass 
	 */
	template<class ClipClass>
	class Track
	{
		// Check if the class template meets the target base class conditions
		static_assert(std::is_base_of<Clip, ClipClass>::value, "ClipClass must derive from Clip");

	public:

		/**
		 * @brief Construct a new Track
		 * 
		 */
		Track(){}

		/**
		 * @brief Destroy the Track
		 * 
		 */
		~Track()
		{
			size_t nClips = m_clips.size();
			for (size_t i = 0; i < nClips; i++)
			{
				delete m_clips[i];
			}
		}

	public:

		/**
		 * @brief add a clip
		 * 
		 * @param clip 
		 * @return true 
		 * @return false 
		 */
		bool add_clip(ClipClass* clip)
		{
			if (!conflicts_with_clip(clip))
			{
				m_clips.push_back(clip);
				return true;
			}

			return false;
		}
		
	public:

		/**
		 * @brief Check if the input clip conflicts with this track 
		 * 
		 * @param clip 
		 * @return true 
		 * @return false 
		 */
		virtual bool conflicts_with_clip(ClipClass* clip) = 0;
		
	public:

		/**
		 * @brief Get the clips 
		 * 
		 * @return vector<ClipClass*>& 
		 */
		vector<ClipClass*>& get_clips()
		{
			return m_clips;
		}

	public:

		/**
		 * @brief Get the number of clips 
		 * 
		 * @return unsigned int 
		 */
		unsigned int get_number_of_clips()
		{
			return (unsigned int)m_clips.size();
		}

	public:
	
		/*virtual json to_json()
		{
			size_t nTracks = get_number_of_clips();

			for (size_t i = 0; i < nTracks; i++)
			{
				Clip* iClip = static_cast<Clip*>(m_clips[i]);
				iClip->to_json();
			}

		}*/

	protected:

		vector<ClipClass*> m_clips;

	};

}


#endif // !LOCALIZATION_TOOL_TRACK_H_