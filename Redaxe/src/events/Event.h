#pragma once
#include "rdxpch.h"

#define Func(x) std::function<void(x)>

namespace rdx
{
	enum class EventType {	KeyDown, KeyUp, KeyHold,
							MouseDown, MouseUp, MouseHold, MouseMove, MouseScroll,
							WindowOpened, WindowCloseed, WindowMoved, WindowResized, 
							SceneStarted, SceneStopped,
							Error = -1};

	struct EventData
	{
		virtual EventType GetType() { return EventType::Error; }
	};

	class Event
	{
	public:
		Event(EventType type, Func(EventData&) method) : method(method), type(type) {}
		~Event() = default;
	public:
		Func(EventData&) GetMethod() { return method; }
		EventType GetType() { return type; }
	private:
		Func(EventData&) method;
		EventType type;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher() = default;
		~EventDispatcher() = default;
	public:
		void Invoke(EventData& params)
		{
			for (Event& callback : m_listeners)
				if (params.GetType() == callback.GetType())
					callback.GetMethod()(params);
				else
					continue;
		}
		void AddListener(const Event& callback)
		{
			m_listeners.emplace_back(callback); 
		}
		void RemoveListeners() 
		{ 
			m_listeners.clear(); 
		}
	private:
		std::list<Event> m_listeners;
	};
}
