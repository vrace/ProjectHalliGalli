#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "../Framework/Scene/Scene.h"
#include "../Framework/Xaml/XamlUIMessage.h"

class XamlUINode;

class MenuScene
	: public Scene
	, public XamlUIMessageHandler
{
public:
	MenuScene();

	virtual void Enter();
	virtual void Exit();
	virtual void Update(float delta);
	virtual void Render();
	virtual void HandleInput(const InputMessage &message);
	virtual void HandleXamlUIMessage(const XamlUIMessage &message);

private:
	XamlUINode *_ui;
};

#endif
