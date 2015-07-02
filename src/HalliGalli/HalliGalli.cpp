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

	glColor3f(1, 1, 1);
	Render::GetInstance().Triangle(Vertex(1, 1, 0), Vertex(-1, 1, 0), Vertex(0, -1, 0));

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0); glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0); glVertex3f(1, -1, 0);
	glColor3f(0, 0, 1); glVertex3f(-1, -1, 0);
	glEnd();
}

int HalliGalliGameApp::ScreenWidth() const
{
	return 960;
}

int HalliGalliGameApp::ScreenHeight() const
{
	return 640;
}
