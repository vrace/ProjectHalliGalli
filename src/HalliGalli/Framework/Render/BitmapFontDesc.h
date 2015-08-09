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

struct BitmapFontInfo
{
	void Init(const std::string &line);

	BitmapFontPadding padding;
};

struct BitmapFontCommon
{
	BitmapFontCommon();
	void Init(const std::string &line);

	int lineHeight, base;
};

struct BitmapFontPages
{
	void Init(const std::string &line);

	typedef std::map<int, std::string> MapType;
	MapType pages;
};

struct BitmapFontChar
{
	BitmapFontChar();
	bool Init(const std::string &line);

	int id, x, y, width, height, xoffset, yoffset, xadvance, page;
};

struct BitmapFontDesc
{
	BitmapFontInfo info;
	BitmapFontCommon common;
	BitmapFontPages pages;
	std::map<int, BitmapFontChar> chardefs;

	BitmapFontDesc();
	void Init(std::istream &font);
};

#endif
