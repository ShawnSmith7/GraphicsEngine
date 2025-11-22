#include "Line.h"

Line::Line() {
    genGeometry();
}

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2) :
    pos1(pos1), pos2(pos2) {
    genGeometry();
}

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2, const glm::vec4& color) :
    pos1(pos1), pos2(pos2), color(color) {
    genGeometry();
}

void Line::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    Drawable::draw(shaderProgram, GL_LINES);
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

    vao.enableAttribute(0);
    vao.setAttributePointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    vao.unbind();
}