#include <iostream>
#include "objects.hpp"

int main()
{
    Rectangle r(5.0, 2.0);
    std::cout << r.get_area() << std::endl;

    Triangle t(5.0, 2.0);
    std::cout << t.get_area() << std::endl;
}