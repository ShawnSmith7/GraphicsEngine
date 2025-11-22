#pragma once

#define _USE_MATH_DEFINES

#include "Drawable.h"

class Circle : public Drawable {
    public:
    Circle();
    Circle(const glm::vec2& pos, float radius);
    Circle(const glm::vec2& pos, float radius, const glm::vec4& color);
    Circle(const glm::vec2& pos, float radius, const glm::vec4& color, unsigned int resolution);

    void draw(const ShaderProgram& shaderProgram) const;
    private:
        glm::vec2 pos = glm::vec2(0.0f);
        float radius = 1.0f;
        glm::vec4 color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        unsigned int resolution = 64;

        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        void genGeometry();
};