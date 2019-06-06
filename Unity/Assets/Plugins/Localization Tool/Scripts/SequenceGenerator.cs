using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.Timeline;

namespace LocalizationTool
{

#if(UNITY_EDITOR)

    public class SequenceGenerator : MonoBehaviour
    {

        public static bool CreateSequence
        (
            string name,
            string path,
            LocalizationToolWrapper.AudioTrack[] audioTracks,
            int nAudioTracks,
            LocalizationToolWrapper.TextTrack[] textTracks,
            int nTextTracks
        )
        {

            bool error = false;
            string completePath = path + name;

            TimelineAsset newTimelineAsset = new TimelineAsset();
            AssetDatabase.CreateAsset(newTimelineAsset, completePath);  // The timeline needs to exist before the tracks are added

            //string textTrackRootName = "TextTrack";


            //for()

            //newTimelineAsset.CreateTrack<TextSwitcherTrack>(newTimelineAsset.GetRootTrack(0), name);


            if(error)
            {
                AssetDatabase.DeleteAsset(completePath);
                Debug.Log("There has been errors creating the timeline asset, deleting...");
            }


            return false;
        }

        public static bool CreateAudioTrack(LocalizationToolWrapper.AudioTrack audioTrack)
        {
            return false;
        }

        public static bool CreateTextTrack(LocalizationToolWrapper.TextTrack textTrack)
        {
            return false;
        }


    }

#endif
}
