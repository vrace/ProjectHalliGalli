#ifndef __XAML_TYPES_H__
#define __XAML_TYPES_H__

#include "../Math/Vector2.h"
#include "../Math/Matrix44.h"
#include <string>

class TiXmlElement;

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

class XamlPoint
{
public:
	int x;
	int y;

	XamlPoint()
		: x(0)
		, y(0)
	{
	}

	XamlPoint(int _x, int _y)
		: x(_x)
		, y(_y)
	{
	}
};

class XamlSize
{
public:
	int width;
	int height;

	XamlSize();
	XamlSize(int w, int h);
	XamlSize(TiXmlElement *element);
};

class XamlRect
{
public:
	XamlPoint origin;
	XamlSize size;
};

class XamlWindow
{
public:
	XamlWindow();
	XamlWindow(TiXmlElement *element);

	XamlSize size;
};

class XamlImage
{
public:
	XamlImage();
	XamlImage(TiXmlElement *element);

	std::string source;
	XamlSize size;
	vec2 origin;
	XamlTransformGroup transform;
};

#endif
