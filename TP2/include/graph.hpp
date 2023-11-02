#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct s_grafo {
    int V; // Número de vértices
    struct Node** adjList; // Lista de adjacência
};
typedef struct s_grafo Grafo;

typedef struct {
    int* colors;
} CoresVertices;


Grafo* NovoGrafo();
void DeletaGrafo(Grafo* g);

void InsereVertice(Grafo* g);
void InsereAresta(Grafo* g, int v, int w);

int QuantidadeVertices(Grafo* g);
int QuantidadeArestas(Grafo* g);

int GrauMinimo(Grafo* g);
int GrauMaximo(Grafo* g);

void ImprimeVizinhos(Grafo* g, int v);

#endif