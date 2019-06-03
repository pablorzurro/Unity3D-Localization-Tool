using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.InteropServices;

public class Test : MonoBehaviour
{

    [DllImport("LocalizationManager", CallingConvention = CallingConvention.Cdecl)]
    public static extern int add(int a, int b);

    int a = 1;
    int b = 2;
    int c = 3;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        c = add(c, b);
        c = add(c, a);

        Debug.Log(c);
    }

}
