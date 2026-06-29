// ============================================================================
//  Aufgabe: Supermarkt-Kassensystem
//    - Katalog (Produktname -> Preis) in einer std::map
//    - Einkaufsliste des Kunden (von der Kommandozeile) in einem std::vector
//    - Kassenzettel aus Vector + Map ausgeben
//
//  Kompilieren:  g++ -std=c++17 -Wall -Wextra kassensystem.cpp -o kasse
//  Starten:      ./kasse
//
//  Hinweis: Statt std::map ginge auch std::unordered_map (schnellerer Zugriff,
//  dafuer keine sortierte Reihenfolge). Die Nutzung ist identisch.
// ============================================================================

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>

// (1)+(2) Katalog anlegen und mit Produktnamen + Preisen befuellen
// TODO

// Hilfsfunktion: verfuegbares Sortiment anzeigen
void zeigeSortiment(const std::map<std::string, double>& katalog) {
    std::cout << "Verfuegbare Produkte:\n";
    for (const auto& [name, preis] : katalog) {
        std::cout << "  - " << std::left << std::setw(10) << name
                  << std::right << std::setw(6) << std::fixed << std::setprecision(2)
                  << preis << " EUR\n";
    }
    std::cout << std::endl;
}

// (3)+(4) Einkaufsliste von der Kommandozeile lesen und im Vector speichern
// TODO

// (5) Kassenzettel aus Vector + Map ausgeben
void druckeKassenzettel(const std::vector<std::string>& einkauf,
                        const std::map<std::string, double>& katalog) {
    std::cout << "\n=============== Kassenzettel ===============\n";
    double summe = 0.0;

    // TODO
}

int main() {
    std::map<std::string, double> katalog = erstelleKatalog();

    zeigeSortiment(katalog);
    std::vector<std::string> einkauf = leseEinkaufsliste();
    druckeKassenzettel(einkauf, katalog);

    return 0;
}