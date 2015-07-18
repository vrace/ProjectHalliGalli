#ifndef __XAML_UI_NODE_H__
#define __XAML_UI_NODE_H__

#include "XamlTypes.h"
#include <vector>

class XamlUINode
{
public:
	XamlUINode();
	virtual ~XamlUINode();

	virtual void Update(float delta);
	virtual void Render();

protected:
	void AddSubNode(XamlUINode *node);
	void RemoveFromParent();

private:
	XamlUINode(const XamlUINode&);
	XamlUINode& operator =(const XamlUINode&);

protected:
	typedef std::vector<XamlUINode*> XamlUINodeArray;
	XamlUINode *_parent;
	XamlUINodeArray _subnodes;

	XamlTransformOrigin _origin;
	XamlTransformGroup _transform;
};

#endif
