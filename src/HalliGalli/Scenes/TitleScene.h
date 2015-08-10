#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "../Framework/Scene/XamlUIScene.h"
#include "../Framework/Render/BitmapFont.h"

class TitleScene : public XamlUIScene
{
public:
	TitleScene();
	~TitleScene();

	virtual void HandleXamlUIMessage(const XamlUIMessage &message);
	virtual void Render();

private:
	BitmapFont *font;
};

#endif
