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
