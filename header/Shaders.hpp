#pragma once

#include <cstddef>

class Shaders {
public:
    Shaders();

private:
    unsigned int VBO = 0;
    unsigned int vertexShader;
    unsigned int fragmentShader;

    unsigned int shaderProgram;
};