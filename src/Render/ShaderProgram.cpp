#include "ShaderProgram.hpp"

#include <glad/gl.h>

#include <stdexcept>
#include <string>
#include <vector>

ShaderProgram::ShaderProgram(const char* vertexSource, const char* fragmentSource)
{
    unsigned int vertexShader = 0;
    unsigned int fragmentShader = 0;

    try
    {
        vertexShader = compile(GL_VERTEX_SHADER, vertexSource, "vertex");
        fragmentShader = compile(GL_FRAGMENT_SHADER, fragmentSource, "fragment");
    }
    catch (...)
    {
        if (vertexShader != 0)
        {
            glDeleteShader(vertexShader);
        }
        if (fragmentShader != 0)
        {
            glDeleteShader(fragmentShader);
        }
        throw;
    }

    program_ = glCreateProgram();
    glAttachShader(program_, vertexShader);
    glAttachShader(program_, fragmentShader);
    glLinkProgram(program_);

    int linked = 0;
    glGetProgramiv(program_, GL_LINK_STATUS, &linked);
    if (linked == GL_FALSE)
    {
        int length = 0;
        glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> log(static_cast<std::size_t>(length > 0 ? length : 1));
        glGetProgramInfoLog(program_, length, nullptr, log.data());

        glDeleteProgram(program_);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        program_ = 0;

        throw std::runtime_error(std::string("Failed to link shader program:\n") + log.data());
    }

    glDetachShader(program_, vertexShader);
    glDetachShader(program_, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ShaderProgram::~ShaderProgram()
{
    if (program_ != 0)
    {
        glDeleteProgram(program_);
    }
}

void ShaderProgram::use() const
{
    glUseProgram(program_);
}

unsigned int ShaderProgram::compile(unsigned int type, const char* source, const char* label)
{
    const unsigned int shader = glCreateShader(type);

    const char* const sources[] = {source};
    glShaderSource(shader, 1, sources, nullptr);
    glCompileShader(shader);

    int compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (compiled == GL_FALSE)
    {
        int length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> log(static_cast<std::size_t>(length > 0 ? length : 1));
        glGetShaderInfoLog(shader, length, nullptr, log.data());

        glDeleteShader(shader);
        throw std::runtime_error(std::string("Failed to compile ") + label + " shader:\n" + log.data());
    }

    return shader;
}
