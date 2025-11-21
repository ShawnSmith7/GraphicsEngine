#include "Drawable.h"

void Drawable::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.use();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}