#include "pch.h"

#include "Texture.h"

#include "Material.h"

using namespace Engine;

void Color::setColor(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

glm::vec4 Color::getVec4() const
{
	return glm::vec4(r, g, b, a);
}

Material::Material()
{

}

Material::~Material()
{

}

void Material::apply()
{
	if (m_texture) {
		m_texture->apply();
	}
	else
	{

	}
}

void Material::bindTexture(Texture* texture)
{
	m_texture.reset(texture);
}

void Material::setColor(const Color& color)
{
	m_color = color;
}

void Material::setColor(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	m_color.setColor(r, g, b, a);
}

Color Material::getColor() const
{
	return m_color;
}

void Material::enableTexture(bool enable /*= true*/)
{
	if (m_texture) {
		m_texture->enable(enable);
	}
}