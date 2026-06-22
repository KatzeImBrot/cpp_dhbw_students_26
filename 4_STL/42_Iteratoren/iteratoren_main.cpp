#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>

void printHelper(std::string &InputString) {
    std::cout << InputString;
}

int main()
{
    std::vector<std::string> myContainer;
    myContainer = {"Hello", ",", " ", "World", "!"};

    // a) range-based-for loop
    // TODO

    //iterator access
    // TODO
    std::cout << "First element: " << *container_iterator << std::endl;
    std::cout << "Second element: " << *(++container_iterator) << std::endl;

    // b) iterator-based loop
    // TODO

    // c1) for_each loop
    // TODO

    // c2) for_each loop with lambda
    // TODO

    return 0;
}
