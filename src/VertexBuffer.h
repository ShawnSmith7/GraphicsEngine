#pragma once
#include <glad/glad.h>

class VertexBuffer {
    public:
        VertexBuffer();
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

        template<typename T, size_t N>
        void setBufferData(const T (&data)[N], GLenum usage) const {
            bind();
            glBufferData(GL_ARRAY_BUFFER, N * sizeof(T), data, usage);
        }
    private:
        unsigned int ID;
};