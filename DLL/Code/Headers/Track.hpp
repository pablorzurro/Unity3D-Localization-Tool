#pragma once

#include <Declarations.hpp>

template<class ClipClass>
class Track
{
public:

	Track(){}

	Track(forward_list<shared_ptr<ClipClass>>& clips) :
		mClips(clips)
	{}

	vector<shared_ptr<ClipClass>> get_conflictive_clips_with(shared_ptr<ClipClass> clip) 
	{ 
		vector<shared_ptr<ClipClass>>*
	}

private:

	forward_list<shared_ptr<ClipClass>> mClips;

};