#include "BitmapFont.h"
#include "TextureManager.h"
#include "Render.h"
#include "../Math/Matrix44.h"
#include <fstream>

BitmapFont::BitmapFont(const std::string &fontdesc)
{
	std::ifstream fs(fontdesc);
	if (fs.is_open())
	{
		_desc.Init(fs);

		for (BitmapFontPages::MapType::iterator it = _desc.pages.pages.begin();
			it != _desc.pages.pages.end(); ++it)
		{
			_textures[it->first] = LoadFontTexture(it->second);
		}
	}
}

BitmapFont::~BitmapFont()
{
	TextureManager &texman = TextureManager::GetInstance();

	for (MapType::iterator it = _textures.begin(); it != _textures.end(); ++it)
		texman.ReleaseTexture(it->second);

	_textures.clear();
}

Texture* BitmapFont::LoadFontTexture(const std::string &name)
{
	std::string res = std::string("data/fonts/") + name;
	return TextureManager::GetInstance().GetTexture(res);
}

void BitmapFont::Draw(const vec2 &topleft, const std::string &text)
{
	mat44 transform = mat44::translate(topleft.x, topleft.y, 0);

	float x = 0;
	float y = 0;

	RenderEngine &r = RenderEngine::GetInstance();

	for (std::string::const_iterator it = text.begin(); it != text.end(); ++it)
	{
		if (_desc.chardefs.find(*it) != _desc.chardefs.end())
		{
			const BitmapFontChar &chardef = _desc.chardefs[*it];
			vec2 v[4];

			v[0].x = x + chardef.xoffset;
			v[0].y = y + chardef.yoffset;

			v[1].x = x + chardef.xoffset + chardef.width;
			v[1].y = y + chardef.yoffset + chardef.height;

			v[2].x = x + chardef.xoffset;
			v[2].y = y + chardef.yoffset + chardef.height;

			v[3].x = x + chardef.xoffset + chardef.width;
			v[3].y = y + chardef.yoffset;

			for (int i = 0; i < 4; i++)
				v[i].ApplyTransform(transform);

			Texture *tex = _textures[chardef.page];

			if (tex)
			{
				r.BindTexture(tex ? tex->TextureID() : 0);

				float uv[4] =
				{
					(float)chardef.x / tex->Width(),
					(float)chardef.y / tex->Height(),
					(float)(chardef.x + chardef.width) / tex->Width(),
					(float)(chardef.y + chardef.height) / tex->Height(),
				};

				r.Triangle(
					RenderVertex(Vertex(v[0]), RenderUV(uv[0], uv[1])),
					RenderVertex(Vertex(v[1]), RenderUV(uv[2], uv[3])),
					RenderVertex(Vertex(v[2]), RenderUV(uv[0], uv[3])));

				r.Triangle(
					RenderVertex(Vertex(v[1]), RenderUV(uv[2], uv[3])),
					RenderVertex(Vertex(v[0]), RenderUV(uv[0], uv[1])),
					RenderVertex(Vertex(v[3]), RenderUV(uv[2], uv[1])));
			}

			x += chardef.xadvance;
		}
	}
}
