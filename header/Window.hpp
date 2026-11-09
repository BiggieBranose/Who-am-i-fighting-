#pragma once

struct GLFWwindow;

// Default window size.
constexpr int SCR_WIDTH = 800;
constexpr int SCR_HEIGHT = 600;

// Owns the GLFW window and the OpenGL context.
class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    [[nodiscard]] bool shouldClose() const;
    void requestClose();
    void pollEvents() const;
    void swapBuffers() const;

    [[nodiscard]] GLFWwindow* handle() const { return window_; }

private:
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

    GLFWwindow* window_ = nullptr;
};
