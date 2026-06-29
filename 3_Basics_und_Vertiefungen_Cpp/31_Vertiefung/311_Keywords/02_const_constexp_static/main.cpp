#include <iostream>
#include <cmath>

#include "HumidityCalculator.hpp"

/// \brief Get Sensor Inputs from User
/// \return void
void getSensorInputs(SensorData &sensorData)
{
    std::cout << "Temperature in °C: ";
    std::cin >> sensorData.temperature;

    std::cout << "Relative Humidity in %: ";
    std::cin >> sensorData.relativeHumidity;
};

int main()
{
    SensorData sensorData;

    getSensorInputs(sensorData);

    HumidityCalculator humidityCalc(sensorData);

    const double absoluteHumidity = humidityCalc.calculateAbsoluteHumidity();
    std::cout << "Absolute Humidity: " << absoluteHumidity << " g/m³" << std::endl;

    return 0;
}