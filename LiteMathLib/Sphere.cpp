#include "pch.h"

#include "Sphere.h"

using namespace Engine;

Engine::Point Engine::Sphere::getCenter() const
{
	return m_center;
}

float Engine::Sphere::getRadius() const
{
	return m_radius;
}
