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
	
	template<class ClipClass>
	class Track
	{

		static_assert(std::is_base_of<Clip, ClipClass>::value, "ClipClass must derive from Clip");

	public:

		Track(){}

		~Track()
		{
			size_t nClips = m_clips.size();
			for (size_t i = 0; i < nClips; i++)
			{
				delete m_clips[i];
			}
		}

	public:

		bool add_clip(ClipClass* clip)
		{
			if (!conflicts_with_clips(clip))
			{
				m_clips.push_back(clip);
			}

			return false;
		}
		
	public:

		virtual bool conflicts_with_clips(ClipClass* clip)
		{
			bool isConflict = false;

			if (clip)
			{
				Clip* clipPtr = static_cast<Clip*>(clip);

				if (clipPtr)
				{
					size_t nClips = get_number_of_clips();

					for (size_t i = 0; i < nClips && !isConflict; i++)
					{
						Clip* iClip = static_cast<Clip*>(m_clips[i]);

						if (iClip)
						{
							isConflict = iClip->collides_with(*clipPtr);
						}
					}

				}
			}

			return isConflict;
		}
		
	public:

		vector<ClipClass*>& get_clips()
		{
			return m_clips;
		}

	public:

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

	private:

		vector<ClipClass*> m_clips;

	};

}


#endif // !LOCALIZATION_TOOL_TRACK_H_