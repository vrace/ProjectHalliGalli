#ifndef __XAML_TYPES_H__
#define __XAML_TYPES_H__

#include "../Math/Vector2.h"
#include "../Math/Matrix44.h"
#include <string>

class TiXmlElement;

class XamlTransformGroup
{
public:
	XamlTransformGroup();
	XamlTransformGroup(TiXmlElement *root);

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
	XamlRect();
	XamlRect(const XamlPoint &_origin, const XamlSize &_size);

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

class XamlNameable
{
public:
	XamlNameable();
	XamlNameable(TiXmlElement *element);
	virtual ~XamlNameable();

	std::string name;
};

class XamlDrawable
{
public:
	XamlDrawable();
	XamlDrawable(TiXmlElement *element, const std::string &transformGroupName);
	virtual ~XamlDrawable();

	XamlSize size;
	vec2 origin;
	XamlTransformGroup transform;
};

class XamlImage
	: public XamlDrawable
	, public XamlNameable
{
public:
	XamlImage(TiXmlElement *element);

	std::string source;
};

class XamlButton
	: public XamlDrawable
	, public XamlNameable
{
public:
	XamlButton(TiXmlElement *element);

	std::string imageNormal, imageDown;
};

#endif
