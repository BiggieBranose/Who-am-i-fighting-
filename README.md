# Who Am I Fighting?

<p align="center">
  A 3D turn-based tactical strategy game built with C++ and OpenGL.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/OpenGL-5586A4?style=flat&logo=opengl&logoColor=white" alt="OpenGL" />
  <img src="https://img.shields.io/badge/GLFW-000000?style=flat" alt="GLFW" />
  <img src="https://img.shields.io/badge/Status-Early%20Development-orange?style=flat" alt="Early Development" />
</p>

---

## About

A personal project where I'm exploring 3D graphics, game development, and AI.

The goal is to create a turn-based strategy game with an AI opponent, with the possibility of using machine learning to train it in the future.

i originally thought of doing this in python which i have less experience with due to it being better for Machine learning projects, but i simply like c++ more.

## Built With

- **C++** — Game logic
- **OpenGL** — 3D rendering
- **GLFW** — Window management and input
- **GLM** — Math
- **glad** — OpenGL loader (vendored)

## Building

### Requirements

- CMake 3.24+
- A C++20 compiler (MSVC on Windows, GCC or Clang on Linux)
- Git (GLFW and GLM are fetched at configure time when not installed)
- OpenGL drivers

The glad OpenGL loader is vendored in `third_party/glad`, so no loader package
is needed. The presets do not force a generator: CMake uses the native default
for each platform (Visual Studio on Windows, Make or Ninja on Linux). Both
platforms place the executable in `build/<preset>/bin`.

### Windows

Install Visual Studio (2022 or newer) with the "Desktop development with C++"
workload. Then, from a terminal in the project root:

```powershell
cmake --preset debug
cmake --build --preset debug
.\build\debug\bin\who-am-i-fighting.exe
```

### Linux (Debian/Ubuntu)

GLFW is built from source, so it needs the X11 development packages:

```bash
sudo apt install build-essential cmake git \
    libgl1-mesa-dev libx11-dev libxrandr-dev \
    libxinerama-dev libxcursor-dev libxi-dev
```

Add `libwayland-dev libxkbcommon-dev wayland-protocols` if you build GLFW with
Wayland support. Then:

```bash
cmake --preset debug
cmake --build --preset debug
./build/debug/bin/who-am-i-fighting
```

Use `release` instead of `debug` for an optimized build. The source tree is
scanned automatically, so new `.cpp` files under `src/` are picked up without
editing any CMake files.

### VS Code

Install the CMake Tools and C/C++ extensions. IntelliSense is provided by CMake
Tools, so it works with both the Visual Studio and Make/Ninja generators. The
`CMake: build (debug)` and `CMake: run (debug)` tasks and the `Debug (CMake)`
launch configuration work on Windows, Linux and macOS.

## Project layout

```text
header/           Public headers (Application, Window, Input, ShaderProgram, Mesh)
src/              Game source (Render/)
shaders/          GLSL shaders
cmake/            Build helpers and dependency setup
third_party/glad/ Vendored OpenGL loader
CMakeLists.txt    Top-level build configuration
CMakePresets.json Debug/Release presets
```

## Developer

**Johannes Ravnevand Paulsen**

Engineering preparatory studies at UiA.

---

<sub>This project is a work in progress.</sub>
