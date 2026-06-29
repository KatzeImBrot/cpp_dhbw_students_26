#ifndef HUMIDITY_CALCULATOR_HPP
#define HUMIDITY_CALCULATOR_HPP

#include <cmath>
#include <iostream>

struct SensorData
{
    double temperature;
    double relativeHumidity;
};

class HumidityCalculator
{
public:
    HumidityCalculator(const SensorData &sensorData);

    virtual ~HumidityCalculator();

    double calculateAbsoluteHumidity() const;

    double getTemperature() const;

    double getHumidity() const;

private:
    const SensorData m_sensorData;
    static constexpr double MAGNUS_BASE_HPA{6.112};
    static constexpr double MAGNUS_COEFF_A{17.67};
    static constexpr double MAGNUS_COEFF_B_C{243.5};
    static constexpr double HUMIDITY_CONVERSION_FACTOR{2.1674};
    static constexpr double KELVIN_OFFSET{273.15};
    // Compile-Zeit-Berechnung: Kombination von MAGNUS_BASE_HPA und HUMIDITY_CONVERSION_FACTOR
    static constexpr double MAGNUS_HUMIDITY_FACTOR{MAGNUS_BASE_HPA * HUMIDITY_CONVERSION_FACTOR};
};

#endif // !HUMIDITY_CALCULATOR_HPP