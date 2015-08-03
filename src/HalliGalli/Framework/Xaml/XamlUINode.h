#ifndef __XAML_UI_NODE_H__
#define __XAML_UI_NODE_H__

#include "XamlTypes.h"
#include "../Input/InputMessage.h"
#include <vector>
#include <string>

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

	void SetName(const std::string &name);
	const std::string& GetName() const;

private:
	XamlUINode(const XamlUINode&);
	XamlUINode& operator =(const XamlUINode&);

protected:
	typedef std::vector<XamlUINode*> XamlUINodeArray;
	XamlUINode *_parent;
	XamlUINodeArray _subnodes;

	mat44 _xform;
	std::string _name;
};

#endif
