#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "Scene.h"
#include <vector>

enum PushSceneMethod
{
	psmRender = 1,
	psmUpdate = 2,
	psmDefault = psmRender | psmUpdate
};

class SceneManager
{
public:
	SceneManager();

	void Update(float delta);
	void Render();

	void PushScene(Scene *scene);
	void PushScene(Scene *scene, PushSceneMethod method);

	void PopScene();

	void Suspend();
	void Resume();

private:
	SceneManager(const SceneManager&);
	SceneManager& operator =(const SceneManager&);

private:
	struct RunSceneData
	{
		Scene *scene;
		PushSceneMethod method;
	};

	enum SceneOperation
	{
		soPush,
		soPop,
	};

	struct SceneOp
	{
		SceneOperation op;
		union
		{
			RunSceneData push;
		};
	};

	typedef std::vector<RunSceneData> SceneStack;
	typedef std::vector<SceneOp> SceneOpArray;

private:
	void PushSceneImpl(Scene *scene, PushSceneMethod method);
	void PopSceneImpl();

private:
	SceneStack _sceneStack;
	SceneOpArray _sceneOps;
};

#endif
