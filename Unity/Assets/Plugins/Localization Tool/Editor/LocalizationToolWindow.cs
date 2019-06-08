using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

namespace LocalizationTool
{

    public class LocalizationToolWindow : EditorWindow
    {

        [MenuItem("Window/Localization Tool")]
        public static void ShowWindow()
        {
            GetWindow(typeof(LocalizationToolWindow));
        }

        void OnGUI()
        {
            GUILayout.Label("Color the selected objects!", EditorStyles.boldLabel);

            if (GUILayout.Button("TEST!"))
            {
                TestString();
            }
        }

        void TestString()
        {
            LocalizationToolWrapper.Test2();
        }
    }

}
