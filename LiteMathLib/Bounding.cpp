#include "pch.h"

#include "Sphere.h"

#include "Bounding.h"

using namespace Engine;

void Engine::AABB::setBox(const Point& min, const Point& max)
{
	m_min = min;
	m_max = max;
}

Engine::Point Engine::AABB::getMin() const
{
	return m_min;
}

Engine::Point Engine::AABB::getMax() const
{
	return m_min;
}

Engine::Point Engine::AABB::getCenter() const
{
	return m_min;
}

float Engine::AABB::getRadius() const
{
	return 0.0f;
}

Engine::Point Engine::BoundingShpere::getCenter() const
{
	return m_center;
}

float Engine::BoundingShpere::getRadius() const
{
	return m_radius;
}
