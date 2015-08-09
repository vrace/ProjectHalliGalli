#include "BitmapFont.h"
#include "TextureManager.h"
#include <fstream>

BitmapFont::BitmapFont(const std::string &fontdesc)
{
	std::ifstream fs(fontdesc);
	if (fs.is_open())
	{
		_desc.Init(fs);

		for (BitmapFontPages::MapType::iterator it = _desc.pages.pages.begin();
			it != _desc.pages.pages.end(); ++it)
		{
			_textures[it->first] = LoadFontTexture(it->second);
		}
	}
}

BitmapFont::~BitmapFont()
{
	TextureManager &texman = TextureManager::GetInstance();

	for (MapType::iterator it = _textures.begin(); it != _textures.end(); ++it)
		texman.ReleaseTexture(it->second);

	_textures.clear();
}

Texture* BitmapFont::LoadFontTexture(const std::string &name)
{
	std::string res = std::string("data/fonts/") + name;
	return TextureManager::GetInstance().GetTexture(res);
}

void BitmapFont::Draw(const vec2 &topleft, const std::string &text)
{

}
