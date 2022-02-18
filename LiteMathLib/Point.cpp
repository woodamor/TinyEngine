#include "pch.h"

#include "Point.h"

using namespace Engine;

Point::Point(float x, float y, float z)
{
	m_point = glm::vec3(x, y, z);
}

void Point::set(float x, float y, float z)
{
	m_point = glm::vec3(x, y, z);
}

glm::vec3 Point::getVec3() const
{
	return m_point;
}

Point Point::operator*(float scale)
{
	Point pt = *this;
	pt.m_point *= scale;
	return pt;
}

Point& Point::operator*=(float scale)
{
	m_point *= scale;
	return *this;
}

float Point::operator*(const Point& pt)
{
	return glm::dot(m_point, pt.m_point);
}

Point Point::scale(float x /*= 1.0f*/, float y /*= 1.0f*/, float z /*= 1.0f*/) const
{
	Point pt = *this;

	pt.m_point.x *= x;
	pt.m_point.y *= y;
	pt.m_point.z *= z;

	return pt;
}

Point& Point::scaleSelf(float x /*= 1.0f*/, float y /*= 1.0f*/, float z /*= 1.0f*/)
{
	m_point.x *= x;
	m_point.y *= y;
	m_point.z *= z;
	return *this;
}