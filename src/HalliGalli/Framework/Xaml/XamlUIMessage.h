#ifndef __XAML_UI_MESSAGE_H__
#define __XAML_UI_MESSAGE_H__

#include <string>

enum XamlUIMessageType
{
	xmtButtonTouch
};

struct XamlUIMessage
{
	std::string name;
	XamlUIMessageType message;
};

class XamlUIMessageHandler
{
public:
	XamlUIMessageHandler();
	virtual ~XamlUIMessageHandler();

	virtual void HandleXamlUIMessage(const XamlUIMessage &message) = 0;
};

#endif
