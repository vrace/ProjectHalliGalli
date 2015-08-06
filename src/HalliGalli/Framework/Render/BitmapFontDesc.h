#ifndef __BITMAP_FONT_DESC_H__
#define __BITMAP_FONT_DESC_H__

#include <istream>
#include <string>
#include <map>
#include <vector>

struct BitmapFontPadding
{
	int top, left, bottom, right;

	BitmapFontPadding();
	void Init(const std::string &line);
};

struct BitmapFontPages
{
	std::map<int, std::string> pages;

	void Init(const std::string &line);
};

struct BitmapFontDesc
{
	BitmapFontPadding padding;
	BitmapFontPages pages;

	BitmapFontDesc();
	void Init(std::istream &font);
};

#endif
