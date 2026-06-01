#include "Object.hpp"
#include "Radar.hpp"
#include "Lidar.hpp"

#include <iostream>

int main()
{
    Object metalObj(50.0, Material::METAL);
    Object plasticObj(80.0, Material::PLASTIC);
    Object farObj(200.0, Material::METAL);

    Radar myRadar(100.0, 0.7);
    Lidar myLidar(120.0);

    myRadar.printMaxRange();
    myLidar.printMaxRange();

    std::cout << "--- Radar ---" << std::endl;
    std::cout << "Metal  (50m):  " << myRadar.detectObject(metalObj)   << std::endl;
    std::cout << "Plastic(80m):  " << myRadar.detectObject(plasticObj) << std::endl;
    std::cout << "Metal (200m):  " << myRadar.detectObject(farObj)     << std::endl;

    std::cout << "--- Lidar ---" << std::endl;
    std::cout << "Metal  (50m):  " << myLidar.detectObject(metalObj)   << std::endl;
    std::cout << "Plastic(80m):  " << myLidar.detectObject(plasticObj) << std::endl;
    std::cout << "Metal (200m):  " << myLidar.detectObject(farObj)     << std::endl;

    return 0;
}
