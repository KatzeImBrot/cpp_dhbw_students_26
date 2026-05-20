#ifndef RADAR_HPP
#define RADAR_HPP

#include "PerceptionSensor.hpp"
#include "Object.hpp"

class Radar : public PerceptionSensor
{
public:
    Radar(double maxRange, double detectionProbability);
    ~Radar();

    bool detectObject(const Object& obj) const;

private:
    double m_detectionProbability;   // 0.0 to 1.0, for PLASTIC objects
};

#endif // RADAR_HPP
