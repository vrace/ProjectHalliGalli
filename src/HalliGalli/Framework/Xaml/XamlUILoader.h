#ifndef __XAML_UI_LOADER_H__
#define __XAML_UI_LOADER_H__

#include "../ThirdParty/tinyxml/tinyxml.h"
#include <string>

class XamlUINode;

class XamlUILoader
{
public:
	XamlUILoader(const std::string &xaml);
	XamlUINode* CreateNodes();

private:
	XamlUILoader();
	XamlUILoader(const XamlUILoader&);
	XamlUILoader& operator =(const XamlUILoader&);

private:
	XamlUINode* CreateNodes(TiXmlElement *xaml);
	void CreateSubNodes(XamlUINode *node, TiXmlElement *xaml);

private:
	TiXmlDocument _document;
};

#endif
