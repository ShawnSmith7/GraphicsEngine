#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>
#include <functional>

class Window {
    public:
        Window();
        Window(unsigned int width, unsigned int height, const char *title);
        ~Window();

        GLFWwindow* get() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        const char *getTitle() const;
        float getAspectRatio() const;

        void setFramebufferSizeCallback(std::function<void(int, int)> callback);

        void renderLoop() const;
    private:
        GLFWwindow* window;
        unsigned int width = 800;
        unsigned int height = 600;
        const char *title = "Window";

        std::function<void(int, int)> userFramebufferSizeCallback;

        void init();
        
        static void internalFramebufferSizeCallback(GLFWwindow* window, int width, int height);
};