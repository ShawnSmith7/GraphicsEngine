#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &ID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &ID);
}

void VertexArray::bind() const {
    glBindVertexArray(ID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}

void VertexArray::enableAttribute(unsigned int i) {
    glEnableVertexAttribArray(i);
}

void VertexArray::setAttributePointer(GLuint i, GLint size, GLenum type, bool normalized, GLsizei stride, size_t offset) {
    glVertexAttribPointer(i, size, type, normalized ? GL_TRUE : GL_FALSE, stride, (void*)offset);
}