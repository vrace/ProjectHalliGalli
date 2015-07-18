#include "XamlUINode.h"
#include <algorithm>
#include <assert.h>

XamlUINode::XamlUINode()
	: _parent(NULL)
{
}

XamlUINode::~XamlUINode()
{
	for (XamlUINodeArray::iterator it = _subnodes.begin(); it != _subnodes.end(); ++it)
	{
		delete *it;
	}

	_subnodes.clear();
}

void XamlUINode::Update(float delta)
{
	// TODO: we need to update matrix here...
}

void XamlUINode::Render()
{
}

void XamlUINode::AddSubNode(XamlUINode *node)
{
	assert(!node->_parent);

	node->_parent = this;
	_subnodes.push_back(node);
}

void XamlUINode::RemoveFromParent()
{
	assert(_parent);

	XamlUINodeArray::iterator it = std::find(
		_parent->_subnodes.begin(),
		_parent->_subnodes.end(),
		this);

	if (it != _parent->_subnodes.end())
		_parent->_subnodes.erase(it);

	delete this;
}
