#pragma once

#include <glm/glm.hpp>

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Rect {
    public:
        Rect();
        Rect(const glm::vec2& pos, const glm::vec2& size);

        void draw(const ShaderProgram& shaderProgram);
    private:
        glm::vec2 pos = glm::vec2(0.0f);
        glm::vec2 size = glm::vec2(1.0f);

        std::array<float, 8> vertices;
        static const std::array<unsigned int, 6> indices;

        VertexArray vao;
        VertexBuffer vbo;
        IndexBuffer ebo;
};