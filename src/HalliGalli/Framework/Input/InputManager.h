#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "InputMessage.h"
#include <deque>

class InputManager
{
public:
	static InputManager& GetInstance();

	void PushInput(const InputMessage &inputMessage);
	bool NextMessage(InputMessage &inputMessage);

	void PushTapInput(TapEvent tapEvent, int id, int x, int y);

private:
	InputManager();
	InputManager(const InputManager&);
	InputManager& operator =(const InputManager&);

private:
	static InputManager _instance;
	typedef std::deque<InputMessage> InputMessageQueue;
	InputMessageQueue _inputMessages;
};

#endif
