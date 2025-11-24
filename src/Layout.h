#pragma once

#include <vector>

#include "VertexArray.h"

struct AttributePointer {
    GLuint i; 
    GLint size; 
    GLenum type; 
    bool normalized; 
    GLsizei stride; 
    size_t offset;
};

class Layout {
    public:
        Layout();
        Layout(const std::vector<AttributePointer>& layout);

        void set(const std::vector<AttributePointer>& layout);
        std::vector<AttributePointer> get() const;

        void apply() const;
    private:
        std::vector<AttributePointer> layout;
};