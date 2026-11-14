#pragma once

// Compiles, links and owns an OpenGL shader program.
class ShaderProgram {
public:
    ShaderProgram(const char* vertexSource, const char* fragmentSource);
    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    void use() const;

private:
    static unsigned int compile(unsigned int type, const char* source, const char* label);

    unsigned int program_ = 0;
};
