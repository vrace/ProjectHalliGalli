#include "TitleScene.h"
#include "../../Framework/GameApp.h"
#include "../../Framework/Render/Render.h"
#include "../../Framework/Xaml/XamlUILoader.h"
#include "../../Framework/Xaml/XamlUINode.h"

TitleScene::TitleScene()
{
}

void TitleScene::Enter()
{
	XamlUILoader xaml("TitleScene.xaml");
	_ui = xaml.CreateNodes();
	_ui->SetXamlUIMessageHandler(this);
}

void TitleScene::Exit()
{
	if (_ui)
		_ui->RemoveFromParent();
}

void TitleScene::Update(float delta)
{
	if (_ui)
		_ui->Update(delta);
}

void TitleScene::Render()
{
	if (_ui)
		_ui->Render();
}

void TitleScene::HandleInput(const InputMessage &message)
{
	if (_ui)
		_ui->HandleInput(message);
}

void TitleScene::HandleXamlUIMessage(const XamlUIMessage &message)
{
	if (message.message == xmtButtonTouch)
	{
		printf("[%s] Touch up inside.\n", message.name.c_str());
	}
}
