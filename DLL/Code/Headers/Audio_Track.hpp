/**
 * @file Audio_Track.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Track of audio clips
 * @version 0.1
 * @date 06-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_AUDIO_TRACK_H_
#define LOCALIZATION_TOOL_AUDIO_TRACK_H_

#include <Track.hpp>
#include <Audio_Clip.hpp>

namespace prz
{

	/**
	 * @brief Track of audio clips
	 * 
	 */
	class Audio_Track : public Track<Audio_Clip>
	{
	public:

		/**
		 * @brief Dimension of the digital sound. Pure stereo (2D) or 3D 
		 * 
		 */
		enum Spatial_Blend_Dimension
		{
			TWO = 0,
			THREE = 1
		};

	public:

		/**
		 * @brief Construct a new Audio_Track
		 * 
		 */
		Audio_Track();

		/**
		 * @brief Destroy the Audio_Track
		 * 
		 */
		~Audio_Track();

	public:

		/**
		 * @brief Get the volume 
		 * 
		 * @return float 
		 */
		float get_volume() const { return m_volume; }

		/**
		 * @brief Get the spatial blend dimension 
		 * 
		 * @return Spatial_Blend_Dimension 
		 */
		Spatial_Blend_Dimension get_spatial_blend_dimension() const { return m_spatialBlendDimension; }

	private:

		float m_volume; // Clamped from 0.0 to 1.0
		Spatial_Blend_Dimension m_spatialBlendDimension; // 2D or 3D
	
	};

	#pragma region AudioTrackExport

	extern "C"
	{

		/**
		 * @brief Get the audio track volume 
		 * 
		 * @param audioTrack 
		 * @return float 
		 */
		/*LOCALIZATION_TOOL_API*/ float get_audio_track_volume(Audio_Track* audioTrack);

		/**
		 * @brief Returns the spatial blend dimension 
		 * 
		 * @param audioTrack 
		 * @return char. '2' for two dimensions, '3' for three dimensions, '/0' for input audio track nullptr
		 */
		/*LOCALIZATION_TOOL_API*/ char get_audio_track_spatial_blend_dimension(Audio_Track* audioTrack);

		/**
		 * @brief Return the number of clips of the input audio track
		 * 
		 * @param audioTrack 
		 * @return int 
		 */
		/*LOCALIZATION_TOOL_API*/ int get_audio_track_number_of_clips(Audio_Track* audioTrack);

		/**
		 * @brief Get the audio track clips 
		 * 
		 * @param audioTrack 
		 * @return Audio_Clip** 
		 */
		/*LOCALIZATION_TOOL_API*/ Audio_Clip** get_audio_track_clips(Audio_Track* audioTrack);
		
	}

	#pragma endregion

} // !namespace prz

#endif // !LOCALIZATION_TOOL_AUDIO_TRACK_H_
