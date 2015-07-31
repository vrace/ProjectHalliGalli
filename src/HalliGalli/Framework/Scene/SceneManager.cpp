#include "SceneManager.h"
#include "../Input/InputManager.h"

SceneManager::SceneManager()
{
}

void SceneManager::Update(float delta)
{
	for (SceneOpArray::iterator it = _sceneOps.begin(); it != _sceneOps.end(); ++it)
	{
		switch (it->op)
		{
		case soPush:
			PushSceneImpl(it->push.scene, it->push.method);
			break;

		case soPop:
			PopSceneImpl();
			break;

		default:
			break;
		}
	}

	_sceneOps.clear();

	for (SceneStack::iterator it = _sceneStack.begin(); it != _sceneStack.end(); ++it)
	{
		if (it->method & psmUpdate)
			it->scene->Update(delta);
	}

	Scene *topScene = NULL;
	if (!_sceneStack.empty())
		topScene = _sceneStack.rbegin()->scene;

	InputMessage input;
	InputManager &inputManager = InputManager::GetInstance();
	
	while (inputManager.NextMessage(input))
	{
		if (topScene)
			topScene->HandleInput(input);
	}
}

void SceneManager::Render()
{
	for (SceneStack::iterator it = _sceneStack.begin(); it != _sceneStack.end(); ++it)
	{
		if (it->method & psmRender)
			it->scene->Render();
	}
}

void SceneManager::PushScene(Scene *scene)
{
	PushScene(scene, psmDefault);
}

void SceneManager::PushScene(Scene *scene, PushSceneMethod method)
{
	SceneOp op;

	op.op = soPush;
	op.push.method = method;
	op.push.scene = scene;

	_sceneOps.push_back(op);
}

void SceneManager::PopScene()
{
	SceneOp op;
	op.op = soPop;
	_sceneOps.push_back(op);
}

void SceneManager::PushSceneImpl(Scene *scene, PushSceneMethod method)
{
	if (!_sceneStack.empty())
	{
		_sceneStack.rbegin()->method = method;
		_sceneStack.rbegin()->scene->Suspend();
	}

	RunSceneData data;
	data.method = psmDefault;
	data.scene = scene;

	_sceneStack.push_back(data);

	scene->Enter();
}

void SceneManager::PopSceneImpl()
{
	if (!_sceneStack.empty())
	{
		_sceneStack.rbegin()->scene->Exit();
		_sceneStack.erase(_sceneStack.end() - 1);
	}

	if (!_sceneStack.empty())
	{
		_sceneStack.rbegin()->method = psmDefault;
		_sceneStack.rbegin()->scene->Resume();
	}
}

void SceneManager::Suspend()
{
	if (!_sceneStack.empty())
		_sceneStack.rbegin()->scene->Suspend();
}

void SceneManager::Resume()
{
	if (!_sceneStack.empty())
		_sceneStack.rbegin()->scene->Resume();
}
