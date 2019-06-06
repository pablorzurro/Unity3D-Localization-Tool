#include <pch.h>
#include <Clip.hpp>

namespace prz
{

	Clip::Clip(float startTime, float duration) :
		m_startTime(startTime),
		m_duration(duration)
	{}

	Clip::Clip(const Clip& other) :
		m_startTime(other.m_startTime),
		m_duration(other.m_duration)
	{}


}