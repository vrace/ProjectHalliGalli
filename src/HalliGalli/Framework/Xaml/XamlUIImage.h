#ifndef __XAML_UI_IMAGE_H__
#define __XAML_UI_IMAGE_H__

#include "XamlUINode.h"
#include "../Render/Texture.h"

class XamlUIImage : public XamlUINode
{
public:
	XamlUIImage(const XamlImage &image);
	virtual ~XamlUIImage();

	virtual void Render();

	void SetImage(const std::string &image);
	void SetAnchor(const vec2 &origin);
	void SetSize(const XamlSize &size);

private:
	XamlUIImage();

private:
	XamlSize _size;
	Texture *_texture;
};

#endif
