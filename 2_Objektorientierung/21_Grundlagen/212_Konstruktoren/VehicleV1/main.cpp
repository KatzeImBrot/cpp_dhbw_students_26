#include "task_vehicle.hpp"

int main()
{
   Vehicle myVehicle("PORSCHE", 0.0, 10);

   myVehicle.printName();

   for (size_t i = 0; i <= 1000; i += 150)
   {
      myVehicle.driveTo(static_cast<double>(i));
      myVehicle.printConsumption();
   }

   return 0;
}