
#include "HumidityCalculator.hpp"

HumidityCalculator::HumidityCalculator(const SensorData &sensorData)
    : m_sensorData(sensorData)
{
    m_instanceCount++;
}

int HumidityCalculator::m_instanceCount = 0;

double HumidityCalculator::calculateAbsoluteHumidity() const
{
    const double numerator = MAGNUS_HUMIDITY_FACTOR * std::exp((MAGNUS_COEFF_A * m_sensorData.temperature) / (m_sensorData.temperature + MAGNUS_COEFF_B_C)) * m_sensorData.relativeHumidity;
    const double denominator = KELVIN_OFFSET + m_sensorData.temperature;
    const double absoluteHumidity = numerator / denominator;
    return absoluteHumidity;
}

double HumidityCalculator::getTemperature() const
{
    return m_sensorData.temperature;
}

double HumidityCalculator::getRelativeHumidity() const
{
    return m_sensorData.relativeHumidity;
}
