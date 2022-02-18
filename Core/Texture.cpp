#include "pch.h"


#include "Texture.h"

using namespace Engine;

GLuint Texture::m_currentID = 0;

Texture::Texture()
{
	m_id = m_currentID;
	m_currentID++;
}

Texture::~Texture()
{

}

Texture* Texture::create2DTexture(const std::string& srcPath)
{
	Texture* texture = new Texture();
	texture->m_srcPath = srcPath;
	texture->setTarget(GL_TEXTURE_2D);
	return texture;
}

void Texture::setTarget(GLenum target)
{

}

void Texture::setWrap(GLint wrapS, GLint wrapT)
{

}

void Texture::setFilter(GLint minFilter, GLint maxFilter)
{

}

void Texture::enable(bool enable /*= true*/)
{

}

void Texture::load()
{

}

void Texture::unload()
{

}

void Texture::apply()
{

}
