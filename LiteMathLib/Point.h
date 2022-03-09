#pragma once

#include <glm/glm.hpp>

namespace Engine {


	class Point
	{
	public:
		Point() = default;
		Point(float x, float y, float z);
		~Point() = default;

		Point operator * (float scale);
		Point& operator *= (float scale);

		float operator * (const Point& pt);  // dot product

	public:
		void set(float x, float y, float z);
		glm::vec3 getVec3() const;

		Point scale(float x = 1.0f, float y = 1.0f, float z = 1.0f) const;
		Point& scaleSelf(float x = 1.0f, float y = 1.0f, float z = 1.0f);

	private:
		glm::vec3 m_point = glm::vec3(0.0f); // homogenous  x,y,z,0
	};

	typedef Point Vector; // x,y,z,1
}
