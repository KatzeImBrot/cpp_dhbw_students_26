#include <iostream>

class Rectangle
{
public:
    // Default constructor
    Rectangle()
    {
    }

    // Overloaded constructor
    Rectangle(double width, double height)
        : m_width(width), m_height(height)
    {
    }

    // Destructor
    ~Rectangle()
    {
    }

    // set width
    void setWidth(double width)
    {
        m_width = width;
    }

    // set height
    void setHeight(double height)
    {
        m_height = height;
    }

    // calc area
    double calcArea()
    {
        return m_height * m_width;
    }

private:
    double m_width;
    double m_height;
};

class Triangle
{
public:
    // Constructor
    Triangle(double base, double height)
        : m_base(base), m_height(height)
    {
    }

    // Destructor
    ~Triangle()
    {
    }

    // set base
    void setBase(double base)
    {
        m_base = base;
    }

    // set height
    void setHeight(double height)
    {
        m_height = height;
    }

    // calc area
    double calcArea()
    {
        return m_base * m_height / 2.0;
    }

private:
    double m_base;
    double m_height;
};

int main()
{
    Rectangle myRectangle(2.0, 3.0);
    std::cout << myRectangle.calcArea() << std::endl;

    Triangle myTriangle(6.0, 4.0);
    std::cout << myTriangle.calcArea() << std::endl;

    return 0;
}
