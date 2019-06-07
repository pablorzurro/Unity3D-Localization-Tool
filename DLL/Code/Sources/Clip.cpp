#include <pch.h>
#include <Clip.hpp>

#include <Utilities.hpp>

namespace prz
{

	Clip::Clip(const string& name, float startTime, float duration) :
		m_name(to_char_array(name)),
		m_startTime(startTime),
		m_duration(duration)
	{}

	Clip::Clip(const Clip& other) :
		m_name(get_copy_of(m_name)),
		m_startTime(other.m_startTime),
		m_endTime(other.m_endTime),
		m_duration(other.m_duration)
	{}

	Clip::~Clip()
	{
		delete[] m_name;
	}

	bool Clip::collides_with(const Clip & other) const
	{
		if (other.m_startTime <= m_startTime && m_startTime <= other.m_endTime
			|| m_startTime >= other.m_startTime && other.m_startTime <= m_endTime)
		{
			return true;
		}

		return false;
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

	#pragma region CLIP EXPORT
	extern "C"
	{

		float get_start_time(Clip* clip)
		{
			if (clip)
			{
				return clip->get_start_time();
			}

			return float::MinValue;
		}

		const char* get_name(Clip* clip)
		{
			if (clip)
			{
				return clip->get_name();
			}

			return nullptr;
		}

		float get_end_time(Clip* clip)
		{
			if (clip)
			{
				return clip->get_end_time();
			}

			return float::MinValue;
		}

		float get_duration(Clip* clip)
		{
			if (clip)
			{
				return clip->get_duration();
			}

			return float::MinValue;
		}

	}
	#pragma endregion
	
}

