#include "XamlUIScene.h"
#include "../Xaml/XamlUILoader.h"

XamlUIScene::XamlUIScene(const std::string &xaml)
	: _xaml(xaml)
	, _window(NULL)
{
}

void XamlUIScene::Enter()
{
	XamlUILoader loader(_xaml);
	
	XamlUINode *root = loader.CreateNodes();
	_window = dynamic_cast<XamlUIWindow*>(root);
	
	if (_window)
	{
		_window->SetXamlUIMessageHandler(this);
	}
	else
	{
		root->RemoveFromParent();
	}
}

void XamlUIScene::Exit()
{
	if (_window)
		_window->RemoveFromParent();
}

void XamlUIScene::Update(float delta)
{
	if (_window)
		_window->Update(delta);
}

void XamlUIScene::Render()
{
	if (_window)
		_window->Render();
}

void XamlUIScene::HandleInput(const InputMessage &message)
{
	if (_window)
		_window->HandleInput(message);
}

void XamlUIScene::HandleXamlUIMessage(const XamlUIMessage &message)
{
}
