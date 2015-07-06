#ifndef __IMAGE_DATA_H__
#define __IMAGE_DATA_H__

#include <vector>

class ImageData
{
public:
	ImageData();

	std::vector<unsigned char> buffer;
	int width;
	int height;
	int format;

private:
	ImageData(const ImageData&);
	ImageData& operator= (const ImageData&);
};

#endif
