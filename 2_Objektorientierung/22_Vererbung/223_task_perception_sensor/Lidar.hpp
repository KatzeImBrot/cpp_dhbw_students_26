#ifndef LIDAR_HPP
#define LIDAR_HPP

#include "PerceptionSensor.hpp"
#include "Object.hpp"

class Lidar : public PerceptionSensor
{
public:
    Lidar(double maxRange);
    ~Lidar();

    bool detectObject(const Object& obj) const;
};

#endif // LIDAR_HPP
