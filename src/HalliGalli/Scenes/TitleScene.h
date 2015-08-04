#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "../Framework/Scene/XamlUIScene.h"

class TitleScene : public XamlUIScene
{
public:
	TitleScene();
	virtual void HandleXamlUIMessage(const XamlUIMessage &message);
};

#endif
