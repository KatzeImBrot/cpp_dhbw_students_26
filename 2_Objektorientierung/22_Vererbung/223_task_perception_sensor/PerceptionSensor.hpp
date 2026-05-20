#ifndef PERCEPTIONSENSOR_HPP
#define PERCEPTIONSENSOR_HPP

class PerceptionSensor
{
public:
    PerceptionSensor(double maxRange);
    ~PerceptionSensor();

    void printMaxRange() const;

protected:
    double m_maxRange;     // in meters
};

#endif // PERCEPTIONSENSOR_HPP
