#include "Radar.hpp"

#include <random>

Radar::Radar(double maxRange, double detectionProbability)
    : PerceptionSensor(maxRange), m_detectionProbability(detectionProbability)
{
}

Radar::~Radar()
{
}

bool Radar::detectObject(const Object& obj) const
{
    if (obj.getDistance() > m_maxRange)
    {
        return false;
    }

    if (obj.getMaterial() == Material::METAL)
    {
        return true;
    }

    // PLASTIC: detect with probability m_detectionProbability
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng) < m_detectionProbability;
}
