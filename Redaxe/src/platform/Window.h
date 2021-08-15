#pragma once
#include "rdxpch.h"
#include "events/InputEvents.h"

namespace rdx
{
	struct WindowData
	{
		WindowData() : name("Redaxe Engine"), width(1280), height(720) {}
		const char* name;
		int width;
		int height;

		EventDispatcher dispatcher;
	};

	class Window
	{
	public:
		Window();
		~Window();
	public:
		void Open(const WindowData& data);
		void Bind();
		void Update();
		void Clear();
		void Swap();
		void Close();

		EventDispatcher& Dispatcher() { return m_windowData.dispatcher; };
	public:
		GLFWwindow* GetWindow() { return m_window; };
		bool HasClosed();
	private:
		GLFWwindow* m_window;
		WindowData m_windowData;
	};
}
