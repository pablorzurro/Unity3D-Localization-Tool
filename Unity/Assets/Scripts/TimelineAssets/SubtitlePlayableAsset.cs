using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Playables;
using UnityEngine.Timeline;

[Serializable]
public class SubtitlePlayableAsset : PlayableAsset, ITimelineClipAsset
{
    private String myText;

    public ClipCaps clipCaps => throw new NotImplementedException();

    public override Playable CreatePlayable(PlayableGraph graph, GameObject owner)
    {
        throw new NotImplementedException();
    }

       
}
