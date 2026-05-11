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
    const int cap = num;
    
    for(int i = 1; i < cap; i++){
        num = num + i;
    }

    std::cout << num << std::endl;
}
