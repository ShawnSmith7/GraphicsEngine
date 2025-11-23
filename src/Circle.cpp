#include "Circle.h"

Circle::Circle(const glm::vec2& pos, float radius, const glm::vec4& color, unsigned int resolution) :
    pos(pos), radius(radius), color(color), resolution(resolution) {
    genGeometry();
}

void Circle::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    Drawable::draw(shaderProgram, GL_TRIANGLES);
}

void Circle::genGeometry() {
    vao.bind();

    vertices.clear();
    vertices.resize(2 * (resolution + 2));

    vertices[0] = pos.x;
    vertices[1] = pos.y;
    float stride = 2.0f * M_PI / resolution;
    for (unsigned int i = 0; i < resolution; i++) {
        float angle = i * stride;
        vertices[2 + 2 * i] = pos.x + radius * cos(angle);
        vertices[2 + 2 * i + 1] = pos.y + radius * sin(angle);
    }

    vbo.bind();
    vbo.setBufferData(vertices, GL_STATIC_DRAW);

    indices.clear();
    indices.resize(3 * resolution);

    for (unsigned int k = 0; k < resolution; k++) {
        indices[3 * k] = 0;
        indices[3 * k + 1] = 1 + k;
        indices[3 * k + 2] = 1 + ((k + 1) % resolution);
    }

    ebo.bind();
    ebo.setBufferData(indices, GL_STATIC_DRAW);

    layout.set({{0, 2, GL_FLOAT, false, 2 * sizeof(float), 0}});
    layout.apply();

    vao.unbind();
}