#include "Window.h"
#include "Rect.h"
#include "Line.h"

void processInput(GLFWwindow *window);

int main() {
    Window window(800, 600, "GraphicsEngine");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");

    Rect rect(glm::vec2(0.0f), glm::vec2(1.0f), glm::vec4(1.0f, 0.5f, 0.2f, 1.0f));

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    window.setRenderLoopFunc([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);
        
        glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 100.0f, 0.0f)), glm::vec3(100.0f, 100.0f, 1.0f));
        glm::mat4 view(1.0f);
        glm::mat4 projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -1.0f, 1.0f);
        glm::mat4 transform = projection * view * model;
        shaderProgram.setMat4("transform", transform);
        rect.draw(shaderProgram);
    });
    window.renderLoop();

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}