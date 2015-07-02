#ifndef __RENDER_UV_H__
#define __RENDER_UV_H__

class RenderUV
{
public:
	RenderUV();
	RenderUV(float u, float v);

	inline float u() const
	{
		return _uv[0];
	}

	inline float v() const
	{
		return _uv[1];
	}

private:
	float _uv[2];
};

#endif
