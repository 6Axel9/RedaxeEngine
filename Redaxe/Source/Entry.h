#pragma once
#include "Application.h"

#ifdef RDX_PLATFORM_WIN
	extern rdx::Application* rdx::CreateApp();

	int main()
	{
		auto app = rdx::CreateApp();
		app->Run();
		delete app;
	}
#endif