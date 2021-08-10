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

		Event<KeyDownData> keyDownEvent;
		Event<KeyUpData> keyUpEvent;
		Event<KeyHoldData> keyHoldEvent;
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

		const Event<KeyDownData>& OnKeyDownEvent() { return m_windowData.keyDownEvent; };
		const Event<KeyUpData>& OnKeyUpEvent() { return m_windowData.keyUpEvent; };
		const Event<KeyHoldData>& OnKeyHoldEvent() { return m_windowData.keyHoldEvent; };
	public:
		bool HasVsync();
		bool HasClosed();
	private:
		GLFWwindow* m_window;
		GLFWmonitor* m_monitor;
		WindowData m_windowData;
	};
}
