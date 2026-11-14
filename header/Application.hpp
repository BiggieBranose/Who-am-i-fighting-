#pragma once

#include "Input.hpp"
#include "Window.hpp"
#include "Shaders.hpp"

// Owns the window, input and the main loop.
class Application {
public:
    Application();
    void run();

private:
    void processInput();
    void render();
    void cleanup();

    Window window_;
    Input input_;
    Shaders shaders_;
};
