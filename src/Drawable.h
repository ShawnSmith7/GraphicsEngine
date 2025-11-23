#pragma once

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
};