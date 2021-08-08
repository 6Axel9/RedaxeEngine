#pragma once
#include "Core.h"

namespace rdx
{
	class RDX_API Application
	{
	public:
		Application();
		virtual~Application();
	public:
		void Run();
	};

	Application* CreateApp();
}