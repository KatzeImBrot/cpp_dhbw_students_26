#include <iostream>
#include <random>

int nummer = 0;

int getRandomNum(){
    std::mt19937 Engine;
    std::cout <<  Engine.min() << Engine.max() << std::endl;

    return 1;
}

class Konto
{
private:
    const int m_BLZ;
    const int m_kontonummer;
    double m_kontostand;

public:
    Konto(int BLZ) : m_BLZ(BLZ), m_kontonummer(nummer)
    {
        m_kontostand = 0;
    }

    void printInfo(){
        std::cout << "BLZ: " << m_BLZ << std::endl;
        std::cout << "Kontonummer: " << m_kontonummer << std::endl;
        std::cout << "Kontostand: " << m_kontostand << std::endl;
    }
};

int main(){
    getRandomNum();
}