#include "SceneManager.h"

SceneManager::SceneManager()
	: _pop(0)
{
}

void SceneManager::Update(float delta)
{
	for (SceneStack::iterator it = _sceneStack.begin(); it != _sceneStack.end(); ++it)
	{
		if (it->method & psmUpdate)
			it->scene->Update(delta);
	}

	while (_pop > 0 && !_sceneStack.empty())
	{
		_pop--;
		_sceneStack.rbegin()->scene->Exit();
		_sceneStack.erase(_sceneStack.end() - 1);

		if (!_sceneStack.empty())
		{
			_sceneStack.rbegin()->method = psmDefault;
			_sceneStack.rbegin()->scene->Resume();
		}
	}

	_pop = 0;
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
	if (!_sceneStack.empty())
	{
		_sceneStack.rbegin()->scene->Suspend();
		_sceneStack.rbegin()->method = method;
	}

	RunSceneData run;
	run.scene = scene;
	run.method = psmDefault;
	_sceneStack.push_back(run);

	scene->Enter();
}

void SceneManager::PopScene()
{
	++_pop;
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
