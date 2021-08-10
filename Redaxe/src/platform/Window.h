#pragma once
#include "rdxpch.h"

namespace rdx
{
	struct WindowData
	{
		WindowData() : isFullscreen(0), hasVsync(1), width(1280), height(720) {}
		bool isFullscreen;
		bool hasVsync;
		int width;
		int height;
	};

	class Window
	{
	public:
		static int m_count;
	public:
		Window(const WindowData& data);
		~Window();
	public:
		void UpdateInputs();
		void SetF(GLFWwindow* win, int value);
		void ToggleFullScreen();
		void ToggleVsync();
		void SwapBuffer();
		void ClearScreen();
	public:
		bool HasVsync();
		bool HasClosed();
	private:
		GLFWwindow* m_window;
		GLFWmonitor* m_monitor;
		WindowData m_windowData;
	};
}
