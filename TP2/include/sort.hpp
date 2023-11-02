#ifndef SORT_HPP
#define SORT_HPP

#include "graph.hpp"

typedef struct {
    int vertice;
    int cor;
} VerticeCor;


void OrdenaBoublleSort(Grafo* g, CoresVertices* cores);
void OrdenaSelectionSort(Grafo* g, CoresVertices* cores);
void OrdenaInsertionSort(Grafo* g, CoresVertices* cores);

void OrdenaMergeSort(Grafo* g, CoresVertices* cores);
void OrdenaQuickSort(Grafo* g, CoresVertices* cores);
void OrdenaHeapSort(Grafo* g, CoresVertices* cores);

#endif