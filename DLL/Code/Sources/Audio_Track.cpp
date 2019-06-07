#include <pch.h>
#include <Audio_Track.hpp>

namespace prz
{

	Audio_Track::Audio_Track()
	{
	}
	Audio_Track::~Audio_Track()
	{
	}


	extern "C"
	{
		float get_volume(Audio_Track* audioTrack)
		{
			if (audioTrack)
			{
				return audioTrack->get_volume();
			}

			return float::MinValue;
		}

		char get_spatial_blend_dimension(Audio_Track* audioTrack)
		{
			if (audioTrack)
			{
				char toReturn;
				if (audioTrack->get_spatial_blend_dimension() == 0)
				{
					toReturn = '2';
				}
				else
				{
					toReturn = '3';
				}
			}

			return '/0';
		}
	}

}
