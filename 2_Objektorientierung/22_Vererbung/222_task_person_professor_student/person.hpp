#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person{
    public:
    Person(){};

    Person(std::string name, std::string address, std::string email);

    ~Person(){};

    std::string get_name();

    protected:
    std::string m_name;
    std::string m_address;
    std::string m_email;
};

#endif