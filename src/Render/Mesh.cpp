#include "Mesh.hpp"

#include <glad/gl.h>

#include <stdexcept>

Mesh::Mesh(std::span<const float> vertices,
           std::span<const unsigned int> indices,
           int components)
{
    if (components <= 0 || components > 4)
    {
        throw std::invalid_argument("Mesh vertex components must be between 1 and 4");
    }

    if (vertices.empty() || vertices.size() % static_cast<std::size_t>(components) != 0)
    {
        throw std::invalid_argument(
            "Mesh vertex data must be non-empty and a multiple of the component count");
    }

    if (indices.empty())
    {
        throw std::invalid_argument("Mesh index data must not be empty");
    }

    indexCount_ = indices.size();

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(vertices.size() * sizeof(float)),
                 vertices.data(),
                 GL_STATIC_DRAW);

    // The element buffer binding is stored in the VAO, so it only has to be
    // bound while this VAO is bound. Never unbind it while the VAO is bound.
    glGenBuffers(1, &ebo_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned int)),
                 indices.data(),
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
    // Delete the VAO first so it no longer references the buffers.
    if (vao_ != 0)
    {
        glDeleteVertexArrays(1, &vao_);
    }

    if (ebo_ != 0)
    {
        glDeleteBuffers(1, &ebo_);
    }

    if (vbo_ != 0)
    {
        glDeleteBuffers(1, &vbo_);
    }
}

void Mesh::draw() const
{
    glBindVertexArray(vao_);
    glDrawElements(GL_TRIANGLES,
                   static_cast<GLsizei>(indexCount_),
                   GL_UNSIGNED_INT,
                   nullptr);
    glBindVertexArray(0);
}
