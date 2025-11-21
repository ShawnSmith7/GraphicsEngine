#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::string& vertexShaderFileName, const std::string& fragmentShaderFileName) :
    ID(glCreateProgram()) {
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderFileName);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderFileName);

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    int  success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(ID, 512, 0, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << '\n';
        throw -1;
    }
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(ID);
}

void ShaderProgram::use() const {
    glUseProgram(ID);
}

void ShaderProgram::unuse() const {
    glUseProgram(0);
}

void ShaderProgram::setVec4(const char *name, const glm::vec4& value) const {
    glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
}

void ShaderProgram::setMat4(const char *name, const glm::mat4& value) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));
}

std::string ShaderProgram::srcFileToString(const std::string& fileName) {
    std::string filePath = std::string(SRC_DIR) + fileName;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filePath << '\n';
        throw -1;
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}

unsigned int ShaderProgram::compileShader(const GLenum& shaderType, const std::string& shaderFileName) {
    std::string shaderString = srcFileToString(shaderFileName);
    const char *shaderSource = shaderString.c_str();
    
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, 0);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        std::string shaderTypeString;
        switch (shaderType) {
            case GL_VERTEX_SHADER:
                shaderTypeString = "VERTEX::";
                break;
            case GL_FRAGMENT_SHADER:
                shaderTypeString = "FRAGMENT::";
                break;
            default:
                shaderTypeString = "";
        }
        
        glGetShaderInfoLog(shader, 512, 0, infoLog);
        std::cerr << "ERROR::SHADER::" << shaderTypeString << "COMPILATION_FAILED\n" << infoLog << '\n';
        throw -1;
    }

    return shader;
}