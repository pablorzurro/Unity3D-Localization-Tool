using UnityEngine;
using UnityEngine.Playables;
using UnityEngine.Timeline;
using UnityEngine.UI;

[TrackColor(0.0f, 0.3f, 0.9f)]
[TrackClipType(typeof(TextTrackDataPlayableAsset))]
[TrackBindingType(typeof(Text))]
public class TextTrackAsset : TrackAsset
{
    public override Playable CreateTrackMixer(PlayableGraph graph, GameObject go, int inputCount)
    {
        return base.CreateTrackMixer(graph, go, inputCount);
    }
}