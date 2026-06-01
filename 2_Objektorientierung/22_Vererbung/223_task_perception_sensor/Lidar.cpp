#include "Lidar.hpp"

Lidar::Lidar(double maxRange)
    : PerceptionSensor(maxRange)
{
}

Lidar::~Lidar()
{
}

bool Lidar::detectObject(const Object& obj) const
{
    if (obj.getDistance() > m_maxRange)
    {
        return false;
    }

    return true;
}
