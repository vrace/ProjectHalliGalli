#include "RenderUV.h"

RenderUV::RenderUV()
{
	_uv[0] = 0;
	_uv[1] = 0;
}

RenderUV::RenderUV(float u, float v)
{
	_uv[0] = u;
	_uv[1] = v;
}
