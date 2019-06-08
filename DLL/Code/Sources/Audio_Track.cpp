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

	#pragma region AudioTrackExport
	extern "C"
	{

		float get_audio_track_volume(Audio_Track* audioTrack)
		{
			if (audioTrack)
			{
				return audioTrack->get_volume();
			}

			return float::MinValue;
		}

		char get_audio_track_spatial_blend_dimension(Audio_Track* audioTrack)
		{
			if (audioTrack)
			{
				char toReturn;
				if (audioTrack->get_spatial_blend_dimension() == 0)
				{
					toReturn = (char)'2';
				}
				else
				{
					toReturn = (char)'3';
				}
			}

			return (char)'/0';
		}

		int get_audio_track_number_of_clips(Audio_Track* audioTrack)
		{
			if (audioTrack)
			{
				return audioTrack->get_number_of_clips();

			}

			return int::MinValue;
		}

		Audio_Clip** get_audio_track_clips(Audio_Track* audioTrack)
		{
			if (audioTrack)
			{
				return audioTrack->get_clips().data();
			}

			return nullptr;
		}

	}
	#pragma endregion AudioTrackExport

}
