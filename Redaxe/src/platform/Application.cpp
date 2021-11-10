#include "rdxpch.h"
#include "Application.h"

namespace rdx
{
	Application::Application() : m_window(0), m_hasEnded(0)
	{
		Log::set_pattern("[%T][%^%l%$][%v]");

		m_interface = new Interface();
		m_window = new Window();

		m_window->Dispatcher().AddListener(Event(EventType::KeyUp, [](EventData data)
		{
			Log::info("Up");
		}));

		m_window->Open(WindowData());
		m_interface->Open(m_window);
	}

	Application::~Application()
	{
		m_interface->Close();
		m_window->Close();

		delete m_interface;
		delete m_window;
	}

	void Application::Update()
	{
		while (!m_window->HasClosed() && !m_hasEnded)
		{
			m_window->Update();
			m_interface->Update();
			m_window->Swap();
		}
	}
}