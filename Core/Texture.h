#pragma once

#include <string>

#include <gl/GL.h>

#include "Resource.h"

namespace Engine
{
	class Texture : public Resource
	{
	public:
		Texture();
		virtual ~Texture();

	public:
		static Texture* create2DTexture(const std::string& srcPath);

		void setTarget(GLenum target);
		void setWrap(GLint wrapS, GLint wrapT);
		void setFilter(GLint minFilter, GLint maxFilter);
		
		void enable(bool enable = true);

		void load();
		void unload();

		virtual void apply() override;

	public:
		static GLuint m_currentID;

		GLuint m_id;				// texture id 
		std::string m_srcPath;		// texture image path

	protected:
		unsigned int m_srcWidth, m_srcHeight;
		GLenum m_target = GL_TEXTURE_2D;
		GLint m_wrapS, m_wrapT, m_wrapR, m_minFilter, m_maxFilter;
	};
}