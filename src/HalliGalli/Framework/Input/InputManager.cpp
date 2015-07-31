#include "InputManager.h"

InputManager InputManager::_instance;

InputManager::InputManager()
{
}

InputManager& InputManager::GetInstance()
{
	return _instance;
}

void InputManager::PushInput(const InputMessage &inputMessage)
{
	_inputMessages.push_back(inputMessage);
}

bool InputManager::NextMessage(InputMessage &inputMessage)
{
	if (!_inputMessages.empty())
	{
		inputMessage = _inputMessages.front();
		_inputMessages.pop_front();
		return true;
	}

	return false;
}

void InputManager::PushTapInput(TapEvent tapEvent, int id, int x, int y)
{
	InputMessage message;
	
	message.type = imtTap;
	message.tap.tapEvent = tapEvent;
	message.tap.id = id;
	message.tap.x = x;
	message.tap.y = y;

	PushInput(message);
}
