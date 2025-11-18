#include "VertexBuffer.h"

VertexBuffer::VertexBuffer() {
    glGenBuffers(1, &ID);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &ID);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}