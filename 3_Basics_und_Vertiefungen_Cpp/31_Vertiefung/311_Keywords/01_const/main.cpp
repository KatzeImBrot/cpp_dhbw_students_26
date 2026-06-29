#include <iostream>
#include <cmath>

const double MAGNUS_BASE_HPA = 6.112;
const double MAGNUS_COEFF_A = 17.67;
const double MAGNUS_COEFF_B_C = 243.5;
const double HUMIDITY_CONVERSION_FACTOR = 2.1674;
const double KELVIN_OFFSET = 273.15;

struct SensorData
{
    double temperature;
    double relativeHumidity;
};

void getSensorInputs(SensorData &sensorData)
{
    std::cout << "Temperature in °C: ";
    std::cin >> sensorData.temperature;

    std::cout << "Relative Humidity in %: ";
    std::cin >> sensorData.relativeHumidity;
};

double calculateAbsoluteHumidity(const SensorData &sensorData)
{
    const double numerator = MAGNUS_BASE_HPA * std::exp((MAGNUS_COEFF_A * sensorData.temperature) / (sensorData.temperature + MAGNUS_COEFF_B_C)) * sensorData.relativeHumidity * HUMIDITY_CONVERSION_FACTOR;
    const double denominator = KELVIN_OFFSET + sensorData.temperature;
    const double absoluteHumidity = numerator / denominator;
    return absoluteHumidity;
};

int main()
{
    SensorData sensorData;

    getSensorInputs(sensorData);

    const double absoluteHumidity = calculateAbsoluteHumidity(sensorData);
    std::cout << "Absolute Humidity: " << absoluteHumidity << " g/m³" << std::endl;

    return 0;
}