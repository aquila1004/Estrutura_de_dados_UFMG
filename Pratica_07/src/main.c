#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.hpp"

int main() {
    int n;
    scanf("%d", &n);

    Heap* heap = NovoHeap(n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Inserir(heap, x);
    }

    while (!Vazio(heap)) {
        int elemento = Remover(heap);
        printf("%d ", elemento);
    }
    printf("\n");

    DeletaHeap(heap);

    return 0;
}
