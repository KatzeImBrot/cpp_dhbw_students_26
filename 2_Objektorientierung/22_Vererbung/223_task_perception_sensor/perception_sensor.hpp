#include <iostream>

class Perception_Sensor{
    public:
    Perception_Sensor(){};

    Perception_Sensor(double max_range){
        m_maxRange = max_range;
    };

    ~Perception_Sensor(){};

    void print_max_range();

    protected:
    double m_maxRange;
};