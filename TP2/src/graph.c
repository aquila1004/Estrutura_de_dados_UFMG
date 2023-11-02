#include "../include/graph.hpp"
#include <stdio.h>
#include <limits.h>

Grafo* NovoGrafo() {
    Grafo* graph = (Grafo*)malloc(sizeof(Grafo));
    if (graph) {
        graph->V = 0;
        graph->adjList = NULL;
    }
    return graph;
}


void DeletaGrafo(Grafo* g) {
    if (g) {
        for (int i = 0; i < g->V; ++i) {
            struct Node* current = g->adjList[i];
            while (current) {
                struct Node* temp = current;
                current = current->next;
                free(temp);
            }
        }
        free(g->adjList);
        free(g);
    }
}


void InsereVertice(Grafo* g) {
    if (g) {
        g->V++;
        g->adjList = (struct Node**)realloc(g->adjList, g->V * sizeof(struct Node*));
        g->adjList[g->V - 1] = NULL;
    }
}

void InsereAresta(Grafo* g, int v, int w) {
    if (g && v >= 0 && v < g->V && w >= 0 && w < g->V) {
        struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
        newNode1->data = w;
        newNode1->next = g->adjList[v];
        g->adjList[v] = newNode1;
    }
}

int QuantidadeVertices(Grafo* g) {
    if (g) {
        return g->V;
    }
    return 0;
}

int QuantidadeArestas(Grafo* g) {
    if (g) {
        int edges = 0;
        for (int i = 0; i < g->V; ++i) {
            struct Node* current = g->adjList[i];
            while (current) {
                edges++;
                current = current->next;
            }
        }
        return edges / 2; 
    }
    return 0;
}

int VerificaColoracaoGulosa(Grafo* grafo, CoresVertices* cores) {
    int numCores = 0; 

    for (int v = 0; v < grafo->V; v++) {
        if (ObtemCor(cores, v) > numCores) {
            numCores = ObtemCor(cores, v);
        }
    }

    for (int v = 0; v < grafo->V; v++) {
        struct Node* current = grafo->adjList[v];
        int corVerticeAtual = ObtemCor(cores, v);
        int* coresMenores = (int*)calloc(corVerticeAtual, sizeof(int)); 
        while (current) {
            int vizinho = current->data;
            int corVizinho = ObtemCor(cores, vizinho);
            if (corVerticeAtual == corVizinho) {
                free(coresMenores);
                return 0; 
            }
            if (corVizinho < corVerticeAtual) {
                coresMenores[corVizinho] = 1;
            }
            current = current->next;
        }
        for (int cor = 1; cor < corVerticeAtual; cor++) {
            if (!coresMenores[cor]) {
                free(coresMenores);
                return 0; 
            }
        }
        free(coresMenores);
    }

   
    for (int c = 1; c <= numCores; c++) {
        for (int v = 0; v < grafo->V; v++) {
            if (ObtemCor(cores, v) == c) {
                int temVizinhosDeTodasAsCoresMenores = 0;
                struct Node* current = grafo->adjList[v];
                while (current) {
                    int vizinho = current->data;
                    int corVizinho = ObtemCor(cores, vizinho);
                    if (corVizinho < c) {
                        temVizinhosDeTodasAsCoresMenores = 1;
                        break;
                    }
                    current = current->next;
                }
                if (!temVizinhosDeTodasAsCoresMenores && c > 1) {
                   return 0; 
                }
            }
        }
    }

    return 1; 
}

void DefineCor(CoresVertices* cores, int vertice, int cor) {
    if (cores && vertice >= 0) {
        cores->colors[vertice] = cor;
    }
}


int ObtemCor(CoresVertices* cores, int vertice) {
    if (cores && vertice >= 0) {
        return cores->colors[vertice];
    }
    return -1; 
}


void LiberaCores(CoresVertices* cores) {
    if (cores) {
        free(cores->colors);
        free(cores);
    }
}


