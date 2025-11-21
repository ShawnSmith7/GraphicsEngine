#pragma once

#include "Drawable.h"

class Rect : public Drawable {
    public:
        Rect();
        Rect(const glm::vec2& pos, const glm::vec2& size);
        Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color);

        void draw(const ShaderProgram& shaderProgram) const;
    private:
        glm::vec2 pos = glm::vec2(0.0f);
        glm::vec2 size = glm::vec2(1.0f);
        glm::vec4 color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

        std::array<float, 8> vertices;
        static const std::array<unsigned int, 6> indices;

        void genGeometry();
};