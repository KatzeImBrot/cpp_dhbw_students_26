#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>

// Diese Funktion dient als Callback fuer std::for_each.
// Jeder Aufruf erhaelt genau ein Element des Containers als Referenz.
void printHelper(std::string &InputString) {
    std::cout << InputString;
}

int main()
{
    // Der Vector speichert mehrere Strings hintereinander.
    // Wir verwenden ihn hier als einfachen Container fuer Textbausteine.
    std::vector<std::string> myContainer;
    myContainer = {"Hello", ",", " ", "World", "!"};

    // a) range-based-for loop
    // Wir fuegen temporaer einen weiteren String an, damit in der Ausgabe
    // sichtbar wird, welche Schleifenvariante gerade verwendet wird.
    myContainer.push_back(" - range-based-for loop");

    // Die range-based-for-Schleife geht automatisch ueber alle Elemente.
    // 'str' ist eine Referenz auf das aktuelle Element im Vector.
    // Dadurch wird keine Kopie des Strings erzeugt.
    for (std::string &str : myContainer)
    {
        std::cout << str;
    }
    std::cout << std::endl;

    // Der zusaetzliche Beschreibungstext wird wieder entfernt,
    // damit der Container fuer die naechsten Beispiele wieder im
    // urspruenglichen Zustand ist.
    myContainer.pop_back();


    // iterator access
    // begin() liefert einen Iterator auf das erste Element.
    // Ein Iterator verhaelt sich aehnlich wie ein Zeiger auf ein Element.
    auto container_iterator = myContainer.begin();

    // Mit * wird der Iterator dereferenziert, also auf das Element zugegriffen,
    // auf das der Iterator gerade zeigt.
    std::cout << "First element: " << *container_iterator << std::endl;

    // ++container_iterator bewegt den Iterator auf das naechste Element.
    // Durch die Klammerung wird zuerst inkrementiert und danach dereferenziert.
    std::cout << "Second element: " << *(++container_iterator) << std::endl;



    // b) iterator-based loop
    myContainer.push_back(" - iterator-based loop");

    // Hier wird dieselbe Iteration explizit mit Iteratoren formuliert.
    // 'it' startet beim ersten Element und wird bis zum Ende weiterbewegt.
    // *it liefert jeweils das aktuelle Element.
    for (auto it = myContainer.begin(); it < myContainer.end(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    myContainer.pop_back();


    // c1) for_each loop
    myContainer.push_back(" - for_each loop");

    // std::for_each erwartet einen Start-Iterator, einen End-Iterator
    // und eine Funktion, die fuer jedes Element aufgerufen wird.
    std::for_each(myContainer.begin(), myContainer.end(), printHelper);
    std::cout << std::endl;

    // c2) for_each loop with lambda
    // Eine Lambda-Funktion ist eine anonyme Funktion direkt an der Aufrufstelle.
    // Sie ist praktisch, wenn die Logik nur hier benoetigt wird.
    std::for_each(myContainer.begin(), myContainer.end(), [](std::string &str) {std::cout << str;});
    std::cout << std::endl;

    return 0;
}
