#include <iostream>

int num_users = 0;

class User
{
private:
    const std::string m_name;
    const int m_id = num_users;

public:
    User()
    {}

    User(std::string name) : m_name(name)
    {
        num_users++;
    }

    void printInfo(){
        std::cout << "Name: " << m_name << std::endl;
        std::cout << "ID: " << m_id << std::endl;
    }
};

int main(){
    User user("Balls");
    user.printInfo();

    User user2("Balls2");
    user2.printInfo();
}