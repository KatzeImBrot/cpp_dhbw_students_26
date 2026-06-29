#ifndef USER_HPP
#define USER_HPP

#include <string>

class User
{
public:
   User();

   User(const std::string &name);

   void printInfo() const;

private:
   std::string m_name;
   int m_id;

   static int nextID;
};

#endif // USER_HPP
