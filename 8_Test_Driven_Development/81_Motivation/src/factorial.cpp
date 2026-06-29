#include "factorial.h"

// Was muss noch abgefangen werden?

int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}






