#include <iostream>
#include "student.hpp"

Student::Student(std::string name, std::string address, std::string email)
{
    m_name = name;
    m_address = address;
    m_email = email;
};

Student::~Student() {};