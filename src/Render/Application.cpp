#include "Application.hpp"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <array>

namespace {

constexpr const char* WINDOW_TITLE = "slightly less spooky Amdus Window";

#pragma region Temp shader and index data
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

constexpr std::array<float, 12> QUAD_VERTICES = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f,  // top left
};

constexpr std::array<unsigned int, 6> QUAD_INDICES = {
    0, 1, 3,  // first triangle
    1, 2, 3,  // second triangle
};

#pragma endregion

} // namespace

Application::Application()
    : window_(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE)
    , input_(window_.handle())
    , shader_(VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE)
    , mesh_(QUAD_VERTICES, QUAD_INDICES)
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
