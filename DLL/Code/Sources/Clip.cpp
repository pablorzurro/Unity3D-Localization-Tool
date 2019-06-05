#include <pch.h>
#include <Clip.hpp>

namespace prz
{

	Clip::Clip(float startTime, float duration) :
		mStartTime(startTime),
		mDuration(duration)
	{}

	Clip::Clip(Clip& other) :
		mStartTime(other.mStartTime),
		mDuration(other.mDuration)
	{}


}