using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.InteropServices;
using System;
using UnityEngine.Timeline;
using UnityEditor;

namespace LocalizationTool
{
    #if (UNITY_EDITOR)

    public unsafe class LocalizationToolWrapper : MonoBehaviour
    {

        #region Native

        #region Sequence

        public struct NativeSequence { }


        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern PString* get_sequence_name(NativeSequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_sequence_number_of_audio_tracks(NativeSequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_sequence_number_of_text_tracks(NativeSequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern NativeAudioTrack** get_sequence_audio_tracks(NativeSequence* sequence);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern NativeTextTrack** get_sequence_text_tracks(NativeSequence* sequence);

        #endregion

        #region File(JSON) Manager

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int load_file(string jsonFilePath, bool forceReimport = false);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern NativeSequence** load_file_and_get_sequences(string jsonFilePath, bool forceReimport = false);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern NativeSequence** get_file_sequences_by_name(string fileName);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern NativeSequence** get_file_sequences_by_path(string filePath);

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

            public struct NativeAudioClip { }
        
            // Setters

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_name(NativeAudioClip* audioClip, string name);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_start_time(NativeAudioClip* audioClip, float startTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_duration(NativeAudioClip* audioClip, float duration);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_file_path(NativeAudioClip* audioClip, string filePath);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_start_cut_time(NativeAudioClip* audioClip, string startCutTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_audio_clip_file_length(NativeAudioClip* audioClip, string fileLength);

            // Getters    

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_audio_clip_name(NativeAudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_start_time(NativeAudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_end_time(NativeAudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_duration(NativeAudioClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_audio_clip_file_path(NativeAudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_audio_clip_file_name(NativeAudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_start_cut_time(NativeAudioClip* audioClip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_clip_file_length(NativeAudioClip* audioClip);

            #endregion // !Audio Clip

            #region Text Clip

            public struct NativeTextClip { }

            // Setters

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_name(NativeTextClip* clip, string name);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_start_time(NativeTextClip* clip, float startTime);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_duration(NativeTextClip* clip, float duration);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool set_text_clip_text(NativeTextClip* clip, string text);

            // Getters

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_text_clip_name(NativeTextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_text_clip_start_time(NativeTextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_text_clip_end_time(NativeTextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_text_clip_duration(NativeTextClip* clip);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern PString* get_text_clip_text(NativeTextClip* clip);

            #endregion // !Text Clip

        #endregion // !Clips

        #region Tracks

            #region Audio Track

            public struct NativeAudioTrack { }

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern float get_audio_track_volume(NativeAudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern char get_audio_track_spatial_blend_dimension(NativeAudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern int get_audio_track_number_of_clips(NativeAudioTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern NativeAudioClip** get_audio_track_clips(NativeAudioTrack* audioTrack);

            #endregion // !Audio Track

            #region Text Track

            public struct NativeTextTrack { }

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern int get_text_track_number_of_clips(NativeTextTrack* audioTrack);

            [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
            public static extern NativeTextClip** get_text_track_clips(NativeTextTrack* audioTrack);

            #endregion // !Text Track

        #endregion // !Tracks

        #region Testing

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern float test_get_seconds_from_string(string str);

        #endregion

        #region PString

        public struct PString { }

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern int get_pstring_size(PString* pString);

        [DllImport("LocalizationTool", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr get_pstring_char_array(PString* pString);

        #endregion

        #endregion // !Native

        #region API Friendly

        static string to_string(PString* pString)
        {
            return Marshal.PtrToStringAnsi(get_pstring_char_array(pString));
        }

        public static bool ImportSequences(string pathJson, string destinationPath, bool reimport)
        {
            NativeSequence** sequences = load_file_and_get_sequences(pathJson, reimport);
            int nSequences = get_file_number_of_sequences_by_path(pathJson);

            bool good = false;

            if(sequences != null)
            {
                for (int i = 0; i < nSequences; i++)
                {
                    good = ImportSequence(sequences[i], destinationPath);
                }
            }

            return good;
        }

        private static bool ImportSequence(NativeSequence* sequence, string destinationPath)
        {
            if(sequence != null && destinationPath.Contains("Assets/"))
            {
                destinationPath = destinationPath.Substring(destinationPath.IndexOf("Assets/"));

                string sequenceName = to_string(get_sequence_name(sequence));

                Debug.Log("Sequence " + sequenceName + " info:");
               
                string completePath = destinationPath + "/" + sequenceName + ".playable";

                Debug.Log("Destination path: " + completePath);

                int nAudioTracks = get_sequence_number_of_audio_tracks(sequence);
                int nTextTracks = get_sequence_number_of_text_tracks(sequence);

                // Check if the sequence is empty
                if(nAudioTracks > 0 || nTextTracks > 0)
                {
                    TimelineAsset newTimelineAsset = new TimelineAsset();
                    AssetDatabase.CreateAsset(newTimelineAsset, completePath);  // The timeline needs to exist before the tracks are added

                    if (nAudioTracks > 0)
                    {
                        NativeAudioTrack** audioTracks = get_sequence_audio_tracks(sequence);

                        for (int i = 0; i < nAudioTracks; i++)
                        {
                            Debug.Log("Audio Track " + i + " info:");
                            CreateAudioTrack(audioTracks[i], newTimelineAsset);
                        }
                    }

                    if (nTextTracks > 0)
                    {
                        NativeTextTrack** textTracks = get_sequence_text_tracks(sequence);
                        for (int i = 0; i < nTextTracks; i++)
                        {
                            Debug.Log("Text Track " + i + " info:");
                            CreateTextTrack(textTracks[i], newTimelineAsset);
                        }
                    }

                    return true;
                }
            }

            return false;
        }

        private static bool CreateAudioTrack(NativeAudioTrack* audioTrack, TimelineAsset timelineAsset)
        {
            int nClips = get_audio_track_number_of_clips(audioTrack);

            if (audioTrack != null && nClips > 0)
            {
                
                NativeAudioClip** audioClips = get_audio_track_clips(audioTrack);

                if(audioClips != null)
                {
                    AudioTrack track = timelineAsset.CreateTrack<AudioTrack>(null, "AudioTrack");

                    for (int i = 0; i < nClips; i++)
                    {
                        // Get the attributes 
                        NativeAudioClip* iAudioClip = audioClips[i];

                        string iAudioClipName = to_string(get_audio_clip_file_name(iAudioClip));
                        string iAudioClipFilePath = to_string(get_audio_clip_file_path(iAudioClip));
                        string iAudioClipFileName = to_string(get_audio_clip_file_name(iAudioClip));

                        float iAudioClipStartTime = get_audio_clip_start_time(iAudioClip);
                        float iAudioClipDuration = get_audio_clip_duration(iAudioClip);
                        float iAudioClipEnd = get_audio_clip_end_time(iAudioClip);
                        float iAudioClipStartCutTime = get_audio_clip_start_cut_time(iAudioClip);



                        Debug.Log("Audio Clip " + iAudioClipName + " info: \n" + "  File path: " + iAudioClipFilePath + "  File name: " + iAudioClipFileName + "  Start: " + iAudioClipStartTime + "  End: " + iAudioClipEnd
                            + "  Duration: " + iAudioClipDuration + "  Start cut: " + iAudioClipStartCutTime);

                        // Create and add the clip
                        TimelineClip clip = track.CreateDefaultClip();
                        clip.start = iAudioClipStartTime;
                        clip.duration = iAudioClipDuration;
                        clip.displayName = iAudioClipName;

                        string audioPath = iAudioClipFilePath.Substring(iAudioClipFilePath.IndexOf("Assets/"));

                        AudioClip audioClip = AssetDatabase.LoadAssetAtPath<AudioClip>(audioPath);

                        var audioPlayableAsset = clip.asset as AudioPlayableAsset;
                        audioPlayableAsset.clip = audioClip;
                    }
                }
            }

            return false;
        }

        private static bool CreateTextTrack(NativeTextTrack* textTrack, TimelineAsset timelineAsset)
        {
            int nClips = get_text_track_number_of_clips(textTrack);

            if (textTrack != null && nClips > 0)
            {
                NativeTextClip** textClips = get_text_track_clips(textTrack);

                if(textClips != null)
                {
                    TextSwitcherTrack track = timelineAsset.CreateTrack<TextSwitcherTrack>(null, "TextTrack");

                    for (int i = 0; i < nClips; i++)
                    {
                        // Get the attributes from the native text clip pointer
                        NativeTextClip* iTextClip = textClips[i];

                        string iTextClipName = to_string(get_text_clip_name(iTextClip));
                        string iTextClipText = to_string(get_text_clip_text(iTextClip));

                        float iTextClipStartTime = get_text_clip_start_time(iTextClip);
                        float iTextClipDuration = get_text_clip_duration(iTextClip);
                        float iTextClipEnd = get_text_clip_end_time(iTextClip);

                        Debug.Log("Text Clip " + iTextClipName + " info: \n" + "  Text: " + iTextClipText + "  Start: " + iTextClipStartTime + "  End: " + iTextClipEnd
                                + "  Duration: " + iTextClipDuration);


                        // Create and add the text clip
                        TimelineClip clip = track.CreateClip<TextSwitcherClip>();

                        clip.start = iTextClipStartTime;
                        clip.duration = iTextClipDuration;
                        clip.displayName = iTextClipName;

                        TextSwitcherClip textSwitcherClip = clip.asset as TextSwitcherClip;
                        textSwitcherClip.template.text = iTextClipText;
                    }
                }

            }

            return false;
        }

        #region Testing

        public static void Test()
        {
            Debug.Log(test_get_seconds_from_string("00:30:040"));
        }

        public static void Test2()
        {
            NativeSequence** sequences = load_file_and_get_sequences("../DLL/Assets/Import Example/ENG/translation_example.json", true);

            Debug.Log(get_file_number_of_sequences_by_path("../DLL/Assets/Import Example/ENG/translation_example.json"));

            string sequenceName = Marshal.PtrToStringAnsi(get_pstring_char_array(get_sequence_name(sequences[0])));
            Debug.Log("Sequence name: " + sequenceName);
            Debug.Log("Number of audio tracks in sequence " + sequenceName + ": " + get_sequence_number_of_audio_tracks(sequences[0]));
            Debug.Log("Number of text tracks in sequence " + sequenceName + ": " + get_sequence_number_of_text_tracks(sequences[0]));

            NativeTextTrack** textTracks = get_sequence_text_tracks(sequences[0]);
            NativeAudioTrack** audioTracks = get_sequence_audio_tracks(sequences[0]);

            Debug.Log("Number of text clips: " + get_text_track_number_of_clips(textTracks[0]));
            Debug.Log("Number of audio clips: " + get_audio_track_number_of_clips(audioTracks[0]));

            NativeTextClip** textClips = get_text_track_clips(textTracks[0]);
            NativeAudioClip** audioClips0 = get_audio_track_clips(audioTracks[0]);

            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_text_clip_name(textClips[0]))));
            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_text_clip_text(textClips[0]))));
            Debug.Log(get_text_clip_start_time(textClips[0]));
            Debug.Log(get_text_clip_end_time(textClips[0]));
            Debug.Log(get_text_clip_duration(textClips[0]));

            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_text_clip_name(textClips[1]))));
            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_text_clip_text(textClips[1]))));
            Debug.Log(get_text_clip_start_time(textClips[1]));
            Debug.Log(get_text_clip_end_time(textClips[1]));
            Debug.Log(get_text_clip_duration(textClips[1]));

            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_audio_clip_file_name(audioClips0[0]))));
            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_audio_clip_file_path(audioClips0[0]))));
            Debug.Log(Marshal.PtrToStringAnsi(get_pstring_char_array(get_audio_clip_name(audioClips0[0]))));
            Debug.Log(get_audio_clip_start_time(audioClips0[0]));
            Debug.Log(get_audio_clip_end_time(audioClips0[0]));
            Debug.Log(get_audio_clip_duration(audioClips0[0]));
        }

        #endregion // !Testing

        #endregion // !API Friendly

    }

#endif
}



