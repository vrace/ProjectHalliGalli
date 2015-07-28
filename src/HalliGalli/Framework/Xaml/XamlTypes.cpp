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

	std::string FilenameAppendPostfix(const std::string &filename, const std::string &postfix)
	{
		std::string::size_type pos = filename.rfind('.');

		if (pos != std::string::npos)
			return filename.substr(0, pos) + postfix + filename.substr(pos);

		return filename + postfix;
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

XamlTransformGroup::XamlTransformGroup()
	: scale(1, 1)
	, rotate(0)
	, translate(0, 0)
{
}

XamlTransformGroup::XamlTransformGroup(TiXmlElement *root)
	: XamlTransformGroup()
{
	if (root)
	{
		TiXmlElement *group = root->FirstChildElement("TransformGroup");
		if (group)
		{
			TiXmlElement *scaleTransform = group->FirstChildElement("ScaleTransform");
			if (scaleTransform)
			{
				scale.x = (float)atof(XamlAttributeValue(scaleTransform, "ScaleX").c_str());
				scale.y = (float)atof(XamlAttributeValue(scaleTransform, "ScaleY").c_str());
			}

			TiXmlElement *rotateTransform = group->FirstChildElement("RotateTransform");
			if (rotateTransform)
				rotate = (float)atof(XamlAttributeValue(rotateTransform, "Angle").c_str());

			TiXmlElement *translateTransform = group->FirstChildElement("TranslateTransform");
			if (translateTransform)
			{
				translate.x = (float)atof(XamlAttributeValue(translateTransform, "X").c_str());
				translate.y = (float)atof(XamlAttributeValue(translateTransform, "Y").c_str());
			}
		}
	}
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
	, transform(element->FirstChildElement("Image.RenderTransform"))
{
}

XamlButton::XamlButton()
	: origin(0.5f, 0.5f)
{
}

XamlButton::XamlButton(TiXmlElement *element)
	: origin(OriginFromXaml(element))
	, size(element)
	, transform(element->FirstChildElement("Button.RenderTransform"))
{
	TiXmlElement *imageElement = element->FirstChildElement("Image");
	if (imageElement)
	{
		imageNormal = XamlAttributeValue(imageElement, "Source");
		imageDown = FilenameAppendPostfix(imageNormal, "_down");
	}
}
