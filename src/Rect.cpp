#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color, float angle) :
    pos(pos), size(size), color(color), angle(angle) {
    genGeometry();
}

void Rect::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    Drawable::draw(shaderProgram, GL_TRIANGLES);
}

const std::array<unsigned int, 6> Rect::indices = { 0, 1, 2, 2, 3, 0 };

void Rect::genGeometry() {
    vao.bind();

    std::array<glm::vec2, 4> verts = {
        pos,
        glm::vec2(pos.x, pos.y + size.y),
        pos + size,
        glm::vec2(pos.x + size.x, pos.y)
    };

    vertices = Transformer::vertsToData(Transformer::rotate(verts, angle));

    vbo.bind();
    vbo.setBufferData(vertices, GL_STATIC_DRAW);

    ebo.bind();
    ebo.setBufferData(indices, GL_STATIC_DRAW);

    vao.enableAttribute(0);
    vao.setAttributePointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    vao.unbind();
}