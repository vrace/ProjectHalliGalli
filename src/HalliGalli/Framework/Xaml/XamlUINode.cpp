#include "XamlUINode.h"
#include <algorithm>
#include <assert.h>

XamlUINode::XamlUINode()
	: _parent(NULL)
	, _origin(0.5f, 0.5f)
	, _xform(mat44::identity())
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
	mat44 translate = mat44::translate(_transform.translate.x, _transform.translate.y, 0);
	mat44 scale = mat44::scale(_transform.scale.x, _transform.scale.y, 1);

	_xform = _parent ? (scale * translate) * _parent->_xform : (scale * translate);

	for (XamlUINodeArray::iterator it = _subnodes.begin(); it != _subnodes.end(); ++it)
		(*it)->Update(delta);
}

void XamlUINode::Render()
{
	for (XamlUINodeArray::iterator it = _subnodes.begin(); it != _subnodes.end(); ++it)
		(*it)->Render();
}

void XamlUINode::AddSubNode(XamlUINode *node)
{
	assert(!node->_parent);

	node->_parent = this;
	_subnodes.push_back(node);
}

void XamlUINode::RemoveFromParent()
{
	if (_parent)
	{
		XamlUINodeArray::iterator it = std::find(
			_parent->_subnodes.begin(),
			_parent->_subnodes.end(),
			this);

		if (it != _parent->_subnodes.end())
			_parent->_subnodes.erase(it);
	}

	delete this;
}

const mat44& XamlUINode::XForm() const
{
	return _xform;
}
