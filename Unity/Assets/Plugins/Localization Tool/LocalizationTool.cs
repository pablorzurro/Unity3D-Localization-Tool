using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.InteropServices;
using System;


#if (UNITY_EDITOR)

public unsafe class LocalizationTool : MonoBehaviour
{
    #region Native

    [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
    public static extern int add(int a, int b);

    [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr get_byte_array();

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
        Debug.Log(GetString(get_byte_array()));
    }

    public static string GetString(IntPtr charArray, bool liberateMemory = false)
    {
        string toReturn = Marshal.PtrToStringAnsi(charArray);

        if (liberateMemory)
        {
            free_memory(charArray);
        }

        return toReturn;
    }

    #endregion


}

#endif
