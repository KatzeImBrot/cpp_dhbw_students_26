#include <iostream>

void inputNum();

int main()
{
    inputNum();
}

void inputNum()
{
    int num;
    std::cin >> num;
    num = num * num;
    std::cout << num << std::endl;
}
