#include "TitleScene.h"
#include "../../Framework/Render/TextureManager.h"
#include "../../Framework/Render/Render.h"

TitleScene::TitleScene()
	: _texture(NULL)
{
}

void TitleScene::Enter()
{
	TextureManager &texman = TextureManager::GetInstance();
	_texture = texman.GetTexture("data/images/button_gallery.png");
}

void TitleScene::Exit()
{
	TextureManager &texman = TextureManager::GetInstance();
	texman.ReleaseTexture(_texture);
}

void TitleScene::Render()
{
	RenderEngine &r = RenderEngine::GetInstance();

	r.BindTexture(0);

	r.Triangle(
		RenderVertex(Vertex(100, 100, 0)),
		RenderVertex(Vertex(500, 100, 0)),
		RenderVertex(Vertex(300, 500, 0)));

	r.Triangle(
		RenderVertex(Vertex(100, 500, 0), RenderColor(1, 0, 0)),
		RenderVertex(Vertex(500, 500, 0), RenderColor(0, 1, 0)),
		RenderVertex(Vertex(300, 100, 0), RenderColor(0, 0, 1)));

	_texture->Draw(Vertex(350, 350));
	_texture->Draw(Vertex(200, 200), Vertex(300, 300));
}
