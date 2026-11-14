#include "Mesh.hpp"

#include <glad/gl.h>

#include <stdexcept>

Mesh::Mesh(std::span<const float> vertices, int components)
{
    if (components <= 0 || vertices.empty() ||
        vertices.size() % static_cast<std::size_t>(components) != 0)
    {
        throw std::invalid_argument(
            "Mesh vertex data must be non-empty and a multiple of the component count");
    }

    vertexCount_ = vertices.size() / static_cast<std::size_t>(components);

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(vertices.size() * sizeof(float)),
                 vertices.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0,
                          components,
                          GL_FLOAT,
                          GL_FALSE,
                          components * static_cast<int>(sizeof(float)),
                          nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    if (vbo_ != 0)
    {
        glDeleteBuffers(1, &vbo_);
    }

    if (vao_ != 0)
    {
        glDeleteVertexArrays(1, &vao_);
    }
}

void Mesh::draw() const
{
    glBindVertexArray(vao_);
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertexCount_));
    glBindVertexArray(0);
}
