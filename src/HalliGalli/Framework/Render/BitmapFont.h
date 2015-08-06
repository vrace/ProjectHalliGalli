#ifndef __BITMAP_FONT_H__
#define __BITMAP_FONT_H__

#include "Texture.h"
#include "BitmapFontDesc.h"
#include <string>
#include <vector>

class BitmapFont
{
public:
	BitmapFont(const std::string &fontdesc);
	~BitmapFont();

private:
	BitmapFont();
	BitmapFont(const BitmapFont&);
	BitmapFont& operator =(const BitmapFont&);

private:
	std::vector<Texture*> _textures;
	BitmapFontDesc _desc;
};

#endif
