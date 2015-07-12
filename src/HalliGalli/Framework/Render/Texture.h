#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "RenderHeader.h"
#include "../Math/Vertex.h"

class Texture
{
public:
	Texture(GLuint texid, int width, int height);
	virtual ~Texture();

	inline GLuint TextureID() const
	{
		return _texid;
	}

	inline int Width() const
	{
		return _width;
	}

	inline int Height() const
	{
		return _height;
	}

	inline operator GLuint() const
	{
		return _texid;
	}

	void Draw(const Vertex &bottomLeft, const Vertex &topRight);

protected:
	GLuint _texid;
	int _width;
	int _height;
};

#endif
