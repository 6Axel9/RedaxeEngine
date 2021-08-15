#pragma once
#include "Window.h"

namespace rdx
{
	class Interface
	{
	public:
		Interface();
		~Interface();
	public:
		void Open(Window* window);
		void Bind();
		void Update();
		void Close();
	private:
		const char* m_glslVersion;
		bool m_isSubOpen;
		bool m_isOpen;

		Window* m_window;
		ImGuiIO* m_io;
	};
}