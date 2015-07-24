#include "XamlUIGrid.h"

void XamlUIGrid::Update(float delta)
{
	_xform = _parent ? _parent->XForm() : mat44::identity();

	for (XamlUINodeArray::iterator it = _subnodes.begin(); it != _subnodes.end(); ++it)
		(*it)->Update(delta);
}
