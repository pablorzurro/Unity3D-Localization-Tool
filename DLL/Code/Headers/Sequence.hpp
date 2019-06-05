#pragma once



#include <Declarations.hpp>

class Audio_Track;
class Text_Track;

class Sequence
{

	vector <shared_ptr<Audio_Track>> mAudioTracks;
	vector <shared_ptr<Text_Track>> mTextTracks;
};