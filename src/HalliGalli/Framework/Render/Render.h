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

#include "RenderVertex.h"
#include <vector>

class Render
{
public:
	~Render();

	static Render& GetInstance();

	void Triangle(const RenderVertex &a, const RenderVertex &b, const RenderVertex &c);
	void SubmitBatch();

private:
	Render();
	Render(const Render&);
	Render& operator= (const Render&);

private:
	std::vector<RenderVertex> _vertices;
};

void PrintRenderErrors(void);

#endif
