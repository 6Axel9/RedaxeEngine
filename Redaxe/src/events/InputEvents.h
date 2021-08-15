#pragma once
#include "rdxpch.h"
#include "Event.h"

#define Event_Type(x) EventType GetType() override { return x; }

namespace rdx
{
	struct KeyEvent : EventData
	{
		KeyEvent() : key(0) {}
		int key;
	};

	struct MouseEvent : EventData
	{
		MouseEvent() : scrollX(0), scrollY(0), posX(0), posY(0), button(0) {}
		double scrollX, scrollY;
		double posX, posY;
		int button;
	};

	struct KeyDownData : KeyEvent
	{
		KeyDownData(int key) { this->key = key; }
		Event_Type(EventType::KeyDown)
	};

	struct KeyUpData : KeyEvent
	{
		KeyUpData(int key) { this->key = key; }
		Event_Type(EventType::KeyUp)
	};

	struct KeyHoldData : KeyEvent
	{
		KeyHoldData(int key) { this->key = key; }
		Event_Type(EventType::KeyHold)
	};

	struct MouseDownData : MouseEvent
	{
		MouseDownData(int button) { this->button = button; }
		Event_Type(EventType::MouseDown)
	};

	struct MouseUpData : MouseEvent
	{
		MouseUpData(int button) { this->button = button; }
		Event_Type(EventType::MouseUp)
	};

	struct MouseHoldData : MouseEvent
	{
		MouseHoldData(int button) { this->button = button; }
		Event_Type(EventType::MouseHold)
	};

	struct MouseScrollData : MouseEvent
	{
		MouseScrollData(double scrollX, double scrollY)
		{
			this->scrollX = scrollX;
			this->scrollY = scrollY;
		}
		Event_Type(EventType::MouseScroll)
	};

	struct MouseMoveData : MouseEvent
	{
		MouseMoveData(double posX, double posY)
		{
			this->posX = posX;
			this->posY = posY;
		}
		Event_Type(EventType::MouseMove)
	};
}
