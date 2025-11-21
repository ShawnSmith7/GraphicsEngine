#pragma once

#include <glad/glad.h>

#include <array>

class Buffer {
    public:
        Buffer();
        ~Buffer();

        void bind(GLenum target) const;
        static void unbind(GLenum target);

        template<typename T, size_t N>
        void setBufferData(GLenum target, const T (&data)[N], GLenum usage) const {
            bind(target);
            glBufferData(target, N * sizeof(T), data, usage);
        }

        template<typename T, size_t N>
        void setBufferData(GLenum target, const std::array<T, N>& data, GLenum usage) const {
            bind(target);
            glBufferData(target, N * sizeof(T), data.data(), usage);
        }
    private:
        unsigned int ID;
};