#pragma once
#include "platform/Application.h"

#ifdef RDX_PLATFORM_WIN
	extern rdx::Application* rdx::CreateApp();

	int main()
	{
		auto app = rdx::CreateApp();
		app->Update();
		delete app;
	}
#endif