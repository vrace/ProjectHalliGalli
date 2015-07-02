#include "Render.h"

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

void Render::Triangle(const Vertex &a, const Vertex &b, const Vertex &c)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(a.x(), a.y(), a.z());
	glVertex3f(b.x(), b.y(), b.z());
	glVertex3f(c.x(), c.y(), c.z());
	glEnd();
}
