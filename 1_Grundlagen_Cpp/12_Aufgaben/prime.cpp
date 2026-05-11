#include <iostream>

bool prim(int n);

int main()
{
    int num = 20;
    std::cout << num << std::endl;
    std::cout << prim(num) << std::endl;
    return 0;
}

bool prim(int n)
{
    if (n <= 5 && n != 4){
        return true;
    }
    if (n%2 == 0 || n%3 == 0 || n%5 == 0){
        return false;
    }
    
    return true;
}
