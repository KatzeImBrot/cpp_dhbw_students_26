#include "Vehicle.hpp"

#include <iostream>
#include <cmath>

Vehicle::Vehicle(std::string name, double position, float consumption)
   : m_name(name), m_position(position), m_avgConsumption(consumption),
   m_totalConsumption(0), m_currentGas(50.0)
{
   std::cout << "--- CONSTRUCTOR ---" << std::endl;
}

Vehicle::~Vehicle()
{
   std::cout << "--- DESTRUCTOR ---" << std::endl;
}

void Vehicle::driveTo(double position)
{
   double distance = std::abs(m_position - position);
   double neededGas = distance * m_avgConsumption / 100.0;
   bool distanceDrivable = (neededGas <= m_currentGas);

   if (distanceDrivable)
   {
      m_position = position;
      m_currentGas -= neededGas;
      std::cout << "--- New position is: " << m_position << std::endl;
      std::cout << "    " << "Current gas is: " << m_currentGas << std::endl;

      m_totalConsumption += neededGas;
   }
   else
   {
      std::cout << "!!! Gastank too low to drive to new position !!!" << std::endl;
   }
}

void Vehicle::fillUpGas()
{
   m_currentGas = 50.0;
}

void Vehicle::printConsumption()
{
   std::cout << "    " << "Total consumption is " << m_totalConsumption << std::endl;
}

void Vehicle::printName()
{
   std::cout << "    " << "Name of vehicle is: " << m_name << std::endl;
   std::cout << "    " << "Maximum distance with current gas is: " << m_currentGas / m_avgConsumption * 100 << " km" << std::endl;
}
