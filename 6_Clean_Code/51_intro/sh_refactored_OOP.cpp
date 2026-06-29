#include <iostream>
#include <vector>
#include <memory>

// Konstanten

// Abstrakte Basisklasse

// Abgeleitete Klassen

// Funktionen

// Hauptfunktion zur Eingabe der Formen und Ausgabe der Flächeninformationen
void getInputAndPrintAreas()
{
    auto shapes = getShapesFromUser(); // Erstellen der Formen basierend auf Benutzereingaben
    printShapeAreas(shapes);           // Ausgabe der Flächeninformationen
}

int main()
{
    getInputAndPrintAreas(); // Aufrufen der Hauptfunktion
    return 0;
}