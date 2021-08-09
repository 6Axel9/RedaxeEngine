#pragma once
#include "Core.h"
#include "Window.h"

namespace rdx
{
	class RDX_API Application
	{
	public:
		Application();
		virtual~Application();
	public:
		void Start();
		void Update();
		void End();
	private:
		Window* m_window;
	};

	Application* CreateApp();
}