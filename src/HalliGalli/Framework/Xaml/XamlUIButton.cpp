#include "XamlUIButton.h"

XamlUIButton::XamlUIButton(const XamlButton &button)
	: XamlUIDrawable(button)
	, _status(bsNormal)
{
	for (int i = 0; i < bsNumStatus; _images[i++] = NULL);

	SetImage(bsNormal, button.imageNormal);
	SetImage(bsDown, button.imageDown);
}

XamlUIButton::~XamlUIButton()
{
	for (int i = 0; i < bsNumStatus; ReleaseTexture(_images[i++]));
}

void XamlUIButton::Update(float delta)
{
	XamlUIDrawable::Update(delta);
}

void XamlUIButton::Render()
{
	Draw(_images[_status]);
	XamlUIDrawable::Render();
}

void XamlUIButton::SetImage(XamlUIButtonStatus status, const std::string &image)
{
	ReleaseTexture(_images[status]);
	_images[status] = GetTexture(image);
}
