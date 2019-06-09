# Localization Tool's Users Guide

## User Guide



1. Select the Localization Tool window

   

![1560097156582](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560097156582.png)

2. A window will now open. Introduce the paths to the JSON file and the destination folder of the sequences.

   - If you enable the reimport, all previous loaded sequences will be discarded and deleted.

     ![1560097092928](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560097092928.png)

     

   - Until the paths to 

     

    



## JSON Structure



```json

```

 ⚠️  **¡IMPORTANT!** ⚠️ 

- UTF-8 is used only for all clip "name" fields and text clip "text" field, file names and paths will use standard character encoding (ANSI/ASCII).

- Time format is written strictly as : **"mm:ss:sss"**

  - "mm" refers to minutes

  - "ss" refers seconds 

  - "sss" refers to milliseconds

    ***Result***: "minutes:seconds:milliseconds", or to be clear,"00:02:940"
  
- All audio clip and destination sequences folder paths must be relative to Unity's Asset folder:

  ```
  "Assets/YourFolder/archive.mp3" audio clip example
  ```

  ```
  "Assets/Sequences/
  ```

  

✍️ ​**Examples:** ✍️

- Arabic text clip value: "مرحبا!", in: "Assets/Ara/arabic_translation.json" 
- English text clip value: "Hello!", in: "Assets/Eng/english_translation.json"