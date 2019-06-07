#include "pch.h"
#include "Sequence.hpp"

namespace prz
{
	Sequence::Sequence(const string& name, vector<shared_ptr<Audio_Track>>& audioTracks, vector<shared_ptr<Text_Track>>& textTracks) : 
		m_name(to_char_array(name)),
		m_audioTracks(audioTracks),
		m_textTracks(textTracks)
	{}
	Sequence::~Sequence()
	{}
}
