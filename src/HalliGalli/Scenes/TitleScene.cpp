#include "TitleScene.h"
#include "../HalliGalli.h"
#include "../Framework/Render/BitmapFont.h"

TitleScene::TitleScene()
	: XamlUIScene("TitleScene.xaml")
{
	BitmapFont font("data/fonts/futura-48.fnt");
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
