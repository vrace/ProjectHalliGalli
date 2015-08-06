#include "BitmapFontDesc.h"

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
	std::string::size_type posId = line.find("id=");
	std::string::size_type posFile = line.find("file=");

	if (posId != std::string::npos && posFile != std::string::npos)
	{
		int id;
		std::vector<char> file(line.length() + 1, '\0');
		sscanf(&line.c_str()[posId], "id=%d", &id);
		sscanf(&line.c_str()[posFile], "file=%s", &file[0]);

		std::string filename = &file[0];
		if (!filename.empty() && filename[0] == '"')
			filename = filename.substr(1);
		if (!filename.empty() && filename[filename.length() - 1] == '"')
			filename = filename.substr(0, filename.length() - 1);

		pages[id] = filename;
	}
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
			// TODO:
		}
	}
}
