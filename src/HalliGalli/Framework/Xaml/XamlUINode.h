#ifndef __XAML_UI_NODE_H__
#define __XAML_UI_NODE_H__

#include "XamlTypes.h"
#include "../Input/InputMessage.h"
#include <vector>

class XamlUINode
{
public:
	XamlUINode();
	virtual ~XamlUINode();

	virtual void Update(float delta);
	virtual void Render();
	virtual bool HandleInput(const InputMessage &message);

	void AddSubNode(XamlUINode *node);
	void RemoveFromParent();

	const mat44& XForm() const;

private:
	XamlUINode(const XamlUINode&);
	XamlUINode& operator =(const XamlUINode&);

protected:
	typedef std::vector<XamlUINode*> XamlUINodeArray;
	XamlUINode *_parent;
	XamlUINodeArray _subnodes;

	mat44 _xform;
};

#endif
