using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using LocalizationTool;
using UnityEngine.Timeline;

namespace LocalizationTool
{

    public class LocalizationToolWindow : EditorWindow
    {

        string jsonPath = "";
        string destinationPath = "";
        string displayJSONPath = "";
        string displayDestinationPath = "";

        bool forceReimport;
        bool canImport;

        [MenuItem("Window/Localization Tool")]
        public static void ShowWindow()
        {
            GetWindow(typeof(LocalizationToolWindow));
        }

        void OnGUI()
        {
            GUILayout.Label("JSON Import", EditorStyles.boldLabel);

            EditorGUILayout.BeginHorizontal();
            {
                jsonPath = EditorGUILayout.DelayedTextField("JSON path: ", jsonPath, GUILayout.Width(370));

                if (GUILayout.Button("...", GUILayout.Width(32)))
                {
                    jsonPath = EditorUtility.OpenFilePanel("Load JSON", "", "json");
                }

            } EditorGUILayout.EndHorizontal();

            if(jsonPath.EndsWith(".json"))
            {
                displayJSONPath = jsonPath;
            }
            else
            {
                displayJSONPath = "JSON file not selected";
            }

            GUILayout.Label("JSON file selected: " + displayJSONPath);

            EditorGUI.DrawRect(EditorGUILayout.GetControlRect(false, 1), new Color(0.5f, 0.5f, 0.5f, 1));


            // SEQUENCES IMPORT 

            GUILayout.Label("Sequences Import", EditorStyles.boldLabel);

            EditorGUILayout.BeginHorizontal();
            {
                destinationPath = EditorGUILayout.DelayedTextField("Destination folder: ", destinationPath, GUILayout.Width(370));

                if (GUILayout.Button("...", GUILayout.Width(32)))
                {
                    destinationPath = EditorUtility.OpenFolderPanel("Select Destination Folder", "Assets/", "");
                }

            }
            EditorGUILayout.EndHorizontal();

            if (destinationPath.Contains("Assets/"))
            {
                displayDestinationPath = destinationPath;
            }
            else
            {
                displayDestinationPath = "Destination folder not selected";
            }

            GUILayout.Label("Destination folder selected: " + displayDestinationPath);


            forceReimport = EditorGUILayout.Toggle("Enable reimport", forceReimport);

            if(jsonPath == displayJSONPath && destinationPath == displayDestinationPath)
            {
                if (GUILayout.Button("Import sequences", GUILayout.Width(128), GUILayout.Height(64)))
                {
                    LocalizationToolWrapper.ImportSequences(jsonPath, displayDestinationPath, forceReimport);
                }
            }
        }
    }

}
