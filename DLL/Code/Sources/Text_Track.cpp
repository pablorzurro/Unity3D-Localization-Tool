#include <pch.h>
#include <Text_Track.hpp>

namespace prz
{

	#pragma region TextTrackExport
	extern "C"
	{

		int get_text_track_number_of_clips(Text_Track* textTrack)
		{
			if (textTrack)
			{
				return textTrack->get_number_of_clips();

			}

			return int::MinValue;
		}

	}
	#pragma endregion TextTrackExport
	
}