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
    glUseProgram(shaders_::shaderProgram);
    glBindVertexArray(shaders_::VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void Application::cleanup()
{
    
}
