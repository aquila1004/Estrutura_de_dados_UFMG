#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../include/graph.hpp"
#include "../include/sort.hpp"

CoresVertices* InicializaCores(int numVertices) {
    CoresVertices* cores = (CoresVertices*)malloc(sizeof(CoresVertices));
    if (cores) {
        cores->colors = (int*)malloc(numVertices * sizeof(int));
        for (int i = 0; i < numVertices; ++i) {
            cores->colors[i] = -1;
        }
    }
    return cores;
}

Grafo* LeGrafo(int numVertices) {
    Grafo* grafo = NovoGrafo();

    for (int i = 0; i < numVertices; ++i) {
        InsereVertice(grafo);
    }

    for (int i = 0; i < numVertices; ++i) {
        int numVizinhos;
        scanf("%d", &numVizinhos);
        for (int j = 0; j < numVizinhos; ++j) {
            int vizinho;
            scanf("%d", &vizinho);
            InsereAresta(grafo, i, vizinho);
        }
    }
    return grafo;
}

int main(int argc, char* argv[]) {

    

    char operacao[10];
    int numVertices;
    scanf("%s", operacao);
    scanf("%d", &numVertices);
    Grafo* grafo = LeGrafo(numVertices);
    CoresVertices* cores = InicializaCores(numVertices);

    for (int i = 0; i < numVertices; ++i) {
        int cor;
        scanf("%d", &cor);
        DefineCor(cores, i, cor);
    }
  
    int resultadoColoracaoGulosa = VerificaColoracaoGulosa(grafo, cores);
    handleOperation(operacao, grafo, cores, resultadoColoracaoGulosa);
    
    DeletaGrafo(grafo);
    LiberaCores(cores);

    return 0;
}

