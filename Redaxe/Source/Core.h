#include <stdio.h>

#ifdef RDX_PLATFORM_WIN
	#ifdef RDX_BUILD_DLL
		#define RDX_API __declspec(dllexport)
	#else
		#define RDX_API __declspec(dllimport)
	#endif
#else
	#error Unsupported Platform
#endif