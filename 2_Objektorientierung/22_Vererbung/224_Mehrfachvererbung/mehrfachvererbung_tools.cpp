#include <iostream>

class Printer {
public:
    void print() {}
    void turnOn() {}
    bool m_isCalibrated;
};

class Scanner {
public:
    void scan() {}
    void turnOn() {}
    bool m_isCalibrated;
};

class MultiFunctionDevice :
    public Printer,
    public Scanner {
public:
    void test() {
        // turnOn(); // Ambiguität : Compiler weiß nicht, ob Printer::turnOn() oder Scanner::turnOn() gemeint ist
        Printer::turnOn(); // explizite Angabe der Klasse (Nicht optimal)
        Scanner::turnOn(); // explizite Angabe der Klasse (Nicht optimal)
        //if (m_isCalibrated) {} // Ambiguität                                                      : Compiler weiß nicht, ob Printer::m_isCalibrated oder Scanner::m_isCalibrated gemeint ist

    }
};

int main()
{
    MultiFunctionDevice mfd;

    // mfd.turnOn(); // FEHLER: Compiler weiß nicht welches turnOn() gemeint ist

    mfd.Printer::turnOn();  // explizit: Printer-Version (Nicht optimal)
    mfd.Scanner::turnOn();  // explizit: Scanner-Version (Nicht optimal)

    mfd.print();
    mfd.scan();

    std::cout << "MultiFunctionDevice bereit." << std::endl;

    return 0;
}



