#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include "Texture.h"
#include <map>
#include <string>

class TextureManager
{
public:
	~TextureManager();

	static void InitInstance();
	static void DeleteInstance();
	static TextureManager& GetInstance();

	Texture* GetTexture(const std::string &filename);
	void ReleaseTexture(Texture *texture);

private:
	TextureManager();
	TextureManager(const TextureManager&);
	TextureManager& operator =(const TextureManager&);

private:
	struct TextureRef
	{
		Texture *texture;
		int count;
	};

	typedef std::map<std::string, TextureRef> TextureCache;

private:
	Texture* LoadTexture(const std::string &filename);
	void DeleteTexture(Texture *texture);

private:
	TextureCache _textureCache;
	static TextureManager *_instance;
};

#endif
