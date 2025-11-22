#include "Drawable.h"

void Drawable::draw(const ShaderProgram& shaderProgram, GLenum mode) const {
    shaderProgram.use();
    vao.bind();
    glDrawElements(mode, ebo.getCount(), GL_UNSIGNED_INT, 0);
}