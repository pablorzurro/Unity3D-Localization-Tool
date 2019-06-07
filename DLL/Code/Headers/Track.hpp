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

namespace prz
{
	
	template<class ClipClass>
	class Track
	{
	public:

		Track(){}

		Track(forward_list<shared_ptr<ClipClass>>& clips) :
			m_clips(clips)
		{}

	public:

		bool add_clip(shared_ptr<ClipClass> clip);
		unsigned int force_add_clip(shared_ptr<ClipClass> clip);
		
	public:

		bool remove_clip_at(unsigned int index);
		bool remove_clip(shared_ptr<ClipClass> clip);

	public:

		vector<shared_ptr<ClipClass>> get_conflictive_clips_with(shared_ptr<ClipClass> clip) 
		{ 
			// vector<shared_ptr<ClipClass>>*
		}

		unsigned int get_number_of_clips()
		{
			return m_clips.size();
		}

	private:

		list<shared_ptr<ClipClass>> m_clips;

};

}


#endif // !LOCALIZATION_TOOL_TRACK_H_