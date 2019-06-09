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
	
	bool Text_Track::conflicts_with_clip(Text_Clip* textClip)
	{
		bool isConflict = false;

		if (textClip)
		{
			size_t nClips = get_number_of_clips();
			for (size_t i = 0; i < nClips && !isConflict; i++)
			{
				isConflict = m_clips[i]->collides_with(*textClip);
			}
		}

		return isConflict;
	}

}