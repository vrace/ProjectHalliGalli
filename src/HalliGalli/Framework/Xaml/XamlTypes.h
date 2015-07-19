#ifndef __XAML_TYPES_H__
#define __XAML_TYPES_H__

#include "../Math/Vector2.h"
#include "../Math/Matrix44.h"
#include <string>

class XamlTransformGroup
{
public:
	XamlTransformGroup()
		: scale(1, 1)
		, rotate(0)
		, translate(0, 0)
	{
	}

	vec2 scale;
	vec2 translate;
	float rotate;
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
		, origin(0.5f, 0.5f)
	{
	}

	std::string source;
	XamlSize size;
	vec2 origin;
	XamlTransformGroup transform;
};

#endif
