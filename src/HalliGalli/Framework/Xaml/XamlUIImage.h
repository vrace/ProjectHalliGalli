#ifndef __XAML_UI_IMAGE_H__
#define __XAML_UI_IMAGE_H__

#include "XamlUIDrawable.h"
#include "../Render/Texture.h"

class XamlUIImage : public XamlUIDrawable
{
public:
	XamlUIImage(const XamlImage &image);
	virtual ~XamlUIImage();

	virtual void Render();
	void SetImage(const std::string &image);

private:
	Texture *_texture;
};

#endif
