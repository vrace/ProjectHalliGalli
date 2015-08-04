#include "HalliGalli.h"
#include "Framework/Render/Render.h"
#include "Framework/Render/TextureManager.h"

#include "Scenes/TitleScene.h"
#include "Scenes/MenuScene.h"

HalliGalliGameApp* GetGameApp(void)
{
	return (HalliGalliGameApp*)theApp;
}

GameApp* GameAppCreate()
{
	return new HalliGalliGameApp();
}

void GameAppDestroy(GameApp *app)
{
	delete app;
}

HalliGalliGameApp::HalliGalliGameApp()
{
}

void HalliGalliGameApp::Init()
{
	TextureManager::InitInstance();


	_scenes[sidTitle] = new TitleScene();
	_scenes[sidMenu] = new MenuScene();

	_sceneManager.PushScene(_scenes[sidTitle]);
}

void HalliGalliGameApp::Exit()
{
	for (int i = 0; i < sidTotal; i++)
		delete _scenes[i];

	TextureManager::DeleteInstance();
}

void HalliGalliGameApp::Suspend()
{
	_sceneManager.Suspend();
}

void HalliGalliGameApp::Resume()
{
	_sceneManager.Resume();
}

void HalliGalliGameApp::Frame(float delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, ScreenWidth(), ScreenHeight(), 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	_sceneManager.Update(delta);
	_sceneManager.Render();

	Render::GetInstance().SubmitBatch();
}

int HalliGalliGameApp::ScreenWidth() const
{
	return 960;
}

int HalliGalliGameApp::ScreenHeight() const
{
	return 640;
}

SceneManager& HalliGalliGameApp::GetSceneManager()
{
	return _sceneManager;
}

Scene* HalliGalliGameApp::GetScene(SceneID id)
{
	return _scenes[id];
}
