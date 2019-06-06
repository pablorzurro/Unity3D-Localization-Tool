using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Playables;
using UnityEngine.Timeline;

public class TextTrackDataPlayableAsset : PlayableAsset, ITimelineClipAsset
{
    public TextClipPlayableBehaviour textClipData = new TextClipPlayableBehaviour();

    // Create the runtime version of the clip, by creating a copy of the template
    public override Playable CreatePlayable(PlayableGraph graph, GameObject go)
    {
        return ScriptPlayable<TextClipPlayableBehaviour>.Create(graph, textClipData);
    }

    // Use this to tell the Timeline Editor what features this clip supports
    public ClipCaps clipCaps
    {
        get { return ClipCaps.Blending | ClipCaps.Extrapolation; }
    }
}

