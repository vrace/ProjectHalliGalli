#ifndef __XAML_UI_BUTTON_H__
#define __XAML_UI_BUTTON_H__

#include "XamlTypes.h"
#include "XamlUINode.h"
#include "../Render/Texture.h"

class XamlUIButton : public XamlUINode
{
public:
	XamlUIButton(const XamlButton &button);
	virtual ~XamlUIButton();

	virtual void Update(float delta);
	virtual void Render();

	void SetImageNormal(const std::string &image);
	void SetImageDown(const std::string &image);
	void SetAnchor(const vec2 &origin);
	void SetSize(const XamlSize &size);

private:
	XamlSize _size;
	Texture *_imageNormal, *_imageDown;
};

#endif
