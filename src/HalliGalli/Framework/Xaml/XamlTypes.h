#ifndef __XAML_TYPES_H__
#define __XAML_TYPES_H__

#include "../Math/Vector2.h"
#include <string>

class XamlTransformOrigin : public vector2f
{
public:
	XamlTransformOrigin()
		: vector2f(0.5f, 0.5f)
	{
	}
};

class XamlScaleTransform : public vector2f
{
public:
	XamlScaleTransform()
		: vector2f(1, 1)
	{
	}
};

class XamlRotateTransform
{
public:
	XamlRotateTransform()
		: angle(0)
	{
	}

	float angle;
};

typedef vector2f XamlTranslateTransform;

class XamlTransformGroup
{
public:
	XamlScaleTransform scale;
	XamlRotateTransform rotate;
	XamlTranslateTransform translate;
};

class XamlSize
{
public:
	int width;
	int height;

	XamlSize()
		: width(0)
		, height(0)
	{
	}

	XamlSize(int w, int h)
		: width(w)
		, height(h)
	{
	}
};

enum XamlNodeType
{
	xntWindow,
	xntImage,
};

class XamlNode
{
public:
	XamlNode(XamlNodeType nodeType)
		: type(nodeType)
	{
	}

	XamlNodeType type;
};

class XamlWindow : XamlNode
{
public:
	XamlWindow()
		: XamlNode(xntWindow)
	{
	}

	XamlSize size;
};

class XamlImage : XamlNode
{
public:
	XamlImage()
		: XamlNode(xntImage)
	{
	}

	std::string source;
	XamlSize size;
	XamlTransformOrigin origin;
	XamlTransformGroup transform;
};

#endif
