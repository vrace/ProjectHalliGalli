#include "TitleScene.h"
#include "../HalliGalli.h"
#include "../Framework/Render/BitmapFont.h"

TitleScene::TitleScene()
	: XamlUIScene("TitleScene.xaml")
{
	font = new BitmapFont("data/fonts/futura-48.fnt");
}

TitleScene::~TitleScene()
{
	delete font;
}

void TitleScene::HandleXamlUIMessage(const XamlUIMessage &message)
{
	if (message.message == xmtButtonTouch)
	{
		HalliGalliGameApp *app = GetGameApp();
		SceneManager &sm = app->GetSceneManager();
		sm.PushScene(app->GetScene(sidMenu));
	}
}

void TitleScene::Render()
{
	XamlUIScene::Render();
	font->Draw(vec2(200, 200), "Halli Galli");
}
