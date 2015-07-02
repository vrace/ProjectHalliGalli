#include "HalliGalli.h"
#include "Framework/Render/Render.h"

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
}

void HalliGalliGameApp::Exit()
{
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

	Render &r = Render::GetInstance();

	r.Triangle(
		RenderVertex(Vertex(1, 1, 0)),
		RenderVertex(Vertex(-1, 1, 0)),
		RenderVertex(Vertex(0, -1, 0)));

	r.Triangle(
		RenderVertex(Vertex(0, 1, 0), RenderColor(1, 0, 0)),
		RenderVertex(Vertex(1, -1, 0), RenderColor(0, 1, 0)),
		RenderVertex(Vertex(-1, -1, 0), RenderColor(0, 0, 1)));

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
