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
