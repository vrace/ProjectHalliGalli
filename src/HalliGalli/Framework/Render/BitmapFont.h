#ifndef __BITMAP_FONT_H__
#define __BITMAP_FONT_H__

#include "Texture.h"
#include <string>
#include <vector>

struct BitmapFontPadding
{
	BitmapFontPadding();
	int top, left, bottom, right;
};

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
	void ProcessDesc(const std::string &line);
	void ProcessInfoArgs(const std::string &line);
	void ProcessCommonArgs(const std::string &line);

private:
	std::vector<Texture*> _textures;
	BitmapFontPadding _padding;
};

#endif
