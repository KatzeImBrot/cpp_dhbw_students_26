#include <iostream>
#include "professor.hpp"

Professor::Professor(std::string name, std::string address, std::string email)
{
    m_name = name;
    m_address = address;
    m_email = email;
};

Professor::~Professor() {};