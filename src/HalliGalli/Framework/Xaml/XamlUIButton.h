#ifndef __XAML_UI_BUTTON_H__
#define __XAML_UI_BUTTON_H__

#include "XamlTypes.h"
#include "XamlUIDrawable.h"
#include "../Render/Texture.h"

enum XamlUIButtonStatus
{
	bsNormal,
	bsDown,
	bsNumStatus,
};

class XamlUIButton : public XamlUIDrawable
{
public:
	XamlUIButton(const XamlButton &button);
	virtual ~XamlUIButton();

	virtual void Update(float delta);
	virtual void Render();
	virtual bool HandleInput(const InputMessage &message);

	void SetImage(XamlUIButtonStatus status, const std::string &image);

private:
	bool IsTouchInside(const InputMessage &message);

private:
	Texture *_images[bsNumStatus];
	XamlUIButtonStatus _status;
};

#endif
