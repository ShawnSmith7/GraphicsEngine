#include "Line.h"

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2, const glm::vec4& color, float width, Type type) :
    pos1(pos1), pos2(pos2), color(color), width(width), type(type) {
    genGeometry();
}

void Line::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    switch (type) {
        case Type::Round:
        case Type::Rect:
        break;
        case Type::Default: default:
        glLineWidth(width);
        Drawable::draw(shaderProgram, GL_LINES);
        glLineWidth(1);
    }
}

const std::array<unsigned int, 2> Line::indices = { 0, 1 };

void Line::genGeometry() {
    vao.bind();

    vertices = {
        pos1.x, pos1.y,
        pos2.x, pos2.y
    };

    vbo.bind();
    vbo.setBufferData(vertices, GL_STATIC_DRAW);

    ebo.bind();
    ebo.setBufferData(indices, GL_STATIC_DRAW);

    layout.set({{0, 2, GL_FLOAT, false, 2 * sizeof(float), 0}});
    layout.apply();

    vao.unbind();
}