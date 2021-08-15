#pragma once
#include "platform/Application.h"

#ifdef RDX_PLATFORM_WIN
	extern rdx::Application* rdx::CreateApp();

	int main()
	{
		rdx::Application* app = rdx::CreateApp();
		app->Update();
		delete app;
	}
#endif