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

		enum Spatial_Blend_Dimension
		{
			TWO = 0,
			THREE = 1
		};

	public:
	
		Audio_Track();
		~Audio_Track();

	public:

		float get_volume() const { return m_volume; }
		Spatial_Blend_Dimension get_spatial_blend_dimension() const { return m_spatialBlendDimension; }

	private:

		float m_volume; // Clamped from 0.0 to 1.0
		Spatial_Blend_Dimension m_spatialBlendDimension; // 2D or 3D
	
	};

	#pragma region AUDIO TRACK EXPORT

	extern "C"
	{

		LOCALIZATION_TOOL_API float get_volume(Audio_Track* audioTrack);
		LOCALIZATION_TOOL_API char get_spatial_blend_dimension(Audio_Track* audioTrack);
		
	}

	#pragma endregion

} // !namespace prz

#endif // !LOCALIZATION_TOOL_AUDIO_TRACK_H_
