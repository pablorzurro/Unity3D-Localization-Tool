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

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr get_byte_array();

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr test_communication(String str);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int free_memory(IntPtr ptr);

        #region Clips

        #region Base
        #endregion // !Base

        #region Audio Clip 

        public struct AudioClip { }

        #endregion // !Audio Clip

        #region Text Clip
        
        public struct TextClip { }

        #endregion // !Text Clip

        #endregion

        #region Tracks

        #region Base

        #endregion // !Base Track

        #region Audio Track

        public struct AudioTrack { }

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern float GetVolume(AudioTrack audioTrack);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern char GetSpatialBlendDimension(AudioTrack audioTrack);

        #endregion // !Audio Track

        #region Text Track

        public struct TextTrack { }

        #endregion // !Text Track

        #endregion // !Tracks

        #endregion // !Native

        #region API_Friendly

        //private delegate void Test(int number);
        //[MonoPInvokeCallback(typeof(Test))]
        //private static void DelegateMessageReceived(int number)
        //{
        //    Debug.Log("MessageReceived " + number);
        //}

        public static void Test()
        {
            String test = "Beast";
            Debug.Log(GetString(test_communication(test)));
        }

        public static string GetString(IntPtr charArray)
        {
            return Marshal.PtrToStringAnsi(charArray);
        }

        #endregion

    }

    #endif
}



