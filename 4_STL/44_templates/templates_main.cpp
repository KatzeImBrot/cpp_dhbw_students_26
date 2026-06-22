#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>

void printVector(const std::vector<std::string> &vec);

void printList(const std::list<std::string> &inList);

//template function
// TODO

//template class
// TODO

int main()
{
    std::vector<std::string> myVector{"10", "20", "30"};
    std::list<std::string> myList{"10", "20", "30"};

    printVector(myVector);
    printList(myList);

    printContainer<std::vector<std::string>>(myVector);
    printContainer<std::list<std::string>>(myList);

    ContainerPrinter<std::vector<std::string>, ' '> vectorPrinter;
    vectorPrinter(myVector);
    ContainerPrinter<std::list<std::string>, '|'> listPrinter;
    listPrinter(myList);

    return 0;
}

void printVector(const std::vector<std::string> &vec)
{
    for (const std::string &item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void printList(const std::list<std::string> &inList)
{
    for (const std::string &item : inList)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
