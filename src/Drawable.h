#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "Layout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Drawable {
    public:
        void draw(const ShaderProgram& shaderProgram, GLenum mode) const;
    protected:
        VertexArray vao;
        Layout layout;
        VertexBuffer vbo;
        IndexBuffer ebo;
        
        template<size_t N, size_t M>
        static std::array<glm::vec2, N> dataToVerts(const std::array<float, M>& data, const AttributePointer& attribute) {
            std::array<glm::vec2, N> result;
            size_t stride = attribute.stride / sizeof(float);
            size_t j = 0;
            for (size_t i = attribute.offset / sizeof(float); i < M; i += stride)
                result[j++] = glm::vec2(data[i], data[i + 1]);
            return result;
        }

        template<size_t N, size_t M>
        static void vertsToData(std::array<float, N>& data, const std::array<glm::vec2, M>& verts, const AttributePointer& attribute) {
            size_t stride = attribute.stride / sizeof(float);
            size_t j = 0;
            for (size_t i = attribute.offset / sizeof(float); i < N; i += stride) {
                data[i] = verts[j].x;
                data[i + 1] = verts[j++].y;
            }
        }

        template<size_t N>
        static std::array<glm::vec2, N> rotate(const std::array<glm::vec2, N>& verts, float angle, const glm::vec2& axis) {
            std::array<glm::vec2, N> result;
            for (size_t i = 0; i < N; i++)
                result[i] = glm::rotate(verts[i] - axis, angle) + axis;
            return result;
        }

        template<size_t N>
        static std::array<glm::vec2, N> translate(const std::array<glm::vec2, N>& verts, const glm::vec2& translation) {
            std::array<glm::vec2, N> result;
            for (size_t i = 0; i < N; i++)
                result[i] = verts[i] + translation;
            return result;
        }

        template<size_t N>
        static std::array<glm::vec2, N> scale(const std::array<glm::vec2, N>& verts, const glm::vec2& factor) {
            std::array<glm::vec2, N> result;
            for (size_t i = 0; i < N; i++)
                result[i] = verts[i] * factor;
            return result;
        }

        template<size_t N>
        static std::array<glm::vec2, N> transform(const std::array<glm::vec2, N>& verts, const glm::vec2& factor,
                                                const glm::vec2& translation,
                                                float angle, const glm::vec2& axis) {
            std::array<glm::vec2, N> result;
            for (size_t i = 0; i < N; i++) {
                result[i] = glm::rotate(verts[i] * factor - axis, angle) + axis + translation;
            }
            return result;
        }
};