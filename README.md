# CATnet
<p align="center">
  <a href="github.com/ZincSoft/CATNET" target="blank"><img src="assets/logo.png" alt="CATNET Logo" /></a>
    <img src="https://img.shields.io/github/license/ZincSoft/CATNET?:ZincSoft:/CATNET?label=License&style=flat" alt="License">
    <img src="https://img.shields.io/github/stars/ZincSoft/CATNET?:ZincSoft:/CATNET?label=Stars&tyle=flat" alt="Stars">
    <img src="https://img.shields.io/github/watchers/ZincSoft/CATNET?style=social&label=Watchers&style=flat" alt="Watchers">
    <img src="https://img.shields.io/github/forks/ZincSoft/CATNET?style=social&label=Forks&style=flat" alt = "Forks">
    <img src="https://img.shields.io/codefactor/grade/github/ZincSoft/CATNET?label=Code%20Factor%20Grade" alt="Code Factor Grade">
    <img src="https://img.shields.io/tokei/lines/github/ZincSoft/CATNET?label=Total Lines" alt="Total Lines">
    <img src="https://img.shields.io/badge/Linux-Supported-green" alt="Linux Supported!">
    <img src="https://img.shields.io/badge/MacOS-Supported-green" alt="MacOS Supported!">
	<img src="https://img.shields.io/badge/Windows-Nope.%20Use%20Linux-red" alt="Fuck Windows!">
    <img src="https://img.shields.io/github/last-commit/ZincSoft/Catnet.svg" alt="Last Commit">
    <img src="https://img.shields.io/aur/last-modified/Catnet.svg" alt="AUR Last Modified">
</p>
CATnet is a more desentralized web for a more modern age.

## User use
### Installation
CATnet uses the Meson build system, because quite simply, it is one of the best build systems for C++. But you're not here to find out why Meson is so awesome, you just want to build CATnet. To build CATnet, you must have Meson and Ninja installed on your system.  
If on Linux, just install your distros meson package, and ninja will be installed along side it. Same on Mac OS. On Windows, winget doesn't have a package for it. Please look up installation directions for Meson and Ninja on Windows. Or throw your Windows cursed hard drive in a bin. Either works.  
As of now, you do not need any libraries preinstalled because the C/C++ standard libraries (duh). However, since Google ProtoBuf takes a while to build, you can download a prebuilt binary from your package manager to speed up the build (the build scripts try to automatically detect it). The following is how to build CATnet.  
![Install GIF](assets/install.gif)
or
```bash
# Clone the repo if you haven't already
git clone https://github.com/ZincSoft/CATNET.git
cd CATNET

# Configure the project
meson build

# Build the project
cd build
ninja
```

### Use
Please run `catnetd --help` to get a help message. To launch the participant (run a whisker), use `catnetd participant`. In opposision, to run the registrar, use `catnetd registrar`.

## Software Development
### Usefull flags
During development of CATnet, you may wish these flags:
* `-l0`, enables all levels of logging. Please note that *trace* and *info* logging are disabled in release builds.

### Building
The way to build CATnet is basically the same as how a regular user would, but instead of running `meson build` you run `meson build --buildtype=debug`

### Logging
Please see `src/logging/include/log.hpp` to see the macros availble. Please choose the right one.

### Code Guidelines
In order to make CATnet easier to maintain and understand, we follow the [CppCoreGuidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). If you need to find out how to style a specific C++ feature, please use your browsers built in search function, or clone it onto your system and `find . | grep x`.
The first time you use a feature (even if it is trivial, such as function declaration), please look up the prefered way to use it in the guidelines.

### Git Workflow
Pretend the other people working on this code base are insane, have a shotgun, and know where you live. As such, please follow `WORKFLOW.MD`.

### Specification
[Here](https://docs.google.com/document/d/1t3FXJTDr-h4J9iPvzBLDdCKGJAukKruhrJjNaMWRgq0/edit?ts=5fc41d5f#heading=h.3bqhl2hpdgyy) is a link to our specifications document.

### Contributing
[![GitHub last commit](https://img.shields.io/github/last-commit/google/skia.svg?style=flat)]()
[![GitHub commit activity the past week, 4 weeks](https://img.shields.io/github/commit-activity/y/eslint/eslint.svg?style=flat)]()
[![GitHub commits since](https://img.shields.io/github/commits-since/tterb/playmusic/v1.2.0.svg)]()
[![Issues](https://img.shields.io/github/issues-raw/tterb/PlayMusic.svg?maxAge=25000)](https://github.com/tterb/Hyde/issues)  
[![Pull Requests](https://img.shields.io/github/issues-pr/cdnjs/cdnjs.svg?style=flat)]()
[![PR's Welcome :D](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat)](http://makeapullrequest.com)  
Thank you for even considering contributing to this project. At this time, we will *NOT* be merging pull requests that are linked to issues that themselves are linked to a certain project. We are, however, eternally greatfull for bug fixes.

## Support
### Discord
[![Discord Chat](https://img.shields.io/discord/YAqvVTrx.svg)](https://discord.gg/YAqvVTrx)  
We have an offical discord server! Please note that it is not ready, but you can still use it nonetheless.
