#include <iostream>
#include <cmath>

#include "task_vehicle.hpp"

// Default constructor
Vehicle::Vehicle(std::string name, double position, float consumption)
    : m_name(name), m_position(position), m_avgConsumption(consumption),
      m_totalConsumption(0), m_currentGas(50.0)
{
   std::cout << "--- CONSTRUCTOR ---" << std::endl;
};

// Destructor
Vehicle::~Vehicle()
{
   std::cout << "--- DESTRUCTOR ---" << std::endl;
};

// change position of vehicle to new position.
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
      std::cout << "!!! Gas tank too low to drive to new position !!!" << std::endl;
   }
};

// fill up gas tank to 50 l
void Vehicle::fillUpGas()
{
   m_currentGas = 50.0;
};

// prints total consumption to console
void Vehicle::printConsumption()
{
   std::cout << "    " << "Total consumption is " << m_totalConsumption << std::endl;
};

// print name of vehicle to console and the maximum distance it can drive with the current gas
void Vehicle::printName()
{
   std::cout << "    " << "Name of vehicle is: " << m_name << std::endl;
   std::cout << "    " << "Maximum distance with current gas is: " << m_currentGas / m_avgConsumption * 100 << " km" << std::endl;
};
