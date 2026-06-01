#include <iostream>

// Base class
class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
   }

   virtual ~Shape()
   {
   }

   void setWidth(double width)
   {
      m_width = width;
   }

   void setHeight(double height)
   {
      m_height = height;
   }

   virtual double getArea() = 0; // pure virtual - must be implemented by derived classes

   void printArea()
   {
      std::cout << "Area: " << getArea() << std::endl; // calls derived getArea() polymorphically
   }

   // Can be changed only by child classes (not by any other)
protected:
   double m_width;
   double m_height;
};

// Derived class
class Rectangle : public Shape // Inheritance from Shape class (base class)
{
public:
   Rectangle(double width, double height)
       : Shape(width, height) // Call the constructor of the base class
   {
   }

   ~Rectangle() override
   {
   }

   double getArea() override
   {
      return m_width * m_height;
   }
};

// Derived class
class Triangle : public Shape // Inheritance from Shape class (base class)
{
public:
   Triangle(double base, double height)
       : Shape(base, height) // Call the constructor of the base class (base -> m_width)
   {
   }

   ~Triangle() override
   {
   }

   double getArea() override
   {
      return m_width * m_height / 2.0;
   }
};

void printShapeArea(Shape* shape)
{
   shape->printArea(); // calls getArea() polymorphically
}

int main()
{
   Rectangle rect(10, 20);
   Triangle tri(10, 20);

   printShapeArea(&rect); // calls Rectangle::getArea() polymorphically
   printShapeArea(&tri);  // calls Triangle::getArea() polymorphically

   return 0;
}

