#include "../include/fat.h"
#include "../include/timer.h"

unsigned long long fatorialRecursivo(int n)
{
    if (n <= 1)
        return (1);
    else
    {

        return n * fatorialRecursivo(n - 1);
    }
    consumesTime();
}
unsigned long long fatorialIterativo(int n)
{
    if (n == 0 || n == 1)
        return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}
