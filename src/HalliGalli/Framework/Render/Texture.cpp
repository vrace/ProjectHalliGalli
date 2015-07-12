#include "Texture.h"
#include "Render.h"

Texture::Texture(GLuint texid, int width, int height)
	: _texid(texid)
	, _width(width)
	, _height(height)
{
}

Texture::~Texture()
{
}

void Texture::Draw(const Vertex &bottomLeft, const Vertex &topRight)
{
	Render &r = Render::GetInstance();

	r.BindTexture(_texid);

	r.Triangle(
		RenderVertex(bottomLeft, RenderUV(0, 0)),
		RenderVertex(topRight, RenderUV(1, 1)),
		RenderVertex(Vertex(bottomLeft.x(), topRight.y()), RenderUV(0, 1)));

	r.Triangle(
		RenderVertex(topRight, RenderUV(1, 1)),
		RenderVertex(bottomLeft, RenderUV(0, 0)),
		RenderVertex(Vertex(topRight.x(), bottomLeft.y()), RenderUV(1, 0)));
}
