#pragma once
#include "Window.h"

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
		Window* m_window;
		bool m_hasEnded;
	};

	Application* CreateApp();
}