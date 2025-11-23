#pragma once

#include "Drawable.h"

class Rect : public Drawable {
    public:
        Rect(const glm::vec2& pos = glm::vec2(0.0f), 
            const glm::vec2& size = glm::vec2(1.0f), 
            const glm::vec4& color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

        void draw(const ShaderProgram& shaderProgram) const;
    private:
        glm::vec2 pos, size;
        glm::vec4 color;

        std::array<float, 8> vertices;
        static const std::array<unsigned int, 6> indices;

        void genGeometry();
};