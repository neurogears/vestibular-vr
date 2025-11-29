# vestibular-vr
Closed-loop VR setup for Rancz Lab

[Design Document](https://github.com/neurogears/vestibular-vr/blob/main/Design%20Documents/Vestibular%20VR%20Design%20Document.md)

### Acquisition Prerequisites

The following need to be installed on a fresh system in order to bootstrap the Bonsai environment correctly:

* Windows 10 or greater
* [Visual Studio Code](https://code.visualstudio.com/) (recommended for editing code scripts and git commits)
* [.NET 8.0 SDK](https://dotnet.microsoft.com/en-us/download/dotnet/8.0)
* [.NET Framework 4.7.2 Developer Pack](https://dotnet.microsoft.com/download/dotnet-framework/thank-you/net472-developer-pack-offline-installer) (required for intellisense when editing code scripts)
* [Git for Windows](https://gitforwindows.org/) (recommended for cloning and manipulating this repository)
* [Visual C++ Redistributable for Visual Studio 2012](https://www.microsoft.com/en-us/download/details.aspx?id=30679) (native dependency for OpenCV)
* [FTDI CDM Driver 2.12.28](https://www.ftdichip.com/Drivers/CDM/CDM21228_Setup.zip) (serial port drivers for HARP devices)
* [Spinnaker SDK 1.29.0.5](https://www.teledynevisionsolutions.com/support/support-center/software-firmware-downloads/iis/spinnaker-sdk-download/spinnaker-sdk--download-files) (device drivers for FLIR cameras, sign in required, look in the archived stable versions for 1.29.0.5)

### Setting up the Bonsai environment

To set up a Bonsai environment for running vestibular-vr, use the terminal to clone the repo into a local folder:

``` 
git clone https://github.com/neurogears/vestibular-vr.git
```

Now navigate into vestibular-vr/bonsai folder and run the `Setup.ps1` script (on Windows right-click > Run with powershell). Once all dependencies have been restored Bonsai can be launched in a local environment from the `.exe` in this folder.

### Session settings

Experiment parameters are based on a json schema (`schema.json` in the repo). Implementations of this schema are defined in `.yml` files provided by the user that are then loaded in the main Bonsai workflow to set up experiment parameters.

#### Working with schemas in Visual Studio Code
To create and edit schema implementations with full autcomplete and hinting, Visual Studio Code requires some extensions to be added:
* json (ZainChen.json)
* JSON Schema Validator (tberman.json-schema-validator)
* YAML (redhat.vscode-yaml)

#### Creating an experiment parameter file
To create an experiment parameter file based on the `schema`, create a new `.yml` file and add a reference to the `schema` at the top of the file

```
%YAML 1.1
---
# yaml-language-server: $schema=schema.json
```

The `schema` has two main groups of properties that define global experiment parameters, and block-specific parameters respectively, e.g.:

```
metadata:
  animalId: plimbo
  rootPath: D:/TrialLogicTestData/
  runGain: 0.0005

blocks: [
  &blockA
  {
    stimulus: {type: "grating"},
    totalRuntime: 20,
    runThreshold: 100,
    decayTimestep: 0.1,
    runThresholdDecay: -1,
    haltProbability: 0.5,
    haltProtocol: {
      minumumDelay: 0.1,
      randomDelay: 1.5,
      haltTime: 2,
      haltGain: 0
    }
  },
  &blockB
  {
    stimulus: {type: "cloud"},
    totalRuntime: 140,
    runThreshold: 200,
    decayTimestep: 0.1,
    runThresholdDecay: -1,
    haltProbability: 0.7,
    haltProtocol: {
      minumumDelay: 0.1,
      randomDelay: 0.5,
      haltTime: 0.5,
      haltGain: 0
    }
  },
  {<<: *blockA},
  {<<: *blockB}
]
```

The description of each parameter's effect on the Bonsai workflow, along with its type and default values are defined within `schema.json` itself. Note that where a parameter is not specifically set in the `.yml` the value will revert the default.

### Running an experiment
To run an experiment, run the Bonsai application from the local environment and open Main.bonsai. Use the property grid to select the desired experiment parameter `.yml` file.

### Gain settings
The `schema` has a number of gain settings that can be used to flexibly the define the relationship between real-time data sources (ball movement, encoder reading, file playback) and closed-loop outputs like visual field movement or motor movement. These gains are applied hierarchically with some affecting all calculations, and some defined per-block or per-source:

- `runGain` - global gain applied to all calculations
  - `blockGainModifier` - additional gain specific to a block
    - Visual: gains that contribute to visual field motion
      - `flowXToVisualGain` - gain applied to optical sensor X reading
      - `flowYToVisualGain` - gain applied to optical sensor Y reading
      - `rotaryToVisualGain` - gain applied to the rotary encoder reading
      - `playbackToVisualGain` - gain applied to the file playback data source
    - Motor: gains that contribute to motor motion
      - `flowXToMotorGain` - gain applied to optical sensor X reading
      - `flowYToMotorGain` - gain applied to optical sensor Y reading
      - `playbackToMotorGain` - gain applied to the file playback data source
  - `haltGain` - set as part of a `haltProtocol`. Applies a gain to all sources during a halt, block-specific.

We use the term 'procession' to describe the movement delta of the visual field or motor in response to an update from a data source (optical flow, playback etc.) on a given trial. Let `h` be a variable that describes whether a halt is currently happening (1 = halt happening, 0 = halt not happening), visual and motor processions are defined as:

```
visualProcession = (runGain * blockGainModifier) * (flowXToVisualGain*flowX + flowYToVisualGain*flowY + rotaryToVisualGain*encoder + playbackToVisualGain*playback) * (haltGain*h)
```
```
motorProcession = (runGain * blockGainModifier) * (flowXToMotorGain*flowX + flowYToMotorGain*flowY + playbackToVisualGain*playback) * (haltGain*h)
```

`motorProcession` is converted by the function `ToPulseInterval` to an immediate pulse interval command which is written to the motor. The conversion between this command and the speed of the motor is dependent on the hardware settings for pulse interval --> motor motion on the motor controller.
The relationship of `visualProcession` to visual field movement is dependent on the current visual stimulus being presented. For example for a gratings stimulus, the value represents the absolute phase angle of the gratings being shown. For a motion clouds stimulus, it represents the (wrapped) index of the motion cloud frame being shown.

Gains can be set to modify the contribution of a data source to procession, for example to specify a block where visual motion is only dependent on the X value of the flow sensor we can set:

```
# metadata
runGain: 0.0008 # represents final conversion from procession to visual angle
# block settings
blockGainModifier: 1 # block modifier does not scale input data sources
flowXToVisualGain: 1 # we want the X flow value to contribute
flowYToVisualGain: 0 # we don't want the Y flow value to contribute
rotaryToVisualGain: 0 # encoder reading should not contribute
playbackToVisualGain: 0 # playback source should not contribute
```

### Optical flow sensor smoothing

An average smoothing function is applied to the optical sensor reading. A `schema` parameter `flowSmoothing` is applied per-block which specifies a count of how many samples to smooth over, i.e. the length of the buffer to take an average, smoothed value from.

### Data logging
Data is logged according to the [Aeon.Acquisition](https://github.com/SainsburyWellcomeCentre/aeon_acquisition) format. Generally, data is grouped according to a folder named with a timestamp representing the start time of an experiment. Within this folder, data is organised by **device**, where a device may be a camera, Harp board, ONIX acquisition etc. For longer experiments, data is 'chunked' by hour such that the full raw data is split across multiple files to ensure no single file grows unmanageably large.

Within each device, data may be stored in a different format according to the device's data output. In general however, there will be a log of the raw data (e.g. camera frames, sensor readings) and a corresponding source of timestamps to allow for relating the data to the Harp clock. For a camera, this will take the form of a video file with the acquired camera frames, as well as a corresponding .csv file with paired Harp timestamps and camera frame indices. For a Harp device, this will take the form of a flat binary file organised by individual register, with the output of that register paired with a Harp timestamp.

As Harp files are saved as flat binary, it is recommended to use the device schema for that Harp device to parse the individual values and read the correct data type.

### Python environment

The following need to be installed once on a new system in order to analyze data:

 * [Visual Studio Code](https://code.visualstudio.com/) (recommended for editing code scripts and git commits)
 * A Conda distribution such as [Miniconda](https://docs.anaconda.com/free/miniconda/index.html)
 * [Python Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-python.python)
   * This extension needs to be made aware of the Conda installation. To do so, navigate to the extension settings. Under the section **Python: Conda Path**, enter the full path to the conda.bat executable. ([more info](https://stackoverflow.com/a/77615160/3312269).)
 * [Jupyter Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-toolsai.jupyter)

#### Create local Environment
1. Open the vestibular-vr folder in VS Code
2. `Ctrl+Shift+P` in VS Code > Python: Create Environment
   * Select Conda
   * Select Python 3.11 kernel
3. Ensure pip is upgraded:
 ```
 pip install --upgrade pip
 ```
4. From the terminal run `pip install -r requirements.txt`
5. Clone aeon_mecha into a separate directory 
 ```
 git clone https://github.com/SainsburyWellcomeCentre/aeon_mecha.git 
 ```
6. From the VS Code terminal, `cd` into the aeon_mecha directory and run:
 ```
 python -m pip install -e .
 ```

 ### SLEAP
 Follow the standard instructions for [installing SLEAP](https://sleap.ai/installation.html), [creating a project](https://sleap.ai/tutorials/new-project.html) and [labeling](https://sleap.ai/tutorials/initial-labeling.html). Ensure that you use training videos of the same pixel width and height that you will use for inference later. During training, ensure you select `single animal` as the training pipeline type, and that the image is converted to grayscale.

 After completing training, activate the sleap conda environment (if not already activated) and run:

 ```
sleap-export -m /model/folder/path
 ```

 to export the trained model to a format that can be used by Bonsai.
