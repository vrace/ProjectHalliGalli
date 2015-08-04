#ifndef __XAML_UI_SCENE_H__
#define __XAML_UI_SCENE_H__

#include "Scene.h"
#include "../Xaml/XamlUIWindow.h"
#include "../Xaml/XamlUIMessage.h"

class XamlUIScene
	: public Scene
	, public XamlUIMessageHandler
{
public:
	XamlUIScene(const std::string &xaml);

	virtual void Enter();
	virtual void Exit();
	virtual void Update(float delta);
	virtual void Render();
	virtual void HandleInput(const InputMessage &message);
	virtual void HandleXamlUIMessage(const XamlUIMessage &message);

private:
	std::string _xaml;
	XamlUIWindow *_window;
};

#endif
