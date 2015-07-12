#include "HalliGalli.h"
#include "Framework/Render/Render.h"
#include "Framework/Render/Texture.h"
#include "Framework/Render/TextureManager.h"
#include "Framework/Image/ImageData.h"

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

	// cache image for use...
	TextureManager &texman = TextureManager::GetInstance();
	texman.GetTexture("data/images/button_gallery.png");
}

void HalliGalliGameApp::Exit()
{
	TextureManager::DeleteInstance();
}

void HalliGalliGameApp::Suspend()
{
}

void HalliGalliGameApp::Resume()
{
}

void HalliGalliGameApp::Frame(float delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, ScreenWidth(), 0, ScreenHeight(), -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Render &r = Render::GetInstance();

	r.BindTexture(0);

	r.Triangle(
		RenderVertex(Vertex(100, 100, 0)),
		RenderVertex(Vertex(500, 100, 0)),
		RenderVertex(Vertex(300, 500, 0)));

	r.Triangle(
		RenderVertex(Vertex(100, 500, 0), RenderColor(1, 0, 0)),
		RenderVertex(Vertex(500, 500, 0), RenderColor(0, 1, 0)),
		RenderVertex(Vertex(300, 100, 0), RenderColor(0, 0, 1)));

	TextureManager &texman = TextureManager::GetInstance();
	Texture *texture = texman.GetTexture("data/images/button_gallery.png");

	texture->Draw(Vertex(350, 350));
	texture->Draw(Vertex(200, 200), Vertex(300, 300));

	texman.ReleaseTexture(texture);

	r.SubmitBatch();
}

int HalliGalliGameApp::ScreenWidth() const
{
	return 960;
}

int HalliGalliGameApp::ScreenHeight() const
{
	return 640;
}
