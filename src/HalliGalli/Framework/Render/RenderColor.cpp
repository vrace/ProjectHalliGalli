#include "RenderColor.h"

RenderColor::RenderColor()
{
	_c[0] = 1;
	_c[1] = 1;
	_c[2] = 1;
	_c[3] = 1;
}

RenderColor::RenderColor(float r, float g, float b)
{
	_c[0] = r;
	_c[1] = g;
	_c[2] = b;
	_c[3] = 1;
}

RenderColor::RenderColor(float r, float g, float b, float a)
{
	_c[0] = r;
	_c[1] = g;
	_c[2] = b;
	_c[3] = a;
}
