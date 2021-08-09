#include "rdxpch.h"
#include "Application.h"

namespace rdx
{
	Application::Application()
	{
		m_window = new Window;
		m_window->Initialize(4, 0, Profiles::Compatibility);
	}

	Application::~Application()
	{
		m_window->Terminate();
		delete m_window;
	}

	void Application::Start()
	{
		m_window->Open(Resolutions::HD);
	}

	void Application::Update()
	{
		while (!m_window->HasClosed())
		{
			m_window->UpdateInputs();
			m_window->ClearScreen();
			m_window->SwapBuffer();
		}
	}

	void Application::End()
	{
		m_window->Close();
	}
}