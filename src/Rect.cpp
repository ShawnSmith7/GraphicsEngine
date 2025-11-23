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
        glm::vec2(0.0f),
        glm::vec2(0.0f, size.y),
        size,
        glm::vec2(size.x, 0.0f)
    };

    glm::vec2 center = 0.5f * size;
    for (glm::vec2& vert : verts) {
        vert = Transformer::rotate(vert + pos, angle, pos + center);
    }

    vertices = Transformer::vertsToData(verts);

    vbo.bind();
    vbo.setBufferData(vertices, GL_STATIC_DRAW);

    ebo.bind();
    ebo.setBufferData(indices, GL_STATIC_DRAW);

    vao.enableAttribute(0);
    vao.setAttributePointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    vao.unbind();
}