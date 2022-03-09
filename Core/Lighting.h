#pragma once

#include <map>
#include <memory>

#include "Object.h"

namespace Engine {

	class LightingFactory;

	// wrapper of GL light source
	class Light : public MovableObject {
	public:
		Light();
		Light(const std::string& name);
		~Light();

		virtual void apply() override;

	public:
		bool m_isEnable = true;
		bool m_useColorMaterial = true;

		glm::vec4 m_position;
		glm::vec4 m_ambient;
		glm::vec4 m_diffuse;
		glm::vec4 m_specular;

	private:
		unsigned short m_id = 0;

		friend class LightingFactory;
	};

	// Light factory
	class LightingFactory {
	public:
		static Light* getOrCreateLight(unsigned int id);

	private:
		static std::map<unsigned int, std::shared_ptr<Light>> m_lights; // id / light

		LightingFactory() = default;
		~LightingFactory() = default;
	};
}