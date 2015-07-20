#include "XamlUIWindow.h"

XamlUIWindow::XamlUIWindow(const XamlSize &size)
	: _size(size)
{
	_origin.x = 0;
	_origin.y = 0;
}

XamlRect XamlUIWindow::GetFrame() const
{
	XamlRect frame;

	frame.origin.x = (int)_transform.translate.x;
	frame.origin.y = (int)_transform.translate.y;
	frame.size.width = (int)(_size.width * _transform.scale.x);
	frame.size.height = (int)(_size.height * _transform.scale.y);

	return frame;
}

void XamlUIWindow::SetFrame(const XamlRect &frame)
{
	_transform.translate.x = (float)frame.origin.x;
	_transform.translate.y = (float)frame.origin.y;
	_transform.scale.x = (float)frame.size.width / _size.width;
	_transform.scale.y = (float)frame.size.height / _size.height;
}
