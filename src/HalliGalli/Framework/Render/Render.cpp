#include "Render.h"
#include <stdio.h>

namespace
{
	void SubmitVertex(const RenderVertex &v)
	{
		glColor4f(v.color().r(), v.color().g(), v.color().b(), v.color().a());
		glTexCoord2f(v.uv().u(), v.uv().v());
		glVertex3f(v.vertex().x(), v.vertex().y(), v.vertex().z());
	}
}

Render::Render()
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

void Render::Triangle(const RenderVertex &a, const RenderVertex &b, const RenderVertex &c)
{
	_vertices.push_back(a);
	_vertices.push_back(b);
	_vertices.push_back(c);
}

void Render::SubmitBatch()
{
	// Let's ignore texture for now

	if (!_vertices.empty())
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		unsigned char *buffer = (unsigned char*)&_vertices[0];

		glVertexPointer(3, GL_FLOAT, RenderVertex::Stride(), buffer + RenderVertex::OffsetVertex());
		glColorPointer(4, GL_FLOAT, RenderVertex::Stride(), buffer + RenderVertex::OffsetColor());

		glDrawArrays(GL_TRIANGLES, 0, _vertices.size());

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
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
