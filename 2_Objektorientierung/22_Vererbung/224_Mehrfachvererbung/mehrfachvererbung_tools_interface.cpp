#include <iostream>

// Dokumentation & Hintergrund: MEHRFACHVERERBUNG.md

class IPrinter {
public:
    virtual void print() = 0;
    virtual void turnOn() = 0;
    virtual bool isCalibrated() = 0;
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void scan() = 0;
    virtual void turnOn() = 0;
    virtual bool isCalibrated() = 0;
    virtual ~IScanner() = default;
};

class MultiFunctionDevice : public IPrinter, public IScanner {
public:
    void print() override {}
    void scan() override {}
    void turnOn() override {}

    bool isCalibrated() override { return m_isCalibrated; }

private:
    bool m_isCalibrated = true;
};

int main()
{
    MultiFunctionDevice mfd;

    mfd.turnOn();    // kein Fehler: eindeutig – MultiFunctionDevice::turnOn()
    mfd.print();
    mfd.scan();

    if (mfd.isCalibrated())
        std::cout << "Device is calibrated." << std::endl;

    return 0;
}




