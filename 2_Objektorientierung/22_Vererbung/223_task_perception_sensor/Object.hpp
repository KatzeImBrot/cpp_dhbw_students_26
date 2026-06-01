#ifndef OBJECT_HPP
#define OBJECT_HPP

enum class Material
{
    PLASTIC,
    METAL
};

class Object
{
public:
    Object(double distance, Material material);

    double getDistance() const;
    Material getMaterial() const;

private:
    double m_distance;     // in meters
    Material m_material;
};

#endif // OBJECT_HPP
