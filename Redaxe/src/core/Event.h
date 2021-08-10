#pragma once
#include "rdxpch.h"

namespace rdx
{
	template <typename T>
	class Event
	{
	public:
		Event() {}
		virtual~Event() {}
	public:
		void Invoke(T params) 
		{
			for (std::function<void(T)>& callback : m_listeners)
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

	template <>
	class Event<void>
	{
	public:
		Event() {}
		virtual~Event() {}
	public:
		void Invoke()
		{
			for (std::function<void()>& callback : m_listeners)
			{
				callback();
			}
		}
		void AddListener(std::function<void()> callback)
		{
			m_listeners.emplace_back(callback);
		}
		void RemoveListeners()
		{
			m_listeners.clear();
		}
	private:
		std::list<std::function<void()>> m_listeners;
	};
}
