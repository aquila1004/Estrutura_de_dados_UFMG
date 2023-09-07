#include "../include/fib.h"
#include "../include/timer.h"

unsigned long long fibonacciRecursivo(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    consumesTime();
}

unsigned long long fibonacciterativo(int n)
{
    if (n <= 1)
        return n;

    unsigned long long fib_prev = 0;
    unsigned long long fib_curr = 1;
    unsigned long long fib_next;

    for (int i = 2; i <= n; ++i)
    {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    return fib_curr;
}
