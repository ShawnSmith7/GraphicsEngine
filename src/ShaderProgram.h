#pragma once

#ifndef SRC_DIR
#define SRC_DIR "./"
#endif

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ShaderProgram {
    public:
        ShaderProgram(const std::string& vertexShaderFileName, const std::string& fragmentShaderFileName);
        ~ShaderProgram();

        void use() const;
        void unuse() const;

        void setVec4(const char *name, const glm::vec4& value) const;
        void setMat4(const char *name, const glm::mat4& value) const;
    private:
        unsigned int ID;

        static std::string srcFileToString(const std::string& fileName);
        static unsigned int compileShader(const GLenum& shaderType, const std::string& shaderFileName);
};