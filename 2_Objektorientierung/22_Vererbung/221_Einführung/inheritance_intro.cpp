#include <iostream>

// Base class
class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
   }

   ~Shape()
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

   ~Rectangle()
   {
   }

   double getArea()
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

   ~Triangle()
   {
   }

   double getArea()
   {
      return m_width * m_height / 2.0;
   }
};

int main()
{
   Rectangle rect(10, 20);

   std::cout << "--- Call getArea() from Rectangle class ---" << std::endl;
   std::cout << "Area: " << rect.getArea() << std::endl;

   Triangle tri(10, 20);
   std::cout << "--- Call getArea() from Triangle class ---" << std::endl;
   std::cout << "Area: " << tri.getArea() << std::endl;

   return 0;
}

// Was passiert wenn Sie die Methode setWidth() in der Klasse Shape als private deklarieren?
// Was passiert wenn Sie die protected Sektion in der Klasse Shape als private deklarieren?
