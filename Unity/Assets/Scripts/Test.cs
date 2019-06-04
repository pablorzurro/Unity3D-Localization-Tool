using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
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
        c = LocalizationTool.add(c, b);
        c = LocalizationTool.add(c, a);

        Debug.Log(c);

    }

}
