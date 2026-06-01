#include "perception_sensor.hpp"
#include "object.hpp"

class Lidar: public Perception_Sensor{
    public:
    Lidar(){};

    Lidar(double max_range);

    ~Lidar(){};

    bool detect_object(Object obj);
};