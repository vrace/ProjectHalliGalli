#ifndef __HALLI_GALLI_H__
#define __HALLI_GALLI_H__

#include "Framework/GameApp.h"
#include "Framework/Scene/SceneManager.h"

class HalliGalliGameApp : public GameApp
{
public:
	HalliGalliGameApp();

	virtual void Init();
	virtual void Exit();

	virtual void Suspend();
	virtual void Resume();

	virtual void Frame(float delta);

	virtual int ScreenWidth() const;
	virtual int ScreenHeight() const;

private:
	enum SceneID
	{
		sidTitle,
		sidTotal,
	};

private:
	SceneManager _sceneManager;

	Scene *_scenes[sidTotal];
};

#endif
