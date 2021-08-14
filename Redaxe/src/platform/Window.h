#pragma once
#include "rdxpch.h"
#include "events/InputEvents.h"

namespace rdx
{
	struct WindowData
	{
		WindowData() : isFullscreen(0), hasVsync(1), width(1280), height(720) {}
		bool isFullscreen;
		bool hasVsync;
		int width;
		int height;

		EventDispatcher eventDispatcher;
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
		void SwapBuffer();
		void ClearScreen();
		void BindCallbacks();
		void ToggleFullScreen();
		void ToggleVsync();

		EventDispatcher& EventDispatcher() { return m_windowData.eventDispatcher; };
	public:
		bool HasVsync();
		bool HasClosed();
	private:
		GLFWwindow* m_window;
		GLFWmonitor* m_monitor;
		WindowData m_windowData;
	};
}
