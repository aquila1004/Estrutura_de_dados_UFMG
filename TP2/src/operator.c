#include "../include/operator.hpp"

int isValidOperation(const char* operation) {
    const char* validOperations[] = {"-b", "-s", "-i", "-m", "-q", "-p", "-y", NULL};
    
    for (int i = 0; validOperations[i]; i++) {
        if (strcmp(operation, validOperations[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}

void handleOperation(const char* operation, Grafo* grafo, CoresVertices* cores, int result) {
    if (!result) {
        printf("0\n");
        return;
    }

    printf("1 ");
    
    if (strcmp(operation, "b") == 0) { 
        OrdenaBoublleSort(grafo, cores);
    } else if (strcmp(operation, "s") == 0) { 
        OrdenaSelectionSort(grafo, cores);
    } else if (strcmp(operation, "i") == 0) { 
        OrdenaInsertionSort(grafo, cores);
    } else if (strcmp(operation, "m") == 0) { 
        OrdenaMergeSort(grafo, cores);
    } else if (strcmp(operation, "q") == 0) { 
        OrdenaQuickSort(grafo, cores);
    } else if (strcmp(operation, "p") == 0) { 
        OrdenaHeapSort(grafo, cores);
    }
    else if(strcmp(operation, "y") == 0) {
        OrdenaInsertionMerge(grafo, cores);
    }
    
}