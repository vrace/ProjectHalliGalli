#ifndef __INPUT_MESSAGE_H__
#define __INPUT_MESSAGE_H__

enum TapEvent
{
	teUp,
	teDown,
};

struct InputMessageTap
{
	TapEvent tapEvent;
	int id;
	int x, y;
};

struct InputMessageKey
{
	char key;
};

enum InputMessageType
{
	imtInvalid,
	imtTap,
	imtKey,
};

struct InputMessage
{
	InputMessageType type;

	union
	{
		InputMessageTap tap;
		InputMessageKey key;
	};
};

#endif
