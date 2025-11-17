#pragma once

#include <glad/glad.h>

class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        static void unbind();

        static void enableAttribute(unsigned int i);
        static void setAttributePointer(GLuint i, GLint size, GLenum type, bool normalized, GLsizei stride, size_t offset);
    private:
        unsigned int ID;
};