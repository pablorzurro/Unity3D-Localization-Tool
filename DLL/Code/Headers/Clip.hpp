#ifndef LOCALIZATION_TOOL_CLIP_H_
#define LOCALIZATION_TOOL_CLIP_H_


#include <Declarations.hpp>


namespace prz
{

	class Clip
	{
	public:

		Clip(float startTime, float duration);
		Clip(Clip& other);
		Clip() = delete;

	public:

		void set_start_time(float startTime)
		{
			mStartTime = startTime;
		}

		void set_duration(float duration)
		{
			mDuration = duration;
		}

	public:

		float get_start_time(){ return mStartTime; }
		float get_duration(){ return mDuration; }

	private:

		float mStartTime;
		float mDuration;

	};

} // !namespace prz

#endif // !LOCALIZATION_TOOL_CLIP_H_
