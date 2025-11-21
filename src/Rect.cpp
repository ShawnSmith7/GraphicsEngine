#include "Rect.h"

Rect::Rect() {
    genGeometry();
}

Rect::Rect(const glm::vec2& pos, const glm::vec2& size) :
    pos(pos), size(size) {
    genGeometry();
}

void Rect::draw(const ShaderProgram& shaderProgram) {
    shaderProgram.use();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

const std::array<unsigned int, 6> Rect::indices = { 0, 1, 2, 2, 3, 0 };

void Rect::genGeometry() {
    vao.bind();

    vertices = {
        pos.x, pos.y,
        pos.x, pos.y + size.y,
        pos.x + size.x, pos.y + size.y,
        pos.x + size.x, pos.y
    };

    vbo.bind();
    vbo.setBufferData(vertices, GL_STATIC_DRAW);

    ebo.bind();
    ebo.setBufferData(indices, GL_STATIC_DRAW);

    vao.enableAttribute(0);
    vao.setAttributePointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    vao.unbind();
}