
#include <iostream>
#include <cmath>
#include "HumidityCalculator.hpp"
#include "HumidityCalculatorTester.hpp"

int main()
{
    SensorData sensorData;
    unsigned int numberOfInstances;

    std::cout << "Enter the number of instances to create: ";
    std::cin >> numberOfInstances;

    std::cout << "------------- HUMIDITY CALCULATOR INSTANCES (HCI) -------------" << std::endl;

    for (auto i = 0u; i < numberOfInstances; ++i)
    {
        std::cout << "Temperature in °C: ";
        std::cin >> sensorData.temperature;

        std::cout << "Relative humidity in %: ";
        std::cin >> sensorData.relativeHumidity;

        const auto humCalculator{HumidityCalculator(sensorData)};
        HumidityCalculatorTester::testPrivateMembers(humCalculator);

        std::cout << "------------- Instance " << humCalculator.getInstanceCount() << " -------------" << std::endl;
    }

    std::cout << "Total instances created: " << HumidityCalculator::getInstanceCount() << std::endl;
    std::cout << "-------------------- END OF HCI --------------------" << std::endl;

    return 0;
}
