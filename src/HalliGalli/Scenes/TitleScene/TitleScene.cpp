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
	// TODO: Handle input

	static const char *tapState[] =
	{
		"Up", "Down", "Move"
	};

	switch (message.type)
	{
	case imtTap:
		printf("Tap: %s [%d, %d]\n", tapState[message.tap.tapEvent],
			message.tap.x, message.tap.y);
		break;

	case imtKey:
		printf("Key: %c\n", message.key.key);
		break;

	default:
		break;
	}

	if (_ui)
		_ui->HandleInput(message);
}
