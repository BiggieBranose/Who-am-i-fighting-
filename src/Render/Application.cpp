#include "Application.hpp"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace {

constexpr const char* WINDOW_TITLE = "Spooky Amdus Window";

}

Application::Application()
    : window_(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE)
    , input_(window_.handle())
{
}

void Application::run()
{
    while (!window_.shouldClose())
    {
        processInput();
        render();

        window_.swapBuffers();
        window_.pollEvents();
    }
}

void Application::processInput()
{
    if (input_.isKeyDown(GLFW_KEY_ESCAPE))
    {
        window_.requestClose();
    }
}

void Application::render()
{
    glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
