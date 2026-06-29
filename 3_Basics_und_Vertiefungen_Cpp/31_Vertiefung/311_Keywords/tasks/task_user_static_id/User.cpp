#include "User.hpp"
#include <iostream>

// Definition und Initialisierung der statischen Member-Variable
int User::nextID = 1;

User::User()
    : User("Unkown")
{
}

User::User(const std::string &name)
    : m_name(name), m_id(nextID++)
{
}

void User::printInfo() const
{
   std::cout << "Name: " << m_name << std::endl;
   std::cout << "ID: " << m_id << std::endl;
}
