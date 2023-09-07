#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *p;
    int num_allocations = 10; // Número desejado de alocações

    for (int i = 0; i < num_allocations; i++)
    {
        p = malloc(128);
        if (p == NULL)
        {
            perror("Falha na alocação de memória");
            break; // Encerre o loop se não for possível alocar mais memória
        }
        printf("%ld\n", (long)p);
        free(p); 
    }

    return 0;
}
