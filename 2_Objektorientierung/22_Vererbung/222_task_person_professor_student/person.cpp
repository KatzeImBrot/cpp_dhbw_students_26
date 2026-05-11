#include <iostream>
#include "person.hpp"

Person::Person(){};

Person::~Person(){};

Person::Person(std::string name, std::string address, std::string email)
: m_name(name), m_address(address), m_email(email){};

std::string Person::get_name(){
    return m_name;
}