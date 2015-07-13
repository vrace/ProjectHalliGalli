#ifndef __SCENE_H__
#define __SCENE_H__

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
};

#endif
