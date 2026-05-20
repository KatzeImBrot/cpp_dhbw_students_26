#include "PerceptionSensor.hpp"

#include <iostream>

PerceptionSensor::PerceptionSensor(double maxRange)
    : m_maxRange(maxRange)
{
}

PerceptionSensor::~PerceptionSensor()
{
}

void PerceptionSensor::printMaxRange() const
{
    std::cout << "Max range: " << m_maxRange << " m" << std::endl;
}
