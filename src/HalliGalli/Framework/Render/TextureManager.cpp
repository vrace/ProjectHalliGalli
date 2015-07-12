#include "TextureManager.h"
#include "../Image/ImageData.h"
#include <assert.h>

TextureManager* TextureManager::_instance = NULL;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (TextureCache::iterator it = _textureCache.begin(); it != _textureCache.end(); ++it)
	{
		DeleteTexture(it->second.texture);
	}

	_textureCache.clear();
}

TextureManager& TextureManager::GetInstance()
{
	assert(_instance != NULL);
	return *_instance;
}

void TextureManager::InitInstance()
{
	assert(_instance == NULL);
	_instance = new TextureManager();
}

void TextureManager::DeleteInstance()
{
	if (_instance)
	{
		delete _instance;
		_instance = NULL;
	}
}

Texture* TextureManager::GetTexture(const std::string &filename)
{
	Texture *texture = NULL;

	TextureCache::iterator it = _textureCache.find(filename);
	if (it != _textureCache.end())
	{
		it->second.count++;
		texture = it->second.texture;
	}
	else
	{
		texture = LoadTexture(filename);
		if (texture)
		{
			TextureRef ref;
			ref.count = 1;
			ref.texture = texture;
			_textureCache[filename] = ref;
		}
	}

	return texture;
}

Texture* TextureManager::LoadTexture(const std::string &filename)
{
	Texture *texture = NULL;

	ImageData image;
	if (image.Load(filename))
	{
		GLenum format = GL_INVALID_ENUM;

		switch (image.bpp())
		{
		case 24:
			format = GL_RGB;
			break;

		case 32:
			format = GL_RGBA;
			break;

		default:
			break;
		}

		if (format != GL_INVALID_ENUM)
		{
			GLuint texid;
			glGenTextures(1, &texid);
			glBindTexture(GL_TEXTURE_2D, texid);
			glTexImage2D(GL_TEXTURE_2D, 0, format, image.width(), image.height(), 0, format, GL_UNSIGNED_BYTE, image.buffer());
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			texture = new Texture(filename, texid, image.width(), image.height());
		}
	}

	return texture;
}

void TextureManager::ReleaseTexture(Texture *texture)
{
	if (texture)
	{
		TextureCache::iterator it = _textureCache.find(texture->filename());
		if (it != _textureCache.end())
		{
			it->second.count--;
			if (it->second.count <= 0)
			{
				DeleteTexture(texture);
			}
		}
	}
}

void TextureManager::DeleteTexture(Texture *texture)
{
	if (texture)
	{
		GLuint texid = texture->TextureID();
		glDeleteTextures(1, &texid);
		delete texture;
	}
}
