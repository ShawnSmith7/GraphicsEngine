#pragma once

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Drawable {
    public:
        void draw(const ShaderProgram& shaderProgram) const;
    protected:
        VertexArray vao;
        VertexBuffer vbo;
        IndexBuffer ebo;
};