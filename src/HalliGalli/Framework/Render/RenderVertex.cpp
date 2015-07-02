#include "RenderVertex.h"

RenderVertex::RenderVertex()
{
}

RenderVertex::RenderVertex(const Vertex &v)
	: _v(v)
{
}

RenderVertex::RenderVertex(const Vertex &v, const RenderColor &c)
	: _v(v)
	, _c(c)
{
}

RenderVertex::RenderVertex(const Vertex &v, const RenderUV &uv)
	: _v(v)
	, _uv(uv)
{
}

RenderVertex::RenderVertex(const Vertex &v, const RenderColor &c, const RenderUV &uv)
	: _v(v)
	, _c(c)
	, _uv(uv)
{
}

int RenderVertex::OffsetVertex()
{
	return (int)&((RenderVertex*)(void*)0)->_v;
}

int RenderVertex::OffsetColor()
{
	return (int)&((RenderVertex*)(void*)0)->_c;
}

int RenderVertex::OffsetUV()
{
	return (int)&((RenderVertex*)(void*)0)->_uv;
}

int RenderVertex::Stride()
{
	return sizeof(RenderVertex);
}
