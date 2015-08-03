#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "../../Framework/Scene/Scene.h"
#include "../../Framework/Xaml/XamlUIMessage.h"

class XamlUINode;

class TitleScene
	: public Scene
	, public XamlUIMessageHandler
{
public:
	TitleScene();

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
