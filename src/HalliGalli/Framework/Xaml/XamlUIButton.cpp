#include "XamlUIButton.h"
#include <algorithm>

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

bool XamlUIButton::IsTouchInside(const InputMessage &message)
{
	vec2 v[4];

	v[0].x = -_size.width * _origin.x;
	v[0].y = -_size.height * _origin.y;

	v[1].x = -_size.width * _origin.x;
	v[1].y = _size.height * (1.0f - _origin.y);

	v[2].x = _size.width * (1.0f - _origin.x);
	v[2].y = _size.height * (1.0f - _origin.y);

	v[3].x = _size.width * (1.0f - _origin.x);
	v[3].y = -_size.height * _origin.y;

	for (int i = 0; i < 4; i++)
		v[i].ApplyTransform(XForm());

	vec2 touch((float)message.tap.x, (float)message.tap.y);

	for (int i = 0; i < 4; i++)
	{
		if (LinePointSide(v[i], v[(i + 1) % 4], touch) == vsLeft)
			return false;
	}

	return true;
}

bool XamlUIButton::HandleInput(const InputMessage &message)
{
	if (message.type == imtTap)
	{
		if (IsTouchInside(message))
		{
			printf("Touch inside!\n");
		}
	}

	return false;
}

void XamlUIButton::SetImage(XamlUIButtonStatus status, const std::string &image)
{
	ReleaseTexture(_images[status]);
	_images[status] = GetTexture(image);
}
