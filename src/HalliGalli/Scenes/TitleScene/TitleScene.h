#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "../../Framework/Scene/Scene.h"

class XamlUINode;

class TitleScene : public Scene
{
public:
	TitleScene();

	virtual void Enter();
	virtual void Exit();
	virtual void Update(float delta);
	virtual void Render();

private:
	XamlUINode *_ui;
};

#endif
