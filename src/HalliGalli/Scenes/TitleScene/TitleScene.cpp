#include "TitleScene.h"
#include "../../Framework/Render/TextureManager.h"
#include "../../Framework/Render/Render.h"
#include "../../Framework/GameApp.h"
#include "../../Framework/Math/Matrix44.h"
#include "../../Framework/Xaml/XamlUILoader.h"

TitleScene::TitleScene()
	: _background(NULL)
{
}

void TitleScene::Enter()
{
	TextureManager &texman = TextureManager::GetInstance();
	_background = texman.GetTexture("data/images/background.png");
	_icon = texman.GetTexture("data/images/button_gallery.png");

	XamlUILoader xaml("data/ui/TitleScene.xaml");
	xaml.CreateNodes();
}

void TitleScene::Exit()
{
	TextureManager &texman = TextureManager::GetInstance();
	texman.ReleaseTexture(_background);
	texman.ReleaseTexture(_icon);
}

void TitleScene::Render()
{
	RenderEngine &r = RenderEngine::GetInstance();
	_background->Draw(Vertex(0, 0),
		Vertex(theApp->ScreenWidth(), theApp->ScreenHeight()));

	_icon->Draw(Vertex(30, 30),
		Vertex(100, 100));

	r.SubmitBatch();

	mat44 translate = mat44::translate(50, 50, 0);
	mat44 scale = mat44::scale(3, 2, 1);

	mat44 mat = scale * translate;
	glLoadMatrixf(mat.xform);

	glDisable(GL_TEXTURE_2D);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0); glVertex3f(100, 200, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 100, 0);
	glColor3f(0, 0, 1); glVertex3f(200, 100, 0);
	glEnd();
	glEnable(GL_TEXTURE_2D);

	mat = translate * scale;
	glLoadMatrixf(mat.xform);

	glDisable(GL_TEXTURE_2D);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0); glVertex3f(100, 200, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 100, 0);
	glColor3f(0, 0, 1); glVertex3f(200, 100, 0);
	glEnd();
	glEnable(GL_TEXTURE_2D);
}
