#include "perception_sensor.hpp"
#include "object.hpp"

class Radar: public Perception_Sensor{
    public:
    Radar(){};

    Radar(double max_range, double detection_probability);

    ~Radar(){};

    bool detect_object(Object obj);

    private:
    double detection_probability;
};