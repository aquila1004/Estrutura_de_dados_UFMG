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


int GrauMinimo(Grafo* g) {
    if (g) {
        int minDegree = INT_MAX;
        for (int i = 0; i < g->V; ++i) {
            int degree = 0;
            struct Node* current = g->adjList[i];
            while (current) {
                degree++;
                current = current->next;
            }
            if (degree < minDegree) {
                minDegree = degree;
            }
        }
        return minDegree;
    }
    return 0;
}


int GrauMaximo(Grafo* g) {
    if (g) {
        int maxDegree = 0;
        for (int i = 0; i < g->V; ++i) {
            int degree = 0;
            struct Node* current = g->adjList[i];
            while (current) {
                degree++;
                current = current->next;
            }
            if (degree > maxDegree) {
                maxDegree = degree;
            }
        }
        return maxDegree;
    }
    return 0;
}


