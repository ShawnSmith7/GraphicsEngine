#pragma once

#include "Buffer.h"

class IndexBuffer : public Buffer {
    public:
        using Buffer::Buffer;

        void bind() const;
        static void unbind();

        template<typename T, size_t N>
        void setBufferData(const T (&data)[N], GLenum usage) {
            count = N;
            Buffer::setBufferData(GL_ELEMENT_ARRAY_BUFFER, data, usage);
        }

        template<typename T, size_t N>
        void setBufferData(const std::array<T, N>& data, GLenum usage) {
            count = N;
            Buffer::setBufferData(GL_ELEMENT_ARRAY_BUFFER, data, usage);
        }

        size_t getCount() const;
    private:
        size_t count = 0;
};