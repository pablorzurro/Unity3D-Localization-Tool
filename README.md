# Localization Tool's Users Guide

Language package directories structure example:



------

 :warning:  **¡IMPORTANT!** :warning: 

UTF-8 is used only for text clips value, file names and paths will use standard character encoding (ANSI/ASCII).

:writing_hand: ​**Examples:** :writing_hand:

- Arabic text clip value: "الله", in: "Assets/Ara/arabic_translation.json" 
- English text clip value: "Hello!", in: "Assets/Eng/english_translation.json"





## JSON Structure

Text 



```
{

​    "Sequences":
​    [
​        {
​            "Name": "Sequence001",
​            "Audio clips":
​            [
​                {
​                    "Name": "birds_sound.mp3",
​                    "Location": "Assets/Global/Audio/MP3/birds_sound.mp3",
​                    "Start": "00:00:00:000",
					 "End":  "00:00:17:940",
​                    "Clip Start": "00:01:00:000",
​                    "Clip End": "-"
​                }
​            ],
​           "Subtitle clips": 
​            [
​                {
​                    "Name": "ST_001",
​                    "Start": "00:00:00:000",
​                    "End":  "00:00:17:940",
​                    "Text": "[Birds singing]"
​                }
​            ]
​        }
​    ]
}
```

