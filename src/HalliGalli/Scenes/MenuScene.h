#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "../Framework/Scene/XamlUIScene.h"

class MenuScene : public XamlUIScene
{
public:
	MenuScene();
	virtual void HandleXamlUIMessage(const XamlUIMessage &message);
};

#endif
