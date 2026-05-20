#include "Object.hpp"

Object::Object(double distance, Material material)
    : m_distance(distance), m_material(material)
{
}

double Object::getDistance() const
{
    return m_distance;
}

Material Object::getMaterial() const
{
    return m_material;
}
