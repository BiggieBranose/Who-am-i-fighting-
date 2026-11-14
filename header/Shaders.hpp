#pragma once

#include <cstddef>

class Shaders {
public:
    Shaders();

    unsigned int VBO = 0;
    unsigned int VAO;

    unsigned int shaderProgram;
private:
    unsigned int vertexShader;
    unsigned int fragmentShader;
};