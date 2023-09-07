#include <stdlib.h>

void f(void)
{

    int *x = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
        x[i] = 0;
    free(x);
}

int main(void)
{

    f();
    return 0;
}
