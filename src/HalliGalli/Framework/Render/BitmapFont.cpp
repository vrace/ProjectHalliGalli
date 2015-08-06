#include "BitmapFont.h"
#include "TextureManager.h"
#include <fstream>

BitmapFont::BitmapFont(const std::string &fontdesc)
{
	std::ifstream fs(fontdesc);
	if (fs.is_open())
	{
		_desc.Init(fs);

		// TODO: load textures
	}
}

BitmapFont::~BitmapFont()
{
	TextureManager &texman = TextureManager::GetInstance();

	for (std::vector<Texture*>::iterator it = _textures.begin(); it != _textures.end(); ++it)
		texman.ReleaseTexture(*it);

	_textures.clear();
}
