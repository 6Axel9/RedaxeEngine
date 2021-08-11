#pragma once
#include "rdxpch.h"

#define Action(x) std::function<void(x)>

namespace rdx
{
	struct EventData
	{
		virtual std::string ToString() = 0;
	};

	template <typename T>
	class Event
	{
	public:
		Event() {}
		virtual~Event() {}
	public:
		void Invoke(T params) 
		{
			spdlog::info("[Event]{0}", params.ToString());
			for (const Action(T)& callback : m_listeners)
			{
				callback(params);
			}
		}
		void AddListener(const Action(T)& callback) 
		{
			m_listeners.emplace_back(callback); 
		}
		void RemoveListeners() 
		{ 
			m_listeners.clear(); 
		}
	private:
		std::list<Action(T)> m_listeners;
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
			spdlog::info("[Event] [Base]");
			for (const Action()& callback : m_listeners)
			{
				callback();
			}
		}
		void AddListener(const Action()& callback)
		{
			m_listeners.emplace_back(callback);
		}
		void RemoveListeners()
		{
			m_listeners.clear();
		}
	private:
		std::list<Action()> m_listeners;
	};
}
