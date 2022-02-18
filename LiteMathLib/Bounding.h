#pragma once

#include <memory>

#include "Point.h"

namespace Engine {

	class AABB
	{
	public:
		AABB() = default;
		AABB(const Point& min, const Point& max) :m_min(min), m_max(max) {};
		~AABB() = default;

		void setBox(const Point& min, const Point& max);
		Point getMin() const;
		Point getMax() const;

		Point getCenter() const;
		float getRadius() const;

	private:
		Point m_min, m_max;
	};

	class Sphere;
	class BoundingShpere
	{
	public:
		BoundingShpere() = default;
		BoundingShpere(const Point& center, float radius) :m_center(center), m_radius(radius) {};
		~BoundingShpere() = default;

		Point getCenter() const;
		float getRadius() const;

	private:
		Point m_center;
		float m_radius;

		std::unique_ptr<Sphere> m_sphere;
	};
}