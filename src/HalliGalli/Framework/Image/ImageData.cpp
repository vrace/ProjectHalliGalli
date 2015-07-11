#include "ImageData.h"
#include "../ThirdParty/libpng/png.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

ImageData::ImageData()
	: _width(0)
	, _height(0)
	, _bpp(0)
{
}

void ImageData::Reset()
{
	_buffer.clear();
	_width = 0;
	_height = 0;
	_bpp = 0;
}

bool ImageData::Load(const std::string &filename)
{
	//return false;
	return LoadFromPng(filename);
}

bool ImageData::LoadFromPng(const std::string &filename)
{
	bool done = false;
	FILE *fp = NULL;
	png_structp png = NULL;
	png_infop info = NULL;

	do
	{
		Reset();

		fp = fopen(filename.c_str(), "rb");
		if (!fp)
			break;

		png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		info = png_create_info_struct(png);

		setjmp(png_jmpbuf(png));

		unsigned char signature[4];
		fread(signature, 1, 4, fp);
		if (png_sig_cmp(signature, 0, 4) != 0)
			break;

		rewind(fp);
		png_init_io(png, fp);
		png_read_png(png, info, PNG_TRANSFORM_EXPAND, NULL);

		_width = png_get_image_width(png, info);
		_height = png_get_image_height(png, info);

		switch (png_get_color_type(png, info))
		{
		case PNG_COLOR_TYPE_RGBA:
			_bpp = 32;
			break;
			
		case PNG_COLOR_TYPE_RGB:
			_bpp = 24;
			break;

		default:
			break;
		}

		if (_bpp != 0)
		{
			int bytesPerLine = _width * _bpp / 8;
			_buffer.resize(_height * bytesPerLine);
			
			png_bytep *rows = png_get_rows(png, info);
			for (int i = 0; i < _height; i++)
				memcpy(&_buffer[i * bytesPerLine], rows[i], bytesPerLine);

			done = true;
		}

	} while (0);

	if (fp)
		fclose(fp);

	if (png)
		png_destroy_read_struct(&png, &info, NULL);

	if (!done)
		Reset();

	return done;
}
