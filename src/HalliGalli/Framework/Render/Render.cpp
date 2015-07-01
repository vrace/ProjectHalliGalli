#include "Render.h"

void DrawTriangle(const Vertex &a, const Vertex &b, const Vertex &c)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(a.x(), a.y(), a.z());
	glVertex3f(b.x(), b.y(), b.z());
	glVertex3f(c.x(), c.y(), c.z());
	glEnd();
}

void DrawTriangle(const Vertex *vertices)
{
	DrawTriangle(vertices[0], vertices[1], vertices[2]);
}
