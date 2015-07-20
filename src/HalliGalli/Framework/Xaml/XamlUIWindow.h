#ifndef __XAML_UI_WINDOW_H__
#define __XAML_UI_WINDOW_H__

#include "XamlUINode.h"

class XamlUIWindow : public XamlUINode
{
public:
	XamlUIWindow(const XamlSize &size);

	XamlRect GetFrame() const;
	void SetFrame(const XamlRect &frame);

protected:
	XamlSize _size;
};

#endif
