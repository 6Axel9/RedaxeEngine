#include "rdxpch.h"
#include "Window.h"

namespace rdx
{
    Window::Window() : m_window(nullptr), m_windowData()
    {
        GLFWerrorfun errorHandler = [](int code, const char* msg)
        {
            Log::error("{0} - {1}", code, msg);
        };
        glfwSetErrorCallback(errorHandler);
        glfwInit();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::Open(const WindowData& data)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

        m_windowData.height = data.height;
        m_windowData.width = data.width;
        m_windowData.name = data.name;

        m_window = glfwCreateWindow(data.width, data.height, data.name, NULL, NULL);
        if (!m_window)
            return;

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(true);
    }

    void Window::Bind()
    {
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glfwSetWindowUserPointer(m_window, &m_windowData);

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                WindowData* userPtr = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                switch (action)
                {
                case GLFW_PRESS:
                    userPtr->dispatcher.Invoke(KeyDownData(key));
                    break;
                case GLFW_RELEASE:
                    userPtr->dispatcher.Invoke(KeyUpData(key));
                    break;
                case GLFW_REPEAT:
                    userPtr->dispatcher.Invoke(KeyHoldData(key));
                    break;
                default:
                    break;
                }
            });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
            {
                WindowData* userPtr = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                switch (action)
                {
                case GLFW_PRESS:
                    userPtr->dispatcher.Invoke(MouseDownData(button));
                    break;
                case GLFW_RELEASE:
                    userPtr->dispatcher.Invoke(MouseUpData(button));
                    break;
                case GLFW_REPEAT:
                    userPtr->dispatcher.Invoke(MouseHoldData(button));
                    break;
                default:
                    break;
                }
            });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
            {
                WindowData* userPtr = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                userPtr->dispatcher.Invoke(MouseScrollData(xoffset, yoffset));
            });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
            {
                WindowData* userPtr = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
                userPtr->dispatcher.Invoke(MouseMoveData(xpos, ypos));
            });
    }

    void Window::Update()
    {
        glfwPollEvents();
    }

    void Window::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void Window::Swap()
    {
        glfwSwapBuffers(m_window);
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