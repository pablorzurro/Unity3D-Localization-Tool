#include <pch.h>
#include <Sequence.hpp>

#include <Audio_Clip.hpp>
#include <Audio_Track.hpp>
#include <Text_Clip.hpp>
#include <Text_Track.hpp>

namespace prz
{

	Sequence::Sequence(const string& name) : 
		m_name(to_char_array(name))
	{}

	Sequence::~Sequence()
	{
		unsigned int nAudioTracks = get_number_of_audio_tracks();
		unsigned int nTextTracks = get_number_of_text_tracks();

		for (size_t i = 0; i < nAudioTracks; ++i)
		{
			delete m_audioTracks[i];
		}
		for (size_t i = 0; i < get_number_of_text_tracks(); ++i)
		{
			delete m_textTracks[i];
		}

		delete[] m_name;
	}

	Audio_Clip* Sequence::add_audio_clip(Audio_Clip* audioClip)
	{
		if (audioClip)
		{	
			register_audio_clip(audioClip);
			return audioClip;
		}

		return nullptr;
	}

	Text_Clip* Sequence::add_text_clip(Text_Clip* textClip)
	{
		if (textClip)
		{
			register_text_clip(textClip);
			return textClip;
		}

		return nullptr;
	}

	Audio_Clip* Sequence::create_audio_clip(const string& name, const string& audioFilePath, float startTime, float duration, float startCutTime)
	{
		if (filesystem::exists(audioFilePath))
		{
			return new Audio_Clip(name, audioFilePath, startTime, duration, startCutTime);
		}

		return nullptr;
	}

	Text_Clip* Sequence::create_text_clip(const vector<uint8_t>& text, const string& name, float startTime, float duration)
	{
		if (text.size() != 0) // Disable this check if desired
		{
			return new Text_Clip(text, name, startTime, duration);
		}

		return nullptr;
	}

	unsigned int Sequence::get_number_of_audio_tracks()
	{
		return (unsigned int)m_audioTracks.size();
	}

	unsigned int Sequence::get_number_of_text_tracks()
	{
		return (unsigned int)m_textTracks.size();
	}

	void Sequence::register_audio_clip(Audio_Clip* audioClip)
	{
		unsigned int nAudioTracks = get_number_of_audio_tracks();

		Audio_Track* selectedTrack = nullptr;

		if (nAudioTracks == 0)
		{
			m_audioTracks.push_back(new Audio_Track());
			selectedTrack = m_audioTracks.back();
		}

		for (size_t i = 0; i < nAudioTracks && !selectedTrack; i++)
		{
			if(!m_audioTracks[i]->conflicts_with_clips(audioClip))
			{
				selectedTrack = m_audioTracks[i];
			}
		}

		if (!selectedTrack)
		{
			m_audioTracks.push_back(new Audio_Track());
			selectedTrack = m_audioTracks.back();
		}

		selectedTrack->add_clip(audioClip);
	}

	void Sequence::register_text_clip(Text_Clip* textClip)
	{
		unsigned int nTextTracks = get_number_of_text_tracks();

		Text_Track* selectedTrack = nullptr;

		if (nTextTracks == 0)
		{
			m_textTracks.push_back(new Text_Track());
			selectedTrack = m_textTracks.back();
		}

		for (size_t i = 0; i < nTextTracks && !selectedTrack; i++)
		{
			if (!m_textTracks[i]->conflicts_with_clips(textClip))
			{
				selectedTrack = m_textTracks[i];
			}
		}

		if (!selectedTrack)
		{
			m_audioTracks.push_back(new Audio_Track());
			selectedTrack = m_textTracks.back();
		}

		selectedTrack->add_clip(textClip);
	}

	#pragma region SequenceExport
	extern "C"
	{

		const char* get_sequence_name(Sequence* sequence)
		{
			if(sequence)
			{
				sequence->get_name();
			}

			return nullptr;
		}

		int get_sequence_number_of_audio_tracks(Sequence* sequence)
		{
			if (sequence)
			{
				return sequence->get_number_of_audio_tracks();
			}

			return int::MinValue;
		}

		int get_sequence_number_of_text_tracks(Sequence* sequence)
		{
			if (sequence)
			{
				return sequence->get_number_of_text_tracks();
			}
			
			return int::MinValue;
		}

		Audio_Track** get_sequence_audio_tracks(Sequence* sequence)
		{
			if (sequence)
			{
				return sequence->get_audio_tracks_ptr();
			}

			return nullptr;
		}

		Text_Track** get_sequence_text_tracks(Sequence* sequence)
		{
			if (sequence)
			{
				return sequence->get_text_tracks_ptr();
			}

			return nullptr;
		}

	}
	#pragma endregion SequenceExport

}
