#include "XamlUIImage.h"
#include "../Render/TextureManager.h"
#include "../Render/Render.h"

XamlUIImage::XamlUIImage(const XamlImage &image)
	: _texture(NULL)
	, _size(image.size)
{
	_origin = image.origin;
	_transform = image.transform;

	_transform.translate.x += _size.width * 0.5f;
	_transform.translate.y += _size.height * 0.5f;

	SetImage(image.source);
}

XamlUIImage::~XamlUIImage()
{
	TextureManager::GetInstance().ReleaseTexture(_texture);
}

void XamlUIImage::Render()
{
	if (_texture)
	{
		_texture->Draw(Vertex(_transform.translate),
			Vertex(_size.width * _transform.scale.x, _size.height * _transform.scale.y));

		RenderEngine &r = RenderEngine::GetInstance();

		r.BindTexture(_texture->TextureID());

		vec2 v[4];

		float hw = _size.width * 0.5f;
		float hh = _size.height * 0.5f;

		v[0].x = -_size.width * _origin.x;
		v[0].y = -_size.height * _origin.y;
		
		v[1].x = _size.width * (1.0f - _origin.x);
		v[1].y = _size.height * (1.0f - _origin.y);

		v[2].x = -_size.width * _origin.x;
		v[2].y = _size.height * (1.0f - _origin.x);

		v[3].x = _size.width * (1.0f - _origin.x);
		v[3].y = -_size.height * _origin.y;

		// TODO: transform with xform

		r.Triangle(
			RenderVertex(Vertex(v[0]), RenderUV(0, 0)),
			RenderVertex(Vertex(v[1]), RenderUV(1, 1)),
			RenderVertex(Vertex(v[2]), RenderUV(0, 1)));

		r.Triangle(
			RenderVertex(Vertex(v[1]), RenderUV(1, 1)),
			RenderVertex(Vertex(v[0]), RenderUV(0, 0)),
			RenderVertex(Vertex(v[3]), RenderUV(1, 0)));
	}

	XamlUINode::Render();
}

void XamlUIImage::SetImage(const std::string &image)
{
	TextureManager &texman = TextureManager::GetInstance();

	texman.ReleaseTexture(_texture);
	_texture = texman.GetTexture(image);
}

void XamlUIImage::SetAnchor(const vec2 &origin)
{
	_origin = origin;
}

void XamlUIImage::SetSize(const XamlSize &size)
{
	_size = size;
}
