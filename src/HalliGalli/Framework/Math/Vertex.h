#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Vector2.h"

class Vertex
{
public:
	Vertex();
	Vertex(float x, float y);
	Vertex(int x, int y);
	Vertex(float x, float y, float z);
	Vertex(int x, int y, int z);
	Vertex(const vec2 &vec);

	inline float x() const
	{
		return _v[0];
	}

	inline float y() const
	{
		return _v[1];
	}

	inline float z() const
	{
		return _v[2];
	}

private:
	float _v[4];
};

#endif
