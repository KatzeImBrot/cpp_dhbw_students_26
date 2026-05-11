#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "person.hpp"

class Student: public Person{
    public:

    Student(std::string name, std::string address, std::string email);

    ~Student(){};

    private:
    double m_average_grade;
};

#endif