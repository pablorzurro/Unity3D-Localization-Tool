using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.InteropServices;
using System;

namespace LocalizationTool
{
    #if (UNITY_EDITOR)

    public unsafe class LocalizationToolWrapper : MonoBehaviour
    {

        #region Native

        #region Sequence

        public struct Sequence { }


        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern PString* get_sequence_name(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_sequence_number_of_audio_tracks(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_sequence_number_of_text_tracks(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern AudioTrack** get_sequence_audio_tracks(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern TextTrack** get_sequence_text_tracks(Sequence* sequence);

        #endregion

        #region File(JSON) Manager

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern Sequence** load_file(string jsonFilePath, bool forceReimport = false);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern Sequence** get_file_sequences_by_name(string fileName);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern Sequence** get_file_sequences_by_path(string filePath);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool is_file_loaded_by_name(string fileName);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool is_file_loaded_by_path(string filePath);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_file_number_of_sequences_by_name(string fileName);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_file_number_of_sequences_by_path(string filePath);

        #endregion

        #region Clips

            #region Audio Clip 

            public struct AudioClip { }
        
            // Setters

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_name(AudioClip* audioClip, string name);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_start_time(AudioClip* audioClip, float startTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_duration(AudioClip* audioClip, float duration);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_file_path(AudioClip* audioClip, string filePath);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_start_cut_time(AudioClip* audioClip, string startCutTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_file_length(AudioClip* audioClip, string fileLength);

            // Getters    

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_audio_clip_name(AudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_start_time(AudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_end_time(AudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_duration(AudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_audio_clip_file_path(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_audio_clip_file_name(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_start_cut_time(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_file_length(AudioClip* audioClip);

            #endregion // !Audio Clip

            #region Text Clip

            public struct TextClip { }

            // Setters

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_name(TextClip* clip, string name);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_start_time(TextClip* clip, float startTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_duration(TextClip* clip, float duration);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_text(TextClip* clip, string text);

            // Getters

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern /*PString**/ IntPtr get_text_clip_name(TextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_text_clip_start_time(TextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_text_clip_end_time(TextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_text_clip_duration(TextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_text_clip_text(TextClip* clip);

            #endregion // !Text Clip

        #endregion // !Clips

        #region Tracks

            #region Audio Track

            public struct AudioTrack { }

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_track_volume(AudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern char get_audio_track_spatial_blend_dimension(AudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern int get_audio_track_number_of_clips(AudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern AudioClip** get_audio_track_clips(AudioTrack* audioTrack);

            #endregion // !Audio Track

            #region Text Track

            public struct TextTrack { }

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern int get_text_track_number_of_clips(TextTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern TextClip** get_text_track_clips(TextTrack* audioTrack);

            #endregion // !Text Track

        #endregion // !Tracks

        #region Testing

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern float test_get_seconds_from_string(string str);

        #endregion

        #region PString

        public struct PString { }

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_pstring_size(PString* pString);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr get_pstring_char_array(PString* pString);

        #endregion


        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr test_me(string s);

        #endregion // !Native

        #region API Friendly

        public static void Test()
        {
            Debug.Log(test_get_seconds_from_string("00:30:040"));

        }

        public static void Test2()
        {
            //Sequence** seq = load_file("Assets/Plugins/Localization Tool/translation_example.json");

            Sequence** seq = load_file("Assets/Plugins/Localization Tool/translation_example.json");

            //Debug.Log(get_sequence_number_of_text_tracks(seq[0]));
            //Debug.Log(get_sequence_number_of_audio_tracks(seq[0]));

            TextTrack** tts = get_sequence_text_tracks(seq[0]);
            TextTrack* tt = tts[0];
            TextClip** tcs = get_text_track_clips(tt);
            TextClip* tc = tcs[0];

            //string tcName = Marshal.PtrToStringUni(get_pstring_char_array(get_text_clip_name(tc)));
            string tcName = Marshal.PtrToStringAnsi(get_text_clip_name(tc));
            Debug.Log(tcName);
            //Debug.Log(get_pstring_size(get_text_clip_name(tc)));

            string tcText = Marshal.PtrToStringAnsi(get_pstring_char_array(get_text_clip_text(tc)));
            Debug.Log(tcText);
            Debug.Log(get_pstring_size(get_text_clip_text(tc)));


            string funciooona = Marshal.PtrToStringAnsi(test_me("holaa"));

            Debug.Log(funciooona);

            //get_text_clip_text();


        }

        #endregion // !API Friendly

    }

#endif
}



