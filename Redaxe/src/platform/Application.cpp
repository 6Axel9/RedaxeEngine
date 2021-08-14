#include "rdxpch.h"
#include "Application.h"

namespace rdx
{
	Application::Application() 
		: m_window(0), m_hasEnded(0)
	{
		spdlog::set_pattern("[%H:%M:%S][%^%l%$] %v");

		m_window = new Window(WindowData());

		Event onKeyDown(EventType::KeyDown, [](EventData& data)
		{
			std::cout << "Down" << std::endl;
		});
		Event onKeyUp(EventType::KeyUp, [](EventData& data)
		{
				KeyUpData& ref = dynamic_cast<KeyUpData&>(data);
			std::cout << ref.key << std::endl;
		});

		m_window->EventDispatcher().AddListener(onKeyDown);
		m_window->EventDispatcher().AddListener(onKeyUp);
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