#include "Window.h"

Window::Window() {
    init();
}

Window::Window(unsigned int width, unsigned int height, const char *title) :
    width(width), height(height), title(title) {
    init();
}

Window::~Window() {
    glfwDestroyWindow(window);
}

GLFWwindow* Window::get() const {
    return window;
}

unsigned int Window::getWidth() const {
    return width;
}

unsigned int Window::getHeight() const {
    return height;
}

const char *Window::getTitle() const {
    return title;
}

float Window::getAspectRatio() const {
    return (float)width / (float)height;
}

void Window::setFramebufferSizeCallback(std::function<void(int, int)> callback) {
    userFramebufferSizeCallback = std::move(callback);
}

void Window::setRenderLoopFunc(std::function<void()> func) {
    userRenderLoopFunc = std::move(func);
}

void Window::renderLoop() const {
    while(!glfwWindowShouldClose(window)) {
        if (userRenderLoopFunc)
            userRenderLoopFunc();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, 0, 0);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))    {
        std::cerr << "Failed to initialize GLAD\n";
        std::exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(window, this);

    glfwSetFramebufferSizeCallback(window, internalFramebufferSizeCallback);
}

void Window::internalFramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));

    win->width = width;
    win->height = height;

    glViewport(0, 0, width, height);

    if (win->userFramebufferSizeCallback)
        win->userFramebufferSizeCallback(width, height);
}