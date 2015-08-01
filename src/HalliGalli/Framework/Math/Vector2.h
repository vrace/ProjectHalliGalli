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

		T px = x;
		T py = y;

		x = m[0] * px + m[4] * py + m[12];
		y = m[1] * px + m[5] * py + m[13];

		return *this;
	}

	vector2<T> operator +(const vector2<T> &rhs) const
	{
		return vector2<T>(x + rhs.x, y + rhs.y);
	}

	vector2<T> operator -(const vector2<T> &rhs) const
	{
		return vector2<T>(x - rhs.x, y - rhs.y);
	}

	T LengthSq() const
	{
		return x * x + y * y;
	}

	T Length() const
	{
		return sqrt(LengthSq());
	}

public:
	T x;
	T y;
};

typedef vector2<float> vec2;

#endif
