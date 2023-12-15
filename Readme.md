# SuiViewer

## About

it looks like a `CMake & imgui & glfw` Using Cmake Subproject `Template`

Using 

* [Cmake](https://cmake.org/)
* [Dear ImGui](https://github.com/ocornut/imgui)
* [Glfw](https://github.com/glfw/glfw)
* [Stb](https://github.com/nothings/stb)
* [OpenGL](https://www.opengl.org/)
* [vcpkg](https://github.com/microsoft/vcpkg)

## Environment Configuration

Plz Change `Config::Debug` in `/Viewer/src/Config.cpp` for Debug

Plz Change `CMAKE_TOOLCHAIN_FILE` in `/CMakeLists.txt`

## Project Structure

```
/
-   CmakeLists.txt
-   [SubProj]Viewer -> Viewer.exe
-   [SubProj]Core -> Core.dll
-   Extern -> Extern Project such as glfw stb
-   Build -> CMake Build File

// Subproject Viewer -> Viewer.exe
-   Viewer/src -> Source Code
-   Viewer/res -> Resource File
-   Viewer/include -> The Header File Corresponding to src
-   Viewer/CMakeLists.txt -> SubProject CMakeLists

// Subproject Core -> Core.dll(Shard) & Core.a(Static)
-   Core/src -> Source Code
-   Core/res -> Resource File
-   Core/include -> The Header File Corresponding to src
-   Core/CMakeLists.txt -> SubProject CMakeLists

// Extern Project
-   Extern/glfw -> GLFW
-   Extern/imgui -> DearImGui
-   Extern/stb -> stb
```

## Build

Using `CLion` or `CMake`

#### Build Dir:

```/Build/Debug/```

```/Build/Release/```




