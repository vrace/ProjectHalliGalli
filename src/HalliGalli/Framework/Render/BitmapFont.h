#ifndef __BITMAP_FONT_H__
#define __BITMAP_FONT_H__

#include "Texture.h"
#include "BitmapFontDesc.h"
#include "../Math/Vector2.h"
#include <string>

class BitmapFont
{
public:
	BitmapFont(const std::string &fontdesc);
	~BitmapFont();

	void Draw(const vec2 &topleft, const std::string &text);

private:
	BitmapFont();
	BitmapFont(const BitmapFont&);
	BitmapFont& operator =(const BitmapFont&);

private:
	Texture* LoadFontTexture(const std::string &name);

private:
	typedef std::map<int, Texture*> MapType;
	MapType _textures;
	BitmapFontDesc _desc;
};

#endif
