#include "TitleScene.h"
#include "../../Framework/Render/TextureManager.h"
#include "../../Framework/Render/Render.h"
#include "../../Framework/GameApp.h"

TitleScene::TitleScene()
	: _background(NULL)
{
}

void TitleScene::Enter()
{
	TextureManager &texman = TextureManager::GetInstance();
	_background = texman.GetTexture("data/images/background.png");
}

void TitleScene::Exit()
{
	TextureManager &texman = TextureManager::GetInstance();
	texman.ReleaseTexture(_background);
}

void TitleScene::Render()
{
	RenderEngine &r = RenderEngine::GetInstance();
	_background->Draw(Vertex(0, 0),
		Vertex(theApp->ScreenWidth(), theApp->ScreenHeight()));
}
