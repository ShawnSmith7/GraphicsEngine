#include "IndexBuffer.h"

void IndexBuffer::bind() const {
    Buffer::bind(GL_ELEMENT_ARRAY_BUFFER);
}

void IndexBuffer::unbind() {
    Buffer::unbind(GL_ELEMENT_ARRAY_BUFFER);
}

size_t IndexBuffer::getCount() const {
    return count;
}