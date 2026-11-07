# pragma region includes
#include <glad/gl.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#pragma endregion includes

# pragma region predef
void frambuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
#pragma endregion predef

#pragma region settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
#pragma endregion settings

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Spooky Amdus Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window \n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frambuffer_size_callback);

    // Loading GLAD function pointers
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD \n";
        return -1;
    }

    while(!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        // Rendering
        glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#pragma region rest
// Callback for resizing the window
void frambuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Processing input
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
#pragma endregion rest
