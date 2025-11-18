#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

unsigned int screenWidth = 800;
unsigned int screenHeight = 600;
float aspectRatio = (float)screenWidth / screenHeight;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", 0, 0);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))    {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    VertexArray vertexArray;
    vertexArray.bind();
    
    float vertices[] = {
        100.0f, 100.0f, 1.0f, 0.0f, 0.0f,
        100.0f, 200.0f, 0.0f, 1.0f, 0.0f,
        200.0f, 200.0f, 0.0f, 0.0f, 1.0f,
        200.0f, 100.0f, 1.0f, 1.0f, 1.0f
    };

    VertexBuffer vertexBuffer;
    vertexBuffer.setBufferData(vertices, GL_STATIC_DRAW);

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 5 * sizeof(float), 0);

    vertexArray.enableAttribute(1);
    vertexArray.setAttributePointer(1, 3, GL_FLOAT, false, 5 * sizeof(float), 2 * sizeof(float));

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");
    shaderProgram.use();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while(!glfwWindowShouldClose(window)) {
        processInput(window);
        
        glm::mat4 transform = glm::ortho(0.0f, (float)screenWidth, (float)screenHeight, 0.0f, -1.0f, 1.0f);
        shaderProgram.setMat4("transform", transform);

        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    screenWidth = width;
    screenHeight = height;
    aspectRatio = (float)screenWidth / screenHeight;
    
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}