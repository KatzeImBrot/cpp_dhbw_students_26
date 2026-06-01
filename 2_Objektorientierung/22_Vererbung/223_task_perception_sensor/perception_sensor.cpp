#include "perception_sensor.hpp"

Perception_Sensor::Perception_Sensor(){};

Perception_Sensor::Perception_Sensor(double max_range)
{
    m_maxRange = max_range;
};

Perception_Sensor::~Perception_Sensor(){};

void Perception_Sensor::print_max_range()
{
    std::cout << m_maxRange << std::endl;
}