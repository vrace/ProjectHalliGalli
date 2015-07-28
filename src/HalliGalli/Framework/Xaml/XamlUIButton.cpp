#include "XamlUIButton.h"

XamlUIButton::XamlUIButton(const XamlButton &button)
{
}

XamlUIButton::~XamlUIButton()
{
}

void XamlUIButton::Update(float delta)
{
	XamlUINode::Update(delta);
}

void XamlUIButton::Render()
{
	XamlUINode::Render();
}

void XamlUIButton::SetImageNormal(const std::string &image)
{
}

void XamlUIButton::SetImageDown(const std::string &image)
{
}

void XamlUIButton::SetAnchor(const vec2 &origin)
{
}

void XamlUIButton::SetSize(const XamlSize &size)
{
}
