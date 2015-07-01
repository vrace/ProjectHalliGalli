#include "Vertex.h"

Vertex::Vertex()
{
	_v[0] = 0;
	_v[1] = 0;
	_v[2] = 0;
}

Vertex::Vertex(float x, float y)
{
	_v[0] = x;
	_v[1] = y;
	_v[2] = 0;
}

Vertex::Vertex(float x, float y, float z)
{
	_v[0] = x;
	_v[1] = y;
	_v[2] = z;
}
