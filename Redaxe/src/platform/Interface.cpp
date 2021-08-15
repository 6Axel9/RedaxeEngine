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

        if (m_isOpen)
            ImGui::ShowDemoWindow(&m_isOpen);

        static float f = 0.0f;
        static int counter = 0;
        float clearColor[4] = { 0.45f, 0.55f, 0.60f, 1.00f };

        ImGui::Begin("Hello, world!");

        ImGui::Text("This is some useful text.");
        ImGui::Checkbox("Demo Window", &m_isOpen);
        ImGui::Checkbox("Another Window", &m_isSubOpen);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
        ImGui::ColorEdit3("clear color", (float*)clearColor);

        if (ImGui::Button("Button"))
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();

        if (m_isSubOpen)
        {
            ImGui::SetWindowPos(ImVec2(0, 0));
            ImGui::Begin("Another Window", &m_isSubOpen);
            
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                m_isSubOpen = false;
            ImGui::End();
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window->GetWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clearColor[0] * clearColor[3], clearColor[1] * clearColor[3], clearColor[2] * clearColor[3], clearColor[3]);
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
