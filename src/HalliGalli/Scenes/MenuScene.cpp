#include "MenuScene.h"
#include "../HalliGalli.h"

MenuScene::MenuScene()
	: XamlUIScene("MenuScene.xaml")
{
}

void MenuScene::HandleXamlUIMessage(const XamlUIMessage &message)
{
	if (message.message == xmtButtonTouch)
	{
		if (message.name == "ExitButton")
		{
			GetGameApp()->GetSceneManager().PopScene();
		}
	}
}
