#include "rdxpch.h"
#include "Window.h"

namespace rdx
{
    void Window::Initialize(int majorVersion, int minorVersion, int profile)
    {
        GLFWerrorfun errorHandler = [](int code, const char* msg)
        {
            spdlog::critical("[GLFW] [code {0}] [{1}]", code, msg);
        };
        glfwSetErrorCallback(errorHandler);

        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
        glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
    }

    void Window::Terminate()
    {
        glfwTerminate();
    }

    void Window::Open(int resolution, int sampleRate)
    {
        m_monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(m_monitor);

        glfwWindowHint(GLFW_SAMPLES, sampleRate);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        m_window = glfwCreateWindow(resolution * 16 / 9, resolution, "Redaxe Engine", NULL, NULL);
        if (!m_window)
            return;

        glfwMakeContextCurrent(m_window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    void Window::UpdateInputs()
    {
        glfwPollEvents();
    }

    void Window::SwapBuffer()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::ClearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::Close()
    {
        glfwDestroyWindow(m_window);
    }

    bool Window::HasClosed()
    {
        return glfwWindowShouldClose(m_window);
    }
}