#pragma once

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

#include <array>

namespace Transformer {
        template<size_t N>
        std::array<float, 2 * N> vertsToData(const std::array<glm::vec2, N>& vertices) {
            std::array<float, 2 * N> result;
            for (unsigned int i = 0; i < N; i++) {
                result[2 * i] = vertices[i].x;
                result[2 * i + 1] = vertices[i].y;
            }
            return result;
        }

        template<size_t N>
        std::array<glm::vec2, N> rotate(const std::array<glm::vec2, N>& vertices, float angle) {
            std::array<glm::vec2, N> result;
            for (unsigned int i = 0; i < N; i++)
                result[i] = glm::rotate(vertices[i], angle);
            return result;
        }
}