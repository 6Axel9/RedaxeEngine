#pragma once
#include "Core.h"

namespace RDX
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