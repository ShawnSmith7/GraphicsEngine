#include "Rect.h"

Rect::Rect() {
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

    vao.unbind();
}

Rect::Rect(const glm::vec2& pos, const glm::vec2& size) :
    pos(pos), size(size) {
    
}

void Rect::draw(const ShaderProgram& shaderProgram) {
    shaderProgram.use();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

const std::array<unsigned int, 6> indices = { 0, 1, 2, 2, 3, 0 };