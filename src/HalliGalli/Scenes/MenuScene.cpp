#include "MenuScene.h"
#include "../Framework/GameApp.h"
#include "../Framework/Xaml/XamlUILoader.h"
#include "../Framework/Xaml/XamlUINode.h"
#include "../Framework/Xaml/XamlUIWindow.h"

MenuScene::MenuScene()
{
}

void MenuScene::Enter()
{
	XamlUILoader loader("MenuScene.xaml");
	_ui = loader.CreateNodes();
	_ui->SetXamlUIMessageHandler(this);
}

void MenuScene::Exit()
{
	if (_ui)
		_ui->RemoveFromParent();
}

void MenuScene::Update(float delta)
{
	if (_ui)
		_ui->Update(delta);
}

void MenuScene::Render()
{
	if (_ui)
		_ui->Render();
}

void MenuScene::HandleInput(const InputMessage &message)
{
	if (_ui)
		_ui->HandleInput(message);
}

void MenuScene::HandleXamlUIMessage(const XamlUIMessage &message)
{
}
