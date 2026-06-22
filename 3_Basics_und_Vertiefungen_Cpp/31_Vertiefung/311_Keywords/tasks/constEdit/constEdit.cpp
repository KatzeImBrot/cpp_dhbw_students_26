#include <iostream>

class Circle
{
private:
    const double m_radius;
    static constexpr double m_PI = 3.14159;
    double m_area;

public:
    Circle(double r) : m_radius(r)
    {
        calcArea();
    }

    double getRadius() const
    {
        return m_radius;
    }

    void calcArea()
    {
        m_area = m_PI * m_radius * m_radius;
    }

    double getArea() const
    {
        return m_area;
    }
};

int main()
{
    const Circle myCircle(5.0);
    std::cout << "Radius: " << myCircle.getRadius() << std::endl;
    std::cout << "Area: " << myCircle.getArea() << std::endl;

    return 0;
}