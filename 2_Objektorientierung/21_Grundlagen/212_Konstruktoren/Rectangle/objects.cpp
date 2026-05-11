#include <iostream>

#include "objects.hpp"

Rectangle::Rectangle() {};

Rectangle::Rectangle(float l, float w)
    : m_length(l), m_width(w) {};

Rectangle::~Rectangle() {};

void Rectangle::set_length(float l)
{
    m_length = l;
}

void Rectangle::set_width(float w)
{
    m_width = w;
}

float Rectangle::get_area()
{
    return m_width * m_length;
}

Triangle::Triangle() {};

Triangle::Triangle(float h, float b)
    : m_height(h), m_base(b) {};

Triangle::~Triangle() {};

void Triangle::set_height(float h)
{
    m_height = h;
}

void Triangle::set_base(float b)
{
    m_base = b;
}

float Triangle::get_area()
{
    return (m_base * m_height / 2);
}
