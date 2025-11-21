#include "VertexBuffer.h"

void VertexBuffer::bind() const {
    Buffer::bind(GL_ARRAY_BUFFER);
}

void VertexBuffer::unbind() {
    Buffer::unbind(GL_ARRAY_BUFFER);
}