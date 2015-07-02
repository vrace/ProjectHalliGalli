#ifndef __RENDER_VERTEX_H__
#define __RENDER_VERTEX_H__

#include "../Math/Vertex.h"
#include "RenderColor.h"
#include "RenderUV.h"

class RenderVertex
{
public:
	RenderVertex();
	explicit RenderVertex(const Vertex &v);
	RenderVertex(const Vertex &v, const RenderColor &c);
	RenderVertex(const Vertex &v, const RenderUV &uv);
	RenderVertex(const Vertex &v, const RenderColor &c, const RenderUV &uv);

	static int OffsetVertex();
	static int OffsetColor();
	static int OffsetUV();
	static int Stride();

	inline const Vertex& vertex() const
	{
		return _v;
	}

	inline const RenderColor& color() const
	{
		return _c;
	}

	inline const RenderUV& uv() const
	{
		return _uv;
	}
	
private:
	Vertex _v;
	RenderColor _c;
	RenderUV _uv;
};

#endif
