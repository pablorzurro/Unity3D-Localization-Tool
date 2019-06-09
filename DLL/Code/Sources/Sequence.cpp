#include <pch.h>
#include <Sequence.hpp>

#include <Audio_Clip.hpp>
#include <Audio_Track.hpp>
#include <Text_Clip.hpp>
#include <Text_Track.hpp>

#include <Utilities.hpp>

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

	Audio_Clip* Sequence::create_audio_clip(const string& name, const string& audioFilePath, const string& startTime, const string& duration, const string& startCutTime)
	{
		return add_audio_clip(new Audio_Clip
		(
			name,
			audioFilePath,
			get_seconds_from_string(startTime),
			get_seconds_from_string(duration),
			get_seconds_from_string(startCutTime)
		));
	}

	Text_Clip* Sequence::create_text_clip(const string& text, const string& name, const string& startTime, const string& duration)
	{
		return add_text_clip(new Text_Clip
		(
			text,
			name,
			get_seconds_from_string(startTime),
			get_seconds_from_string(duration)
		));
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

		for (size_t i = 0; i < nAudioTracks && !selectedTrack; i++)
		{
			if (m_audioTracks[i]->add_clip(audioClip))
			{
				return;
			}
		}

		selectedTrack = new Audio_Track();
		m_audioTracks.push_back(selectedTrack);
		selectedTrack->add_clip(audioClip);
	}

	void Sequence::register_text_clip(Text_Clip* textClip)
	{
		unsigned int nTextTracks = get_number_of_text_tracks();

		Text_Track* selectedTrack = nullptr;

		for (size_t i = 0; i < nTextTracks && !selectedTrack; i++)
		{
			if (m_textTracks[i]->add_clip(textClip))
			{
				return;
			}
		}

		selectedTrack = new Text_Track();
		m_textTracks.push_back(selectedTrack);
		selectedTrack->add_clip(textClip);
	}

	#pragma region SequenceExport
	extern "C"
	{

		const PString* get_sequence_name(Sequence* sequence)
		{
			if(sequence)
			{
				return &sequence->get_name();
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
