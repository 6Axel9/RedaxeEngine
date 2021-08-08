#pragma once
#include "Core.h"

#include <functional>
#include <list>
#include <iostream>

namespace RDX
{
	struct RDX_API EventParams
	{
	};

	class RDX_API Event
	{
	public:
		Event() {}
		virtual~Event() {}
	public:
		void Invoke();
		void AddListener(std::function<void()> callback);
		void RemoveListeners();
	private:
		std::list<std::function<void()>> m_listeners;
	};

	template <typename T>
	class CustomEvent
	{
	public:
		CustomEvent() {}
		virtual~CustomEvent() {}
	public:
		void Invoke(T params) 
		{
			for (auto callback : m_listeners)
			{
				callback(params);
			}
		}
		void AddListener(std::function<void(T)> callback) 
		{
			m_listeners.emplace_back(callback); 
		}
		void RemoveListeners() 
		{ 
			m_listeners.clear(); 
		}
	private:
		std::list<std::function<void(T)>> m_listeners;
	};
}
