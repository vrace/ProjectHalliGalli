#include "HalliGalli.h"
#include "Framework/Render/Render.h"
#include "Framework/Image/ImageData.h"

namespace
{
	GLuint texture;
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
	ImageData image;
	image.Load("data/images/button_gallery.png");

	ImageData another;
	another.Load("data/images/card_cover.png");

	// let's try some texture...

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.buffer());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	PrintRenderErrors();
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

	glDisable(GL_TEXTURE_2D);

	r.Triangle(
		RenderVertex(Vertex(1, 1, 0)),
		RenderVertex(Vertex(-1, 1, 0)),
		RenderVertex(Vertex(0, -1, 0)));

	r.Triangle(
		RenderVertex(Vertex(0, 1, 0), RenderColor(1, 0, 0)),
		RenderVertex(Vertex(1, -1, 0), RenderColor(0, 1, 0)),
		RenderVertex(Vertex(-1, -1, 0), RenderColor(0, 0, 1)));

	r.SubmitBatch();

	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.5, 0); glVertex3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(1, 1); glVertex3f(0.5, -0.5, 0);
	glTexCoord2f(0, 1); glVertex3f(-0.5, -0.5, 0);
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
