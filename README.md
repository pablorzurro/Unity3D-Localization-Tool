# Localization Tool's Users Guide

Language package directories structure example:

## JSON Structure



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

 ⚠️  **¡IMPORTANT!** ⚠️ 

- UTF-8 is used only for all clip "name" fields and text clip "text" field, file names and paths will use standard character encoding (ANSI/ASCII).

- Time format is written strictly as : **"mm:ss:sss"**

  - "mm" refers to minutes

  - "ss" refers seconds 

  - "sss" refers to milliseconds

    ***Result***: "minutes:seconds:milliseconds"

✍️ ​**Examples:** ✍️

- Arabic text clip value: "مرحبا!", in: "Assets/Ara/arabic_translation.json" 
- English text clip value: "Hello!", in: "Assets/Eng/english_translation.json"