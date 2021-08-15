#pragma once
#include "Window.h"
#include "Interface.h"

namespace rdx
{
	class Application
	{
	public:
		Application();
		virtual~Application();
	public:
		void Update();
	private:
		Interface* m_interface;
		Window* m_window;
		bool m_hasEnded;
	};
	
	Application* CreateApp();
}