#include "BitmapFontDesc.h"

namespace
{
	const char* Lookup(const std::string &line, const std::string &tag)
	{
		std::string search = tag + "=";
		std::string::size_type pos = line.find(search);
		return pos != std::string::npos ? &line.c_str()[pos + tag.length()] : NULL;
	}

	bool ExtractValue(const std::string &line, const std::string &tag, int &value)
	{
		const char *str = Lookup(line, tag);
		return str ? (sscanf(str, "=%d", &value) == 1) : false;
	}

	bool ExtractValue(const std::string &line, const std::string &tag, std::string &value)
	{
		const char *str = Lookup(line, tag);
		if (str)
		{
			std::vector<char> buf(line.length() + 1, '\0');
			if (sscanf(str, "=%s", &buf[0]) == 1)
			{
				value = &buf[0];
				return true;
			}
		}

		return false;
	}
};

BitmapFontPadding::BitmapFontPadding()
	: top(0), left(0), bottom(0), right(0)
{
}

void BitmapFontPadding::Init(const std::string &line)
{
	std::string::size_type pos = line.find("padding=");
	if (pos != std::string::npos)
	{
		sscanf(&line.c_str()[pos], "padding=%d,%d,%d,%d",
			&top, &right, &bottom, &left);
	}
}

void BitmapFontPages::Init(const std::string &line)
{
	int id;
	std::string file;

	if (ExtractValue(line, "id", id) && ExtractValue(line, "file", file))
	{
		if (!file.empty() && file[0] == '"')
			file = file.substr(1);
		if (!file.empty() && file[file.length() - 1] == '"')
			file = file.substr(0, file.length() - 1);

		pages[id] = file;
	}
}

BitmapFontChar::BitmapFontChar()
	: id(0)
	, x(0), y(0), width(0), height(0)
	, xoffset(0), yoffset(0)
	, xadvance(0)
	, page(0)
{
}

bool BitmapFontChar::Init(const std::string &line)
{
	ExtractValue(line, "id", id);
	ExtractValue(line, "x", x);
	ExtractValue(line, "y", y);
	ExtractValue(line, "width", width);
	ExtractValue(line, "height", height);
	ExtractValue(line, "xoffset", xoffset);
	ExtractValue(line, "yoffset", yoffset);
	ExtractValue(line, "xadvance", xadvance);
	ExtractValue(line, "page", page);

	return id > 0;
}

BitmapFontDesc::BitmapFontDesc()
{
}

void BitmapFontDesc::Init(std::istream &font)
{
	std::string line;
	while (std::getline(font, line))
	{
		if (line.find("info ") == 0)
		{
			padding.Init(line);
		}
		else if (line.find("common ") == 0)
		{
			// TODO:
		}
		else if (line.find("page ") == 0)
		{
			pages.Init(line);
		}
		else if (line.find("char ") == 0)
		{
			BitmapFontChar chardef;
			if (chardef.Init(line))
				chardefs[chardef.id] = chardef;
		}
	}
}
