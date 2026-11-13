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

Requires CMake 3.24+, a C++20 compiler, Ninja (or Make), and OpenGL drivers.
GLFW and GLM are fetched automatically if they are not already installed, and
the glad OpenGL loader is vendored in `third_party/`, so there are no other
system dependencies.

```bash
# Configure
cmake --preset debug

# Build
cmake --build --preset debug

# Run
./build/debug/bin/who-am-i-fighting
```

Use `release` instead of `debug` for an optimized build. The source tree is
scanned automatically, so new `.cpp` files under `src/` are picked up without
editing any CMake files.

## Project layout

```text
cmake/            Build helpers and dependency setup
header/           header files for single defining or setup for .cpp
src/              Game source (render/, etc.)
third_party/glad/ Vendored OpenGL loader
CMakeLists.txt    Top-level build configuration
CMakePresets.json Debug/Release presets
```

## Developer

**Johannes Ravnevand Paulsen**

Engineering preparatory studies at UiA.

---

<sub>This project is a work in progress.</sub>
