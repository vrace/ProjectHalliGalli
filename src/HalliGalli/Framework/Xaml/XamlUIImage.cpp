#include "XamlUIImage.h"
#include "../Render/Render.h"

XamlUIImage::XamlUIImage(const XamlImage &image)
	: XamlUIDrawable(image)
	, _texture(NULL)
{
	SetImage(image.source);
}

XamlUIImage::~XamlUIImage()
{
	ReleaseTexture(_texture);
}

void XamlUIImage::Render()
{
	Draw(_texture);
	XamlUINode::Render();
}

void XamlUIImage::SetImage(const std::string &image)
{
	ReleaseTexture(_texture);
	_texture = GetTexture(image);
}
