# Localization Tool's Users Guide

## Installation 

1. This Package uses an unmanaged C++ DLL and in order to use the plugin, it is needed to enable unsafe code in Unity. 

   ```
   Edit -> Project Settings -> Player -> Allow unsafe code 
   ```

   ![1560100180402](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560100180402.png)



2. The root folder includes a Unity Package. Drag and drop the file to the Unity project.

![1560099825564](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560099825564.png)



![1560099878698](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560099878698.png)

## Use Instructions

1. Select the Localization Tool window

   

![1560097156582](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560097156582.png)



2. A window will now open.

3.  Introduce the paths to the JSON file and the destination folder of the sequences.

   - If you enable the reimport, all previously loaded sequences will be discarded and deleted.

     

     ![1560097092928](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560097092928.png)

     

   - Until the paths are and correct, loading and saving of sequences won't be available.

4. A button will now display and ready to be pressed.

5. When the import sequences button is pressed, the file will be ready at the selected path. 

   

   ![1560103136974](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560103136974.png)

   

6. To open the asset is required to have a Timeline window opened. It can be opened by: 

   ![1560103210807](C:\Users\Pablo\AppData\Roaming\Typora\typora-user-images\1560103210807.png)



```
Window -> Sequencing -> Timeline
```



## JSON Structure

The structure of the JSON files to read have to be precise. Follow the next rules to avoid unwanted errors and crashes. It is recommended to read the example assets of the project.



### Sequence Structure

```json

        {
            "name": "Tyrion_Trial-ENG",
            "clips":
            {
                "audio":
                [
           			// Audio Clips {}, {}, ...
                ],
                "text": 
                [
                   // Text Clips {}, {}, ...
                ]
            },
        }

```

###  

### Audio Clip Structure

```json
{
    "name": "A name",
    "path": "Assets/my_mp3.wav",
    "start": "00:00:000",
    "duration": "00:56:000",
    "start_cut": "00:00:000" // 00(minutes) : 00(seconds) : 000 (milliseconds)
}
```

Where:

- **"start"**: is the time to start the clip 

- **"duration"**: is the time to finish the clip playback since the start

- **"start_cut"**: will cut since the clip start to this time value. Can't be lower than start

  

### Text Clip Structure

```
{
    "name": "A name",
    "start": "00:00:000",
    "duration": "00:56:000",
    "text": "This is a text"
}
```



### Overview

```
{
	// [] is an array of items
	"sequences":
	[
		{
			"name": "Sequence001"
            "clips":
            [
            	"audio":
            	[
            		{
                        "name": "A name",
                        "path": "Assets/my_mp3.wav",
                        "start": "00:00:000",
                        "duration": "00:56:000",
                        "start_cut": "00:00:000" 
                    }
            	],
            	"text":
            	[
            		{
                        "name": "A name",
                        "path": "Assets/my_mp3.wav",
                        "start": "00:00:000",
                        "duration": "00:56:000",
                        "start_cut": "00:00:000" 
                    }
            	]
            ]
		}
	]
}
```



------

⚠️  **IMPORTANT NOTES** ⚠️ 

- The texts have a UTF-8 encoding and are available any Unicode character.

- Time format is written strictly as : **"mm:ss:sss"**

  - "mm" refers to minutes

  - "ss" refers seconds 

  - "sss" refers to milliseconds

    ***Result***: "minutes:seconds:milliseconds", or to be clear,"00:02:940"
  
- All audio clip and destination sequences folder paths should be relative to Unity's Asset folder, but the JSON can be in any path available:

  ```
  "Assets/YourFolder/archive.mp3" audio clip example
  ```

  ```
  "Assets/Sequences/" destination folder example   
  ```

  ```
  "C:/Downloads/my_json.json" json file example
  ```

- This project uses Unity Engine's default TextSwitcher ScriptableAsset and is not possible to have two or more active text tracks at the same time. It will require to create other behaviors to manage text settings. 