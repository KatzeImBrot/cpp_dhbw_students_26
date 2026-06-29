// Beispiel: Dieses Programm zeigt typische STL-Werkzeuge im Zusammenspiel.
// Es fuellt Container, transformiert Werte, berechnet Kennzahlen und sortiert
// Strings mit unterschiedlichen Vergleichsfunktionen.

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>

// TODO
// yourWayToSort
// myWayToSort
// printContainer
// printContainer(std::vector<int> container)

int main()
{

    std::vector<std::string> myContainer;
    myContainer = {"Hello", ",", "World", "!", "I", "love", "std::sort", "for these Numbers: "};
    printContainer(myContainer);
    std::cout << std::endl;

    // TODO
    // use fill / ... / iota / transform
    printContainer(numbers);

    //Accumulate all numbers and find minimum element
    std::cout << "Accumulated sum of numbers: " << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
    std::cout << "Minimum Element: " << *std::min_element(numbers.begin(), numbers.end()) << std::endl;
    auto index = std::distance(numbers.begin(), std::min_element(numbers.begin(), numbers.end())); //Get Index
    std::cout << "Index: " << index << std::endl;

    // Convert numbers to strings
    std::vector<std::string> numberStrings;
    numberStrings.reserve(numbers.size());
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(numberStrings),
                   [](int n) { return std::to_string(n); });

    // Move the strings into myContainer
    std::move(numberStrings.begin(), numberStrings.end(), std::back_inserter(myContainer));
    printContainer(myContainer);

    //Sort string container using the yourWayToSort function
    std::sort(myContainer.begin(), myContainer.end(), yourWayToSort);
    printContainer(myContainer);

    //Sort string container using the myWayToSort function
    std::sort(myContainer.begin(), myContainer.end(), myWayToSort);
    printContainer(myContainer);

    return 0;
}