#ifndef __RENDER_H__
#define __RENDER_H__

#ifdef WIN32

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#else

#error Unsupported render platform

#endif

#include "../Math/Vertex.h"

class Render
{
public:
	~Render();

	static Render& GetInstance();

	void Triangle(const Vertex &a, const Vertex &b, const Vertex &c);

private:
	Render();
	Render(const Render&);
	Render& operator= (const Render&);
};

#endif
