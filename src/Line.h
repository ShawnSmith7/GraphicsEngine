#pragma once

#include "Drawable.h"

class Line : public Drawable {
    public:
        Line();
        Line(const glm::vec2& pos1, const glm::vec2& pos2);
        Line(const glm::vec2& pos1, const glm::vec2& pos2, const glm::vec4& color);

        void draw(const ShaderProgram& shaderProgram) const;
    private:
        glm::vec2 pos1 = glm::vec2(0.0f), pos2 = glm::vec2(1.0f, 0.0f);
        glm::vec4 color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

        std::array<float, 4> vertices;
        static const std::array<unsigned int, 2> indices;

        void genGeometry();
};