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
            Debug.Log(test_get_seconds_from_string("2:59:940"));
        }

        #endregion // !API Friendly

    }

#endif
}



