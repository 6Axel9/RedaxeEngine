#pragma once
#include "Application.h"

#ifdef RDX_PLATFORM_WIN
	extern RDX::Application* RDX::CreateApp();

	int main()
	{
		auto app = RDX::CreateApp();
		app->Run();
		delete app;
	}
#endif