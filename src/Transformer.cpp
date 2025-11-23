#include "Transformer.h"

glm::vec2 Transformer::rotate(const glm::vec2& vertex, float angle, const glm::vec2& axis) {
    return glm::rotate(vertex - axis, angle) + axis;
}