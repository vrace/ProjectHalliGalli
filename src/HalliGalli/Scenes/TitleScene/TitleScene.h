#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "../../Framework/Scene/Scene.h"
#include "../../Framework/Render/Texture.h"

class TitleScene : public Scene
{
public:
	TitleScene();

	virtual void Enter();
	virtual void Exit();
	virtual void Render();

private:
	Texture *_background;
	Texture *_icon;
};

#endif
