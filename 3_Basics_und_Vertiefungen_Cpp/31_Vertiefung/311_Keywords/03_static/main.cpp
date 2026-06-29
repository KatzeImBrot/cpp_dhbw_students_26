
#include <iostream>
#include <cmath>
#include "HumidityCalculator.hpp"

/// \brief Get Sensor Inputs from User
/// \param [in] sensorData as reference to SensorData struct
/// \return void, user inputs are assigned to the struct members
void getSensorInputs(SensorData &sensorData)
{
    std::cout << "Temperature in °C: ";
    std::cin >> sensorData.temperature;

    std::cout << "Relative humidity in %: ";
    std::cin >> sensorData.relativeHumidity;
}

int main()
{
    SensorData sensorData;
    unsigned int numberOfInstances;

    std::cout << "Enter the number of instances to create: ";
    std::cin >> numberOfInstances;

    std::cout << "------------- HUMIDITY CALCULATOR INSTANCES (HCI) -------------" << std::endl;

    for (unsigned int i = 0; i < numberOfInstances; ++i)
    {
        getSensorInputs(sensorData);

        const HumidityCalculator humCalculator(sensorData);
        const double absoluteHumidity = humCalculator.calculateAbsoluteHumidity();
        std::cout << "Absolute humidity: " << absoluteHumidity << " g/m³" << std::endl;

        std::cout << "------------- Instance " << humCalculator.getInstanceCount() << " -------------" << std::endl;
    }

    std::cout << "Total instances created: " << HumidityCalculator::getInstanceCount() << std::endl;
    std::cout << "-------------------- END OF HCI --------------------" << std::endl;

    return 0;
}
