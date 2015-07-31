#ifndef __SCENE_H__
#define __SCENE_H__

#include "../Input/InputMessage.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Enter();
	virtual void Exit();
	virtual void Suspend();
	virtual void Resume();
	virtual void Update(float delta);
	virtual void Render();
	virtual void HandleInput(const InputMessage &message);
};

#endif
