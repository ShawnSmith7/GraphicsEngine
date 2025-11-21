#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Window.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "Rect.h"

void processInput(GLFWwindow *window);

int main() {
    Window window(800, 600, "GraphicsEngine");

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

    IndexBuffer indexBuffer;
    indexBuffer.setBufferData(indices, GL_STATIC_DRAW);

    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 5 * sizeof(float), 0);

    vertexArray.enableAttribute(1);
    vertexArray.setAttributePointer(1, 3, GL_FLOAT, false, 5 * sizeof(float), 2 * sizeof(float));

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");
    shaderProgram.use();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    window.setRenderLoopFunc([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);
        
        glm::mat4 model(1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -1.0f, 1.0f);
        glm::mat4 transform = projection * view * model;
        shaderProgram.setMat4("transform", transform);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    });
    window.renderLoop();

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}