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
* [Spinnaker SDK 1.29.0.5](https://www.flir.co.uk/support/products/spinnaker-sdk/#Downloads) (device drivers for FLIR cameras, sign in required, look in the archived stable versions for 1.29.0.5)

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