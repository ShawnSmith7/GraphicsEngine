#pragma once

#include "Buffer.h"

class VertexBuffer : public Buffer {
    public:
        using Buffer::Buffer;

        void bind() const;
        static void unbind();

        template<typename T, size_t N>
        void setBufferData(const T (&data)[N], GLenum usage) const {
            Buffer::setBufferData(GL_ARRAY_BUFFER, data, usage);
        }

        template<typename T, size_t N>
        void setBufferData(const std::array<T, N>& data, GLenum usage) const {
            Buffer::setBufferData(GL_ARRAY_BUFFER, data, usage);
        }
};