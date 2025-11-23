#include "Window.h"
#include "Rect.h"
#include "Line.h"
#include "Circle.h"

void processInput(GLFWwindow *window);

int main() {
    Window window(1280, 800, "GraphicsEngine");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");

    glm::vec4 coolColor(1.0f, 0.5f, 0.2f, 1.0f);

    Rect rect(glm::vec2(320.0f, 200.0f), glm::vec2(200.0f), coolColor);
    Circle circle(glm::vec2(640.0f, 200.0f), 100.0f, coolColor);
    Line line(glm::vec2(860.0f, 100.0f), glm::vec2(1060.0f, 300.0f), coolColor, 20.0f);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    window.setRenderLoopFunc([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);
        
        glm::mat4 projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -1.0f, 1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 model(1.0f);
        glm::mat4 transform = projection * view * model;
        shaderProgram.setMat4("transform", transform);
        rect.draw(shaderProgram);
        circle.draw(shaderProgram);
        line.draw(shaderProgram);
    });
    window.renderLoop();

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}