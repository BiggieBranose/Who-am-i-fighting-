#include "Input.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

Input::Input(GLFWwindow* window)
    : window_(window)
{
}

bool Input::isKeyDown(int key) const
{
    return glfwGetKey(window_, key) == GLFW_PRESS;
}
