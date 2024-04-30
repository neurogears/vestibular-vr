# videoCapture
## Features
* Acquire videos from multiple cameras
* Get timestamp of each frame
* Get input TTL status at each frame (captured at each end of exposure)
* Real time monitoring of frame rate and TTL input

## Installing Spinnaker SDK
* You need to install an old version **1.23.0.27** Spinnaker SDK, because latest versions crashes Bonsai.
* Use "Application Development" option upon installation
* Check "DirectShow" option under "Third Party Support" upon installation
* After installing, search "SpinnakerDirectShow....dll" under C:\ProgramFiles\Point Grey Research\Spinnaker
* In cmd (as admin), go to the directory where the dll file is
* Register the dll file by typing "regsvr32 SpinnakerDirectShow_v140.dll" (the dll file name may differ)

## Before you start recording
* Always check the frame rate for each camera in SpinView
* Make sure GPIO cable is connected to the camera, where Black wire is TTL and Blue wire is ground.

## Resulting files
* Video (.avi) files for each camera
* CSV file for each camera: first column is timestamp in [ns], second is TTL status
