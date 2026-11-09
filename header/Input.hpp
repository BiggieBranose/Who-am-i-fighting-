#pragma once

struct GLFWwindow;

// Thin wrapper around GLFW keyboard queries.
class Input {
public:
    explicit Input(GLFWwindow* window);

    [[nodiscard]] bool isKeyDown(int key) const;

private:
    GLFWwindow* window_ = nullptr;
};
