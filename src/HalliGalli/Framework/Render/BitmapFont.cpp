#include "BitmapFont.h"
#include "TextureManager.h"
#include <fstream>

BitmapFontPadding::BitmapFontPadding()
	: top(0)
	, left(0)
	, bottom(0)
	, right(0)
{
}

BitmapFont::BitmapFont(const std::string &fontdesc)
{
	std::ifstream fs(fontdesc);

	if (fs.is_open())
	{
		std::string line;

		while (std::getline(fs, line))
		{
			ProcessDesc(line);
		}
	}
}

BitmapFont::~BitmapFont()
{
	TextureManager &texman = TextureManager::GetInstance();

	for (std::vector<Texture*>::iterator it = _textures.begin(); it != _textures.end(); ++it)
		texman.ReleaseTexture(*it);

	_textures.clear();
}

void BitmapFont::ProcessDesc(const std::string &line)
{
	if (line.find("info face") == 0)
	{
		// We read only padding here
		std::string::size_type pos = line.find("padding=");
		if (pos != std::string::npos)
		{
			sscanf(&line.c_str()[pos], "padding=%d,%d,%d,%d",
				&_padding.top, &_padding.right, &_padding.bottom, &_padding.left);
		}
	}
}
