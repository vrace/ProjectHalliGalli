#ifndef __VECTOR_2_H__
#define __VECTOR_2_H__

template <class T>
class vector2
{
public:
	vector2()
		: x()
		, y()
	{
	}

	vector2(T _x, T _y)
		: x(_x)
		, y(_y)
	{
	}

public:
	T x;
	T y;
};

typedef vector2<float> vector2f;

#endif
