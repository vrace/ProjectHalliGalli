#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "RenderHeader.h"
#include "../Math/Vertex.h"
#include <string>

class Texture
{
public:
	friend class TextureManager;

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

	inline const std::string filename() const
	{
		return _filename;
	}

	void Draw(const Vertex &bottomLeft);
	void Draw(const Vertex &bottomLeft, const Vertex &topRight);

private:
	Texture(const std::string &filename, GLuint texid, int width, int height);
	Texture();
	Texture(const Texture&);
	Texture& operator =(const Texture&);
	virtual ~Texture();

protected:
	std::string _filename;
	GLuint _texid;
	int _width;
	int _height;
};

#endif
