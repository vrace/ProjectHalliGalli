#ifndef __RENDER_H__
#define __RENDER_H__

#include "RenderHeader.h"
#include "RenderVertex.h"
#include <vector>

class Render
{
public:
	~Render();

	static Render& GetInstance();

	void BindTexture(GLuint texture);
	void Triangle(const RenderVertex &a, const RenderVertex &b, const RenderVertex &c);
	void SubmitBatch();

private:
	Render();
	Render(const Render&);
	Render& operator= (const Render&);

private:
	GLuint _texture;
	std::vector<RenderVertex> _vertices;
};

typedef Render RenderEngine;

void PrintRenderErrors(void);

#endif
