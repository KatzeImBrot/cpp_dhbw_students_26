#include "lidar.hpp"

Lidar::Lidar() {};

Lidar::Lidar(double max_range)
{
    m_maxRange = max_range;
};

Lidar::~Lidar() {};

bool Lidar::detect_object(Object obj)
{
}