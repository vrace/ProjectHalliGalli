#ifndef __RENDER_COLOR_H__
#define __RENDER_COLOR_H__

class RenderColor
{
public:
	RenderColor();
	RenderColor(float r, float g, float b);
	RenderColor(float r, float g, float b, float a);

	inline float r() const
	{
		return _c[0];
	}

	inline float g() const
	{
		return _c[1];
	}

	inline float b() const
	{
		return _c[2];
	}

	inline float a() const
	{
		return _c[3];
	}

private:
	float _c[4];
};

#endif
