#pragma once

#include <glad/glad.h>

class IndexBuffer {
    public:
        IndexBuffer();
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        template<typename T, size_t N>
        void setBufferData(const T (&data)[N], GLenum usage) {
            bind();
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, N * sizeof(T), data, usage);
        }
    private:
        unsigned int ID;
};