# nitro
It is a general purpose C++ library that can help developers create various kinds of applications in no time.

## Table of Contents
- [Coding Style](https://github.com/ii887522/nitro#coding-style)
- [Prerequisites](https://github.com/ii887522/nitro#prerequisites)
- [Update .NET Framework SDK version used by ms-build-tools to match your OS](https://github.com/ii887522/nitro#update-net-framework-sdk-version-used-by-ms-build-tools-to-match-your-os)
- [Build custom-node docker image](https://github.com/ii887522/nitro#build-custom-node-docker-image)
- [Build ms-build-tools docker image](https://github.com/ii887522/nitro#build-ms-build-tools-docker-image)
- [Install dependencies](https://github.com/ii887522/nitro#install-dependencies)
- [Set correct cpplint executable path in .vscode/settings.json](https://github.com/ii887522/nitro#set-correct-cpplint-executable-path-in-vscodesettingsjson)
- [Build project](https://github.com/ii887522/nitro#build-project)
- [Deploy project](https://github.com/ii887522/nitro#deploy-project)

## Coding Style
This project follows [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). Please familiarize yourself with the rules provided
in the coding style and make sure all the proposed code changes in your commits are conforming to the style before making a merge request. You can
also make use of cpplint which is a [Visual Studio Code](https://code.visualstudio.com/) plugin and `build` command under the
[Build project](https://github.com/ii887522/nitro#build-project) section to support you.

## Prerequisites
- Windows 10
- [Docker Desktop](https://www.docker.com/products/docker-desktop) using Windows containers
- [Visual Studio Code](https://code.visualstudio.com/)
  - C/C++
  - cpplint
  - Docker
  - EditorConfig for VS Code
  - Markdown All in One
  - Remote - WSL
  - YAML
- [Visual Studio Community 2019](https://visualstudio.microsoft.com/) and later
  - Extensions:
    - Markdown Editor
    - EditorConfig Language Service
    - Line Endings Unifier
    - Github Extension for Visual Studio
    - OpenCppCoverage Plugin
  - Workloads:
    - Desktop development with C++
  - Individual components:
    - JavaScript and TypeScript language support
    - Git for Windows
- [Python 3.9.1](https://www.python.org/downloads/) and later

## Update .NET Framework SDK version used by ms-build-tools to match your OS
1. Left click on the start button at the bottom left corner of your desktop.

  <img src="docs/start-button.png" alt="Start button" width="770" /><br /><br />

2. Left click on the settings button at the left side of the start menu.

  <img src="docs/settings.png" alt="Settings" width="770" /><br /><br />

3. Left click on the system button at the top left corner of settings window.

  <img src="docs/system.png" alt="System" width="770" /><br /><br />

4. Left click on the about button at the bottom left corner of settings window.

  <img src="docs/about.png" alt="About" width="770" /><br /><br />

5. Take note of the version shown in the settings window. You will need it to search for appropriate tags later.

  <img src="docs/version.png" alt="Version" width="770" /><br /><br />

6. Go to https://hub.docker.com/_/microsoft-dotnet-framework-sdk/ and find the Full Tag Listing section.
7. Copy a tag that contains the version you have taken note of under the Full Tag Listing section.
8. Finally, inside the repository, navigate to `ms-build-tools/Dockerfile`. Then, paste to replace the tag as highlighted and shown in the screenshot below and save it.

  <img src="docs/tag.png" alt="Tag" width="770" /><br /><br />

## Build custom-node docker image
```sh
cd custom-node
build
cd ..
```

## Build ms-build-tools docker image
```sh
cd ms-build-tools
build
cd ..
```

## Install dependencies
```sh
install
```

## Set correct cpplint executable path in `.vscode/settings.json`
1. In the explorer panel of [Visual Studio Code](https://code.visualstudio.com/), navigate to `env\Scripts\` or `env/bin/` in the project directory
and find the cpplint executable.
2. Right click on the cpplint executable and click on Copy Path to copy its absolute path.
3. In the explorer panel of [Visual Studio Code](https://code.visualstudio.com/), navigate to `.vscode/settings.json` in the project directory and
open it.
4. Finally, paste the absolute path as a string value of `"cpplint.cpplintPath"` in `settings.json` and save it.

## Build project
```sh
build
```

## Deploy project
```sh
deploy <version> <access-token>
```
