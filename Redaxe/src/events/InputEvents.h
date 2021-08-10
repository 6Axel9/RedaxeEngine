#pragma once
#include "rdxpch.h"
#include "Event.h"

#define KEY_DOWN(key)	KeyEvent(key), source(InputSource::Keyboard), state(KeyState::Down)
#define KEY_UP(key)		KeyEvent(key), source(InputSource::Keyboard), state(KeyState::Up)
#define KEY_HOLD(key)	KeyEvent(key), source(InputSource::Keyboard), state(KeyState::Hold)

#define MOUSE_DOWN(key)	KeyEvent(key), source(InputSource::Mouse), state(KeyState::Down)
#define MOUSE_UP(key)	KeyEvent(key), source(InputSource::Mouse), state(KeyState::Up)
#define MOUSE_HOLD(key)	KeyEvent(key), source(InputSource::Mouse), state(KeyState::Hold)

#define MOUSE_MOVED(x, y) source(InputSource::Mouse), x(x), y(y)

namespace rdx
{
	enum class InputSource { Keyboard, Mouse };
	enum class KeyState { Down, Up, Hold };

	struct KeyEvent : EventData
	{
		KeyEvent(int key) : key(key) {}
		int key;
	};

	struct KeyDownData : KeyEvent
	{
		KeyDownData(int key) : KEY_DOWN(key) {}
		InputSource source;
		KeyState state;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Keyboard][Key " << key << " was down]";
			return ss.str();
		}
	};

	struct KeyUpData : KeyEvent
	{
		KeyUpData(int key) : KEY_UP(key) {}
		InputSource source;
		KeyState state;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Keyboard][Key " << key << " was up]";
			return ss.str();
		}
	};

	struct KeyHoldData : KeyEvent
	{
		KeyHoldData(int key) : KEY_HOLD(key) {}
		InputSource source;
		KeyState state;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Keyboard][Key " << key << " was in hold]";
			return ss.str();
		}
	};

	struct MouseDownData : KeyEvent
	{
		MouseDownData(int key) : MOUSE_DOWN(key) {}
		InputSource source;
		KeyState state;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Mouse][Key " << key << " was down]";
			return ss.str();
		}
	};

	struct MouseUpData : KeyEvent
	{
		MouseUpData(int key) : MOUSE_UP(key) {}
		InputSource source;
		KeyState state;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Mouse][Key " << key << " was up]";
			return ss.str();
		}
	};

	struct MouseHoldData : KeyEvent
	{
		MouseHoldData(int key) : MOUSE_HOLD(key) {}
		InputSource source;
		KeyState state;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Mouse][Key " << key << " was in hold]";
			return ss.str();
		}
	};

	struct MouseMovedData : EventData 
	{
		MouseMovedData(int x, int y) : MOUSE_MOVED(x, y) {}
		InputSource source;
		int x, y;

		std::string ToString() override
		{
			std::stringstream ss;
			ss << "[Mouse][Moved to x:" << x << " y:" << y << "]";
			return ss.str();
		}
	};
}
