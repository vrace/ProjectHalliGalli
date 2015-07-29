#ifndef __XAML_UI_DRAWABLE_H__
#define __XAML_UI_DRAWABLE_H__

#include "XamlTypes.h"
#include "XamlUINode.h"
#include "../Render/Texture.h"

class XamlUIDrawable : public XamlUINode
{
public:
	XamlUIDrawable(const XamlDrawable &drawable);

	virtual void Update(float delta);

protected:
	void Draw(const Texture *texture);
	Texture* GetTexture(const std::string &name);
	void ReleaseTexture(Texture *texture);

protected:
	vec2 _origin;
	XamlSize _size;
	XamlTransformGroup _transform;
};

#endif
