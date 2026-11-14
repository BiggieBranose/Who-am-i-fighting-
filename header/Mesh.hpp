#pragma once

#include <cstddef>
#include <span>

// Owns a VAO/VBO/EBO for indexed triangle geometry.
// Uses attribute location 0, matching the active shader program.
class Mesh {
public:
    Mesh(std::span<const float> vertices,
         std::span<const unsigned int> indices,
         int components = 3);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw() const;

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    unsigned int ebo_ = 0;
    std::size_t indexCount_ = 0;
};
