#include "rdxpch.h"
#include "Application.h"

namespace rdx
{
	Application::Application() : m_window(0), m_hasEnded(0)
	{
		Log::set_pattern("[%T][%^%l%$][%v]");


		m_window = new Window();
		m_window->Open(WindowData());
	}

	Application::~Application()
	{
		m_window->Close();
		delete m_window;
	}

	void Application::Update()
	{
		m_window->Bind();
		while (!m_window->HasClosed() && !m_hasEnded)
		{
			m_window->Update();
			m_window->Clear();
			m_window->Swap();
		}
	}
}