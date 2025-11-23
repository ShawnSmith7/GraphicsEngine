#pragma once

#include "Drawable.h"

class Line : public Drawable {
    public:
        enum class Type { Default, Rect, Round };
        
        Line(const glm::vec2& pos1 = glm::vec2(0.0f), 
            const glm::vec2& pos2 = glm::vec2(1.0f, 0.0f), 
            const glm::vec4& color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), 
            float width = 1, 
            Type type = Type::Default);

        void draw(const ShaderProgram& shaderProgram) const;
    private:
        glm::vec2 pos1, pos2;
        glm::vec4 color;
        float width;
        Type type;

        std::array<float, 4> vertices;
        static const std::array<unsigned int, 2> indices;

        void genGeometry();
};