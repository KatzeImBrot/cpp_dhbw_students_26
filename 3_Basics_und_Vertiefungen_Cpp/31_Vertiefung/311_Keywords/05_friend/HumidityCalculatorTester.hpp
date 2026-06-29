
#ifndef HUMIDITY_CALCULATOR_TESTER_HPP
#define HUMIDITY_CALCULATOR_TESTER_HPP

#include <iostream>
#include "HumidityCalculator.hpp"

class HumidityCalculatorTester
{
public:
    HumidityCalculatorTester(const HumidityCalculator &calculator);

    virtual ~HumidityCalculatorTester();

    static void testPrivateMembers(const HumidityCalculator &calculator)
    {
        std::cout << "MY FRIEND TESTER SAYS ABSOLUTE HUMIDITY: "
                  << calculator.calculateAbsoluteHumidity() << " g/m³\n";
    };
};

#endif // HUMIDITY_CALCULATOR_TESTER_HPP
