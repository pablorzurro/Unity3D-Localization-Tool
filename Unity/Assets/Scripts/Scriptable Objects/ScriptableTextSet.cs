using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "NewScriptableTextSet", menuName = "ScriptableTextSet", order = 52)]
public class ScriptableTextSet : ScriptableObject
{
    public List<Subtitle> texts;
}
