#include <iostream>

enum class Material{
    PLASTIC,
    METAL
};

class Object{
    public:
        Object(){};

        Object(double distance, Material material){};

        ~Object(){};

        double get_distance();

        Material get_material();

    private:
    double m_distance;
    Material m_material;
};