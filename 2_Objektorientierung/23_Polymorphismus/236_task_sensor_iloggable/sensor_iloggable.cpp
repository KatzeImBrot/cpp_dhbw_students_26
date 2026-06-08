#include <iostream>
#include <string>
#include <vector>

// Interface: rein virtuelle Methode, keine Member-Variablen
class ILoggable
{
public:
    virtual void logData() = 0;
    virtual ~ILoggable() = default;
};

// Basisklasse Sensor
class Sensor
{
public:
    Sensor(std::string name, double value)
        : m_name(name), m_value(value)
    {
    }

    double readValue() const
    {
        return m_value;
    }

    std::string getName() const
    {
        return m_name;
    }

protected:
    std::string m_name;
    double m_value;
};

// Mehrfachvererbung: Sensor + ILoggable
class TemperaturSensor : public Sensor, public ILoggable
{
public:
    TemperaturSensor(std::string name, double value)
        : Sensor(name, value)
    {
    }

    void logData() override
    {
        std::cout << "[TEMP]   " << m_name << ": " << m_value << " °C" << std::endl;
    }
};

// Mehrfachvererbung: Sensor + ILoggable
class DruckSensor : public Sensor, public ILoggable
{
public:
    DruckSensor(std::string name, double value)
        : Sensor(name, value)
    {
    }

    void logData() override
    {
        std::cout << "[DRUCK]  " << m_name << ": " << m_value << " bar" << std::endl;
    }
};

// Völlig unabhängig von Sensor – implementiert nur ILoggable
class Server : public ILoggable
{
public:
    Server(std::string hostname, double cpuLoad)
        : m_hostname(hostname), m_cpuLoad(cpuLoad)
    {
    }

    void logData() override
    {
        std::cout << "[SERVER] " << m_hostname << ": CPU " << m_cpuLoad << " %" << std::endl;
    }

private:
    std::string m_hostname;
    double m_cpuLoad;
};

// Freie Funktion – arbeitet polymorph über ILoggable*
void logAll(std::vector<ILoggable*> loggables)
{
    for (ILoggable* l : loggables)
    {
        l->logData();
    }
}

int main()
{
    TemperaturSensor t1("Außen",  -3.2);
    TemperaturSensor t2("Innen",  21.5);
    DruckSensor      d1("Kessel",  4.7);
    Server           s1("web-01", 67.2);

    std::vector<ILoggable*> loggables = {&t1, &t2, &d1, &s1};
    logAll(loggables);

    return 0;
}
