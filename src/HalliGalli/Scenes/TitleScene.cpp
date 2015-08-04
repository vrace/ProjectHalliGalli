#include "TitleScene.h"
#include "../HalliGalli.h"

TitleScene::TitleScene()
	: XamlUIScene("TitleScene.xaml")
{
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
