using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.InteropServices;
using System;


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

    #endregion

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
