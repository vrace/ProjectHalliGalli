#include "HalliGalli.h"
#include "Framework/Render/Render.h"
#include "Framework/Render/Texture.h"
#include "Framework/Image/ImageData.h"

namespace
{
	Texture *texture;
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

	GLuint tex;

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.buffer());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	texture = new Texture(tex, image.width(), image.height());

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

	r.BindTexture(0);

	r.Triangle(
		RenderVertex(Vertex(1, 1, 0)),
		RenderVertex(Vertex(-1, 1, 0)),
		RenderVertex(Vertex(0, -1, 0)));

	r.Triangle(
		RenderVertex(Vertex(0, 1, 0), RenderColor(1, 0, 0)),
		RenderVertex(Vertex(1, -1, 0), RenderColor(0, 1, 0)),
		RenderVertex(Vertex(-1, -1, 0), RenderColor(0, 0, 1)));

	texture->Draw(Vertex(-0.5f, -0.5f), Vertex(0.5f, 0.5f));

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
