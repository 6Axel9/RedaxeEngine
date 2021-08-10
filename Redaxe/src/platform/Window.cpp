#include "rdxpch.h"
#include "Window.h"

namespace rdx
{
    Window::Window(const WindowData& data)
        : m_window(nullptr), m_monitor(nullptr), m_windowData()
    {
        if (Window::m_count == 0)
        {
            GLFWerrorfun errorHandler = [](int code, const char* msg)
            {
                std::cout << "[glfw] [" << code << "] [" << msg << "]\n";
            };
            
            glfwSetErrorCallback(errorHandler);
            glfwInit();
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

        m_windowData.height = data.height;
        m_windowData.width = data.width;
        m_windowData.isFullscreen = data.isFullscreen;
        m_windowData.hasVsync = data.hasVsync;

        m_monitor = glfwGetPrimaryMonitor();
        m_window = glfwCreateWindow(m_windowData.width, m_windowData.height, "Redaxe Engine", m_windowData.isFullscreen ? m_monitor : NULL, NULL);
        if (!m_window)
        {
            glfwTerminate();
            return;
        }

        GLFWwindowmaximizefun maximizeHandler = [](GLFWwindow* win, int val)
        {
            Window* windowPtr = (Window*)glfwGetWindowUserPointer(win);
            windowPtr->ToggleFullScreen();
        };
        glfwSetWindowMaximizeCallback(m_window, maximizeHandler);

        Window::m_count++;
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, this);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glfwSwapInterval(m_windowData.hasVsync ? 1 : 0);
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        Window::m_count--;

        if(Window::m_count == 0)
            glfwTerminate();
    }

    void Window::UpdateInputs()
    {
        glfwPollEvents();
    }

    void Window::SetF(GLFWwindow* win, int value)
    {
        ToggleFullScreen();
    }

    void Window::ToggleFullScreen()
    {
        m_windowData.isFullscreen = !m_windowData.isFullscreen;
        glfwSetWindowMonitor(m_window, m_windowData.isFullscreen ? m_monitor : NULL, 0, 0, m_windowData.width, m_windowData.height, GLFW_DONT_CARE);
    }

    void Window::ToggleVsync()
    {
        m_windowData.hasVsync = !m_windowData.hasVsync;
        glfwSwapInterval(m_windowData.hasVsync ? 1 : 0);
    }

    void Window::SwapBuffer()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::ClearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    bool Window::HasVsync()
    {
        return false;
    }

    bool Window::HasClosed()
    {
        return glfwWindowShouldClose(m_window);
    }

    int Window::m_count = 0;
}