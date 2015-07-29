#include "XamlUIWindow.h"

XamlUIWindow::XamlUIWindow(const XamlWindow &window)
	: _designSize(window.size)
	, _frame(XamlPoint(), window.size)
{
}

XamlRect XamlUIWindow::GetFrame() const
{
	return _frame;
}

void XamlUIWindow::SetFrame(const XamlRect &frame)
{
	_frame = frame;
	
	mat44 translate = mat44::translate(
		(float)frame.origin.x,
		(float)frame.origin.y,
		0);

	mat44 scale = mat44::scale(
		(float)frame.size.width / _designSize.width,
		(float)frame.size.height / _designSize.height,
		1);

	_xform = scale * translate;
}
