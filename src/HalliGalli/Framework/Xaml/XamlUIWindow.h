#ifndef __XAML_UI_WINDOW_H__
#define __XAML_UI_WINDOW_H__

#include "XamlUINode.h"

class XamlUIWindow : public XamlUINode
{
public:
	XamlUIWindow(const XamlWindow &window);

	XamlRect GetFrame() const;
	void SetFrame(const XamlRect &frame);

private:
	XamlUIWindow();

protected:
	XamlSize _designSize;
	XamlRect _frame;
};

#endif
