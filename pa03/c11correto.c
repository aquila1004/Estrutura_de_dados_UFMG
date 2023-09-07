#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char *msg = malloc(10); // Aloque memória para acomodar a string completa
    if (msg == NULL) {
        perror("malloc");
        return 1; // Trate a falha na alocação de memória, se necessário
    }

    strcpy(msg, "Holberton");
    msg[0] = 'R';
    printf("%ld, %s\n", (long)getpid(), msg);

    free(msg); // Libere a memória alocada quando não for mais necessária

    return 0;
}
