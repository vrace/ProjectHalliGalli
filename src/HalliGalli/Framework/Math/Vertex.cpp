#include "Vertex.h"

Vertex::Vertex()
{
	_v[0] = 0;
	_v[1] = 0;
	_v[2] = 0;
	_v[3] = 1;
}

Vertex::Vertex(float x, float y)
{
	_v[0] = x;
	_v[1] = y;
	_v[2] = 0;
	_v[3] = 1;
}

Vertex::Vertex(int x, int y)
	: Vertex((float)x, (float)y)
{
}

Vertex::Vertex(float x, float y, float z)
{
	_v[0] = x;
	_v[1] = y;
	_v[2] = z;
	_v[3] = 1;
}

Vertex::Vertex(int x, int y, int z)
	: Vertex((float)x, (float)y, (float)z)
{
}

Vertex::Vertex(const vec2 &vec)
	: Vertex(vec.x, vec.y)
{
}
