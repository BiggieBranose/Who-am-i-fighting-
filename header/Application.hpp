#pragma once

#include "Input.hpp"
#include "Mesh.hpp"
#include "ShaderProgram.hpp"
#include "Window.hpp"

// Owns the window, input, graphics resources and the main loop.
class Application {
public:
    Application();
    void run();

private:
    void processInput();
    void render();

    // Declaration order matters: the window (and its OpenGL context) is
    // created first and destroyed last, after the GL resources are released.
    Window window_;
    Input input_;
    ShaderProgram shader_;
    Mesh mesh_;
};
