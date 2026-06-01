#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Vehicle
{
public:
   // Constructor
   Vehicle(std::string name, double position, float consumption);

   // Destructor
   ~Vehicle();

   // change position of vehicle to new position.
   void driveTo(double position);

   // fill up gas tank to 50 l
   void fillUpGas();

   // prints total consumption to console
   void printConsumption();

   // print name of vehicle to console and the maximum distance it can drive with the current gas
   void printName();

private:
   std::string m_name;        // name of vehicle
   double m_position;         // in km
   double m_avgConsumption;   // in l / 100 km
   double m_totalConsumption; // in l
   double m_currentGas;       // in l
};

#endif // VEHICLE_HPP
