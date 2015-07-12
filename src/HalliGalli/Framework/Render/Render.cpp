#include "Render.h"
#include <stdio.h>

Render::Render()
	: _texture(0)
{
}

Render::~Render()
{
}

Render& Render::GetInstance()
{
	static Render r;
	return r;
}

void Render::BindTexture(GLuint texture)
{
	if (texture != _texture && !_vertices.empty())
		SubmitBatch();

	_texture = texture;
}

void Render::Triangle(const RenderVertex &a, const RenderVertex &b, const RenderVertex &c)
{
	_vertices.push_back(a);
	_vertices.push_back(b);
	_vertices.push_back(c);
}

void Render::SubmitBatch()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _texture);

	if (!_vertices.empty())
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		unsigned char *buffer = (unsigned char*)&_vertices[0];

		glVertexPointer(3, GL_FLOAT, RenderVertex::Stride(), buffer + RenderVertex::OffsetVertex());
		glColorPointer(4, GL_FLOAT, RenderVertex::Stride(), buffer + RenderVertex::OffsetColor());
		glTexCoordPointer(2, GL_FLOAT, RenderVertex::Stride(), buffer + RenderVertex::OffsetUV());

		glDrawArrays(GL_TRIANGLES, 0, _vertices.size());

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	_vertices.clear();
}

void PrintRenderErrors(void)
{
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		printf("OpenGL error: %d\n", err);
	}
}
