#include "object.hpp"

Object::Object() {};

Object::Object(double distance, Material material)
{
    m_distance = distance;
    m_material = material;
}

Object::~Object() {};

double Object::get_distance()
{
    return m_distance;
}

Material Object::get_material()
{
    return m_material;
}