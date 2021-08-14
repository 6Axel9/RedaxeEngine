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
		MouseEvent() : deltaX(0), deltaY(0), scroll(0), x(0), y(0), key(0) {}
		int deltaX;
		int deltaY;
		int scroll;
		int x, y;
		int key;
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
		MouseDownData(int key) { this->key = key; }
		Event_Type(EventType::MouseDown)
	};

	struct MouseUpData : MouseEvent
	{
		MouseUpData(int key) { this->key = key; }
		Event_Type(EventType::MouseUp)
	};

	struct MouseHoldData : MouseEvent
	{
		MouseHoldData(int key) { this->key = key; }
		Event_Type(EventType::MouseHold)
	};

	struct MouseScrollData : MouseEvent
	{
		MouseScrollData(int scroll) { this->scroll = scroll; }
		Event_Type(EventType::MouseScroll)
	};

	struct MouseMoveData : MouseEvent
	{
		MouseMoveData(int deltaX, int deltaY, int x, int y)
		{
			this->deltaX = deltaX;
			this->deltaY = deltaY;
			this->x = x;
			this->y = y;
		}
		Event_Type(EventType::MouseMove)
	};
}
