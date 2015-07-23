#include "XamlTypes.h"
#include "../ThirdParty/tinyxml/tinyxml.h"
#include <stdio.h>

namespace
{
	vec2 OriginFromXaml(TiXmlElement *element)
	{
		const char *attr = element->Attribute("RenderTransformOrigin");

		if (attr)
		{
			vec2 vec;
			sscanf(attr, "%f,%f", &vec.x, &vec.y);

			return vec;
		}

		return vec2(0.5f, 0.5f);
	}

	std::string XamlAttributeValue(TiXmlElement *element, const std::string &key)
	{
		const char *attr = element->Attribute(key.c_str());
		return attr ? attr : std::string();
	}
};

XamlSize::XamlSize()
	: width(0)
	, height(0)
{
}

XamlSize::XamlSize(int w, int h)
	: width(w)
	, height(h)
{
}

XamlSize::XamlSize(TiXmlElement *element)
{
	const char *w = element->Attribute("Width");
	const char *h = element->Attribute("Height");

	width = w ? atoi(w) : 0;
	height = h ? atoi(h) : 0;
}

XamlWindow::XamlWindow()
{
}

XamlWindow::XamlWindow(TiXmlElement *element)
	: size(element)
{
}

XamlImage::XamlImage()
	: origin(0.5f, 0.5f)
{
}

XamlImage::XamlImage(TiXmlElement *element)
	: origin(OriginFromXaml(element))
	, source(XamlAttributeValue(element, "Source"))
	, size(element)
{
	// TODO: transform
}
