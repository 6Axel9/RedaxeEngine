#include "rdxpch.h"
#include "Interface.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace rdx
{
    Interface::Interface() : m_glslVersion("#version 400 core"), m_isSubOpen(false), m_isOpen(true), m_window(0), m_io(0)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        m_io = &ImGui::GetIO();
    }

    Interface::~Interface()
    {
    }

    void Interface::Open(Window* window)
    {
        m_window = window;

        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(m_window->GetWindow(), true);
        ImGui_ImplOpenGL3_Init(m_glslVersion);

        auto font = m_io->Fonts->AddFontFromFileTTF("../Redaxe/assets/fonts/Roboto-Regular.ttf", 13);
    }

    void Interface::Bind()
    {
    }

    void Interface::Update()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow(&m_isOpen);

        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Interface::Close()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
