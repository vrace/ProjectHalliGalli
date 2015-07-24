#ifndef __VECTOR_2_H__
#define __VECTOR_2_H__

#include "Matrix44.h"

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

	vector2<T> ApplyTransform(const matrix44<T> &transform)
	{
		const T *m = transform.xform;

		x = m[0] * x + m[4] * y + m[12];
		y = m[1] * x + m[5] * y + m[13];

		return *this;
	}

public:
	T x;
	T y;
};

typedef vector2<float> vec2;

#endif
