#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex
{
public:
	Vertex();
	Vertex(float x, float y);
	Vertex(float x, float y, float z);

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
