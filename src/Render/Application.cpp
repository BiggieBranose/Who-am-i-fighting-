#include "Application.hpp"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <array>

namespace {

constexpr const char* WINDOW_TITLE = "Spooky Amdus Window";

constexpr const char* VERTEX_SHADER_SOURCE = R"(#version 330 core

layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";

constexpr const char* FRAGMENT_SHADER_SOURCE = R"(#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
)";

constexpr std::array<float, 9> TRIANGLE_VERTICES = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
};

}

Application::Application()
    : window_(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE)
    , input_(window_.handle())
    , shader_(VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE)
    , mesh_(TRIANGLE_VERTICES)
{
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
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
    glClear(GL_COLOR_BUFFER_BIT);

    shader_.use();
    mesh_.draw();
}
