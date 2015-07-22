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

	void AddSubNode(XamlUINode *node);
	void RemoveFromParent();

private:
	XamlUINode(const XamlUINode&);
	XamlUINode& operator =(const XamlUINode&);

protected:
	typedef std::vector<XamlUINode*> XamlUINodeArray;
	XamlUINode *_parent;
	XamlUINodeArray _subnodes;

	vec2 _origin;
	XamlTransformGroup _transform;

	mat44 _xform;
};

#endif
