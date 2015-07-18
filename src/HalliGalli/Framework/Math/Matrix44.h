#ifndef __MATRIX_44_H__
#define __MATRIX_44_H__

template <class T>
class matrix44
{
public:
	static matrix44<T> identity()
	{
		matrix44<T> mat;
		T *xform = mat.xform;

		for (int i = 0; i < 16; i++)
			xform[i] = T();

		xform[0] = T(1);
		xform[5] = T(1);
		xform[10] = T(1);
		xform[15] = T(1);

		return mat;
	}

	static matrix44<T> translate(T x, T y, T z)
	{
		matrix44<T> mat = matrix44<T>::identity();

		mat.xform[12] = x;
		mat.xform[13] = y;
		mat.xform[14] = z;

		return mat;
	}

	static matrix44<T> scale(T x, T y, T z)
	{
		matrix44<T> mat = matrix44<T>::identity();

		mat.xform[0] = x;
		mat.xform[5] = y;
		mat.xform[10] = z;

		return mat;
	}

	matrix44<T>& operator =(const matrix44<T> &rhs)
	{
		if (this != &rhs)
		{
			for (int i = 0; i < 16; i++)
				xform[i] = rhs.xform[i];
		}

		return *this;
	}

	matrix44<T> operator *(const matrix44<T> &rhs)
	{
		matrix44<T> mat;

		T *R = mat.xform;
		const T *M = xform;
		const T *L = rhs.xform;

		R[0] = M[0] * L[0] + M[4] * L[1] + M[8] * L[2] + M[12] * L[3];
		R[1] = M[1] * L[0] + M[5] * L[1] + M[9] * L[2] + M[13] * L[3];
		R[2] = M[2] * L[0] + M[6] * L[1] + M[10] * L[2] + M[14] * L[3];
		R[3] = M[3] * L[0] + M[7] * L[1] + M[11] * L[2] + M[15] * L[3];

		R[4] = M[0] * L[4] + M[4] * L[5] + M[8] * L[6] + M[12] * L[7];
		R[5] = M[1] * L[4] + M[5] * L[5] + M[9] * L[6] + M[13] * L[7];
		R[6] = M[2] * L[4] + M[6] * L[5] + M[10] * L[6] + M[14] * L[7];
		R[7] = M[3] * L[4] + M[7] * L[5] + M[11] * L[6] + M[15] * L[7];

		R[8] = M[0] * L[8] + M[4] * L[9] + M[8] * L[10] + M[12] * L[11];
		R[9] = M[1] * L[8] + M[5] * L[9] + M[9] * L[10] + M[13] * L[11];
		R[10] = M[2] * L[8] + M[6] * L[9] + M[10] * L[10] + M[14] * L[11];
		R[11] = M[3] * L[8] + M[7] * L[9] + M[11] * L[10] + M[15] * L[11];

		R[12] = M[0] * L[12] + M[4] * L[13] + M[8] * L[14] + M[12] * L[15];
		R[13] = M[1] * L[12] + M[5] * L[13] + M[9] * L[14] + M[13] * L[15];
		R[14] = M[2] * L[12] + M[6] * L[13] + M[10] * L[14] + M[14] * L[15];
		R[15] = M[3] * L[12] + M[7] * L[13] + M[11] * L[14] + M[15] * L[15];

		return mat;
	}

public:
	T xform[16];
};

typedef matrix44<float> mat44;

#endif
