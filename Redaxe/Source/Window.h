#pragma once
#include "rdxpch.h"

namespace rdx
{
	enum Profiles { Compatibility = GLFW_OPENGL_COMPAT_PROFILE, Core = GLFW_OPENGL_CORE_PROFILE};
	enum Resolutions { FHD = 1080, HD = 720, SD = 576 };

	class Window
	{
	public:
	public:
		Window() : m_window(nullptr), m_monitor(nullptr) {}
		~Window() {}
	public:
		void Initialize(int majorVersion, int minorVersion, int profile);
		void Terminate();
	public:
		void Open(int resolution, int sampleRate = 0);
		void UpdateInputs();
		void SwapBuffer();
		void ClearScreen();
		void Close();
	public:
		bool HasClosed();
	private:
		GLFWwindow* m_window;
		GLFWmonitor* m_monitor;
	};
}
