#include "Buffer.h"

Buffer::Buffer() {
    glGenBuffers(1, &ID);
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &ID);
}

void Buffer::bind(GLenum target) const {
    glBindBuffer(target, ID);
}

void Buffer::unbind(GLenum target) {
    glBindBuffer(target, 0);
}