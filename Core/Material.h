#pragma once

#include <memory>

namespace Engine
{
	class Color
	{
	public:
		Color() = default;
		Color(unsigned int _r, unsigned int _g, unsigned int _b) :r(_r), g(_g), b(_b) {};

		void setColor(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a);

		glm::vec4 getVec4() const;

	public:
		unsigned int r, g, b, a = 255;
	};

	class Texture;
	class Material
	{
	public:
		Material();
		virtual ~Material();

	public:
		void apply(); // if texture is not binded, use color
		void bindTexture(Texture* texture);
		void enableTexture(bool enable = true);

		void setColor(const Color& color);
		void setColor(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

		Color getColor() const;

	private:
		Color m_color;
		std::shared_ptr<Texture> m_texture;
	};
}