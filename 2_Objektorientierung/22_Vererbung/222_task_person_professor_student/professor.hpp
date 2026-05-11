#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include "person.hpp"

class Professor: public Person{
    public:

    Professor(std::string name, std::string address, std::string email);

    ~Professor(){};

    private:
    std::string m_iban;
};

#endif