#pragma once

#include <Declarations.hpp>

class Clip
{
public:

	Clip(float startTime, float duration) :
		mStartTime(startTime),
		mDuration(duration)
	{
		
	}

	Clip(Clip& other) :
		mStartTime(other.mStartTime),
		mDuration(other.mDuration)
	{}

	Clip() = delete;

private:

	float mStartTime;
	float mDuration;  
};

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
		mFilePath(new char[audioFilePath.length() + 1]),
		mStartClippingTime(startClippingTime)
	{}

private: 

	char* mFilePath;
	float mStartClippingTime;

	//uint8_t byteArray[];
};

class Text_Clip : public Clip
{

};