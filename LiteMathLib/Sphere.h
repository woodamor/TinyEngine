#pragma once

#include "Point.h"

namespace Engine
{
	class Sphere
	{
	public:
		Sphere() = default;
		Sphere(const Point& center, float radius) :m_center(center), m_radius(radius) {};
		~Sphere() = default;

		Point getCenter() const;
		float getRadius() const;

	public:
		Point m_center;
		float m_radius;
	};
}