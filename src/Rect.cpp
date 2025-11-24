#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color) :
    pos(pos), size(size), color(color) {
    genGeometry();
}

void Rect::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    Drawable::draw(shaderProgram, GL_TRIANGLES);
}

const std::array<unsigned int, 6> Rect::indices = { 0, 1, 2, 2, 3, 0 };

void Rect::genGeometry() {
    vao.bind();

    static const std::array<glm::vec2, 4> unitRect = {
        glm::vec2(0.0f),
        glm::vec2(0.0f, 1.0f),
        glm::vec2(1.0f),
        glm::vec2(1.0f, 0.0f)
    };

    std::array<glm::vec2, 4> verts = transform(unitRect, size, pos - 0.5f * size, 1.0f, 0.5f * size);

    AttributePointer attribute = {0, 2, GL_FLOAT, false, 2 * sizeof(float), 0};
    vertsToData(vertices, verts, attribute);

    vbo.bind();
    vbo.setBufferData(vertices, GL_STATIC_DRAW);

    ebo.bind();
    ebo.setBufferData(indices, GL_STATIC_DRAW);

    layout.set({attribute});
    layout.apply();

    vao.unbind();
}