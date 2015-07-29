#include "XamlUIDrawable.h"
#include "../Render/Render.h"
#include "../Render/TextureManager.h"

XamlUIDrawable::XamlUIDrawable(const XamlDrawable &drawable)
	: _size(drawable.size)
	, _origin(drawable.origin)
	, _transform(drawable.transform)
{
	_transform.translate.x += _size.width * 0.5f;
	_transform.translate.y += _size.height * 0.5f;
}

void XamlUIDrawable::Update(float delta)
{
	mat44 translate = mat44::translate(
		_transform.translate.x, _transform.translate.y, 0);
	mat44 scale = mat44::scale(
		_transform.scale.x, _transform.scale.y, 1);
	mat44 rotate = mat44::rotateZ(_transform.rotate * 3.14159f / 180);

	_xform = scale * (rotate * (translate * (_parent ? _parent->XForm() : mat44::identity())));

	XamlUINode::Update(delta);
}

void XamlUIDrawable::Draw(const Texture *texture)
{
	if (texture)
	{
		RenderEngine &r = RenderEngine::GetInstance();

		r.BindTexture(texture->TextureID());

		vec2 v[4];

		v[0].x = -_size.width * _origin.x;
		v[0].y = -_size.height * _origin.y;

		v[1].x = _size.width * (1.0f - _origin.x);
		v[1].y = _size.height * (1.0f - _origin.y);

		v[2].x = -_size.width * _origin.x;
		v[2].y = _size.height * (1.0f - _origin.y);

		v[3].x = _size.width * (1.0f - _origin.x);
		v[3].y = -_size.height * _origin.y;

		for (int i = 0; i < 4; i++)
			v[i].ApplyTransform(XForm());

		r.Triangle(
			RenderVertex(Vertex(v[0]), RenderUV(0, 0)),
			RenderVertex(Vertex(v[1]), RenderUV(1, 1)),
			RenderVertex(Vertex(v[2]), RenderUV(0, 1)));

		r.Triangle(
			RenderVertex(Vertex(v[1]), RenderUV(1, 1)),
			RenderVertex(Vertex(v[0]), RenderUV(0, 0)),
			RenderVertex(Vertex(v[3]), RenderUV(1, 0)));
	}
}

Texture* XamlUIDrawable::GetTexture(const std::string &image)
{
	std::string src = "data/images/" + image;
	return TextureManager::GetInstance().GetTexture(src);
}

void XamlUIDrawable::ReleaseTexture(Texture *texture)
{
	TextureManager::GetInstance().ReleaseTexture(texture);
}
