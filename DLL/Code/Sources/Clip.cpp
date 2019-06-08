#include <pch.h>
#include <Clip.hpp>

#include <Utilities.hpp>

namespace prz
{

	Clip::Clip(const string& name, float startTime, float duration) :
		m_name(name),
		m_startTime(startTime),
		m_duration(duration),
		m_endTime(startTime + duration)
	{}

	Clip::Clip(const Clip& other) :
		m_name(other.m_name),
		m_startTime(other.m_startTime),
		m_endTime(other.m_endTime),
		m_duration(other.m_duration)
	{}

	Clip::~Clip()
	{}

	bool Clip::collides_with(const Clip & other) const
	{
		if (other.m_startTime <= m_startTime && m_startTime <= other.m_endTime
			|| m_startTime >= other.m_startTime && other.m_startTime <= m_endTime)
		{
			return true;
		}

		return false;
	}

	void Clip::set_name(const string& name)
	{
		m_name = name;
	}

	void Clip::set_start_time(float startTime)
	{
		m_startTime = startTime;
		refresh_end_time();
	}

	void Clip::set_duration(float duration)
	{
		m_duration = duration;
		refresh_end_time();
	}

	void Clip::refresh_end_time()
	{
		m_endTime = m_startTime + m_duration;
	}
	
}
