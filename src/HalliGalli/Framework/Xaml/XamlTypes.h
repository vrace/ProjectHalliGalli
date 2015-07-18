#ifndef __XAML_TYPES_H__
#define __XAML_TYPES_H__

#include <string>

class XamlTransformOrigin
{
public:
	XamlTransformOrigin()
		: x(0.5f)
		, y(0.5f)
	{
	}

	float x;
	float y;
};

class XamlScaleTransform
{
public:
	XamlScaleTransform()
		: scaleX(1)
		, scaleY(1)
	{
	}

	float scaleX;
	float scaleY;
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

class XamlTranslateTransform
{
public:
	XamlTranslateTransform()
		: x(0)
		, y(0)
	{
	}

	float x;
	float y;
};

class XamlTransformGroup
{
public:
	XamlScaleTransform scale;
	XamlRotateTransform rotate;
	XamlTranslateTransform translate;
};

class XamlWindow
{
public:
	int width;
	int height;
};

class XamlImage
{
public:
	std::string source;
	int width;
	int height;
	XamlTransformOrigin origin;
	XamlTransformGroup transform;
};

#endif
