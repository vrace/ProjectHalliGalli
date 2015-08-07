#ifndef __BITMAP_FONT_DESC_H__
#define __BITMAP_FONT_DESC_H__

#include <istream>
#include <string>
#include <map>
#include <vector>

struct BitmapFontPadding
{
	BitmapFontPadding();
	void Init(const std::string &line);

	int top, left, bottom, right;
};

struct BitmapFontPages
{
	void Init(const std::string &line);

	std::map<int, std::string> pages;
};

struct BitmapFontChar
{
	BitmapFontChar();
	bool Init(const std::string &line);

	int id, x, y, width, height, xoffset, yoffset, xadvance, page;
};

struct BitmapFontDesc
{
	BitmapFontPadding padding;
	BitmapFontPages pages;
	std::map<int, BitmapFontChar> chardefs;

	BitmapFontDesc();
	void Init(std::istream &font);
};

#endif
