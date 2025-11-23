#pragma once

#include <vector>

#include "VertexArray.h"

class Layout {
    public:
        struct AttributePointer {
            GLuint i; 
            GLint size; 
            GLenum type; 
            bool normalized; 
            GLsizei stride; 
            size_t offset;
        };

        Layout(const std::vector<AttributePointer>& layout);
        void apply() const;
    private:
        std::vector<AttributePointer> layout;
};