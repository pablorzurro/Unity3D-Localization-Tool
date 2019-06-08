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

		LOCALIZATION_TOOL_API Text_Clip** get_text_track_clips(Text_Track* textTrack)
		{
			if (textTrack)
			{
				return textTrack->get_clips().data();
			}

			return nullptr;
		}

	}
	#pragma endregion TextTrackExport
	
}