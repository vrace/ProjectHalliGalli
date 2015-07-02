#include "Render.h"

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
	glBegin(GL_TRIANGLES);
	SubmitVertex(a);
	SubmitVertex(b);
	SubmitVertex(c);
	glEnd();
}
