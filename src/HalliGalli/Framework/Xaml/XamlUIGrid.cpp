#include "XamlUIGrid.h"

void XamlUIGrid::Update(float delta)
{
	if (_parent)
	{
		_xform = _parent->XForm();
	}
	else
	{
		_xform = mat44::identity();
	}

	for (XamlUINodeArray::iterator it = _subnodes.begin(); it != _subnodes.end(); ++it)
		(*it)->Update(delta);
}
