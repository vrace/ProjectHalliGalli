#ifndef __IMAGE_DATA_H__
#define __IMAGE_DATA_H__

#include <vector>
#include <string>

class ImageData
{
public:
	ImageData();

	void Reset();
	bool Load(const std::string &filename);

	inline const unsigned char* buffer() const
	{
		return _buffer.empty() ? NULL : &_buffer[0];
	}

	inline int buffersize() const
	{
		return (int)_buffer.size();
	}

	inline int width() const
	{
		return _width;
	}

	inline int height() const
	{
		return _height;
	}

	inline int bpp() const
	{
		return _bpp;
	}

private:
	bool LoadFromPng(const std::string &filename);

private:
	std::vector<unsigned char> _buffer;
	int _width;
	int _height;
	int _bpp;
};

#endif
