#include "XamlTypes.h"
#include "../ThirdParty/tinyxml/tinyxml.h"

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
