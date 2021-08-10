#include "rdxpch.h"
#include "Application.h"

namespace rdx
{
	Application::Application() 
		: m_window(0), m_hasEnded(0)
	{
		m_window = new Window(WindowData());
	}

	Application::~Application()
	{
		delete m_window;
	}

	void Application::Update()
	{
		m_window->BindCallbacks();
		while (!m_window->HasClosed() && !m_hasEnded)
		{
			m_window->UpdateInputs();
			m_window->ClearScreen();
			m_window->SwapBuffer();
		}
	}
}