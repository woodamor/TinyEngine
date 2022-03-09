#include "pch.h"


#include "Lighting.h"

namespace Engine {

	Light::Light()
	{

	}

	Light::Light(const std::string& name): MovableObject(name)
	{

	}

	Light::~Light()
	{

	}

	void Light::apply()
	{
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glm::value_ptr(m_ambient));

		glLightfv(m_id, GL_POSITION, glm::value_ptr(m_position));
		glLightfv(m_id, GL_DIFFUSE, glm::value_ptr(m_diffuse));
		glLightfv(m_id, GL_SPECULAR, glm::value_ptr(m_specular));

		if (m_isEnable) {
			glEnable(m_id);
		}
		else {
			glDisable(m_id);
		}

		glEnable(GL_LIGHT0 + m_id);
	}


	//////////////////////////////////////////////////////////////////////////
	std::map<unsigned int, std::shared_ptr<Light>> LightingFactory::m_lights; // id / light

	Light* LightingFactory::getOrCreateLight(unsigned int id)
	{
		auto it = m_lights.find(id);
		if (it != m_lights.end()) return it->second.get();

		m_lights[id] = std::make_shared<Light>();
		return m_lights[id].get();
	}
}