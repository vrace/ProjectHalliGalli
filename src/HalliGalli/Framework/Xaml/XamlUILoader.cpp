#include "XamlUILoader.h"
#include "XamlUIWindow.h"
#include "XamlUIImage.h"

XamlUILoader::XamlUILoader(const std::string &xaml)
{
	_document.LoadFile(xaml.c_str());
}

XamlUINode* XamlUILoader::CreateNodes()
{
	return CreateNodes(_document.RootElement());
}

XamlUINode* XamlUILoader::CreateNodes(TiXmlElement *xaml)
{
	XamlUINode *node = NULL;

	if (xaml)
	{
		std::string type = xaml->Value();

		if (type == "Window")
		{
			XamlWindow window;
			window.size = XamlSize(xaml);

			node = new XamlUIWindow(window);
		}

		if (node)
		{
			TiXmlElement *sub = xaml->FirstChildElement();
			while (sub)
			{
				XamlUINode *subnode = CreateNodes(sub);
				if (subnode)
					node->AddSubNode(subnode);

				sub = sub->NextSiblingElement();
			}
		}
	}

	return node;
}
