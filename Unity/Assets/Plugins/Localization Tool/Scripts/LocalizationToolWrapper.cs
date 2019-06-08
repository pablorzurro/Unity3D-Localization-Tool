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
        public static extern string get_sequence_name(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_sequence_number_of_audio_tracks(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_sequence_number_of_text_tracks(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern AudioTrack*[] get_sequence_of_audio_tracks(Sequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern TextTrack*[] get_sequence_text_tracks(Sequence* sequence);

        #endregion

        #region File(JSON) Loader

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern Sequence*[] load_file(string jsonFilePath, bool forceReimport);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern Sequence*[] get_file_sequences_by_name(string fileName);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern Sequence*[] get_file_sequences_by_path(string filePath);

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

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern string get_name(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_start_time(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_end_time(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_duration(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool get_file_path(AudioClip* audioClip, string filePath);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_start_cut_time(AudioClip* audioClip, string startCutTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_file_length(AudioClip* audioClip, string fileLength);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern string get_file_path(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern string get_file_name(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_start_cut_time(AudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_file_length(AudioClip* audioClip);

            #endregion // !Audio Clip

            #region Text Clip

            public struct TextClip { }

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern string get_name(TextClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_start_time(TextClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_end_time(TextClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_duration(TextClip* audioClip);

            #endregion // !Text Clip

        #endregion // !Clips

        #region Tracks

            #region Audio Track

            public struct AudioTrack { }

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_volume(AudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern char* get_spatial_blend_dimension(AudioTrack* audioTrack);

            #endregion // !Audio Track

            #region Text Track

            public struct TextTrack { }

        #endregion // !Text Track

        #endregion // !Tracks

        #region Testing

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern float test_get_seconds_from_string(string str);

        #endregion

        #endregion // !Native

        #region API Friendly

        public static void Test()
        {
            Debug.Log(test_get_seconds_from_string("00:30:040"));
        }

        #endregion // !API Friendly

    }

#endif
}



