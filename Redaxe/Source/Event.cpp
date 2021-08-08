#include "Event.h"

namespace RDX
{
	void Event::Invoke()
	{
		for (auto callback : m_listeners)
		{
			callback();
		}
	}

	void Event::AddListener(std::function<void()> callback)
	{
		m_listeners.emplace_back(callback);
	}

	void Event::RemoveListeners() 
	{
		m_listeners.clear(); 
	}
}