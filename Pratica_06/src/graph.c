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

// Função para inserir um novo vértice no grafo
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

        // Não é necessário adicionar v à lista de adjacência de w, pois já foi adicionado acima
    }
}

// Função para obter a quantidade de vértices no grafo
int QuantidadeVertices(Grafo* g) {
    if (g) {
        return g->V;
    }
    return 0;
}

// Função para obter a quantidade de arestas no grafo
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
        return edges / 2; // Cada aresta é contada duas vezes
    }
    return 0;
}

// Função para obter o grau mínimo no grafo
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

// Função para obter o grau máximo no grafo
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

// Função para imprimir os vértices vizinhos de um vértice específico
void ImprimeVizinhos(Grafo* g, int v) {
    if (g && v >= 0 && v < g->V) {
        struct Node* current = g->adjList[v];
        int vizinhos[100]; // Suponhamos um limite máximo de 100 vizinhos (ajuste conforme necessário)
        int numVizinhos = 0;

        //printf("Vizinhos do vértice %d: ", v);

        // Armazena os vizinhos em um vetor
        while (current) {
            vizinhos[numVizinhos] = current->data;
            current = current->next;
            numVizinhos++;
        }

        // Imprime os vizinhos na ordem inversa
        for (int i = numVizinhos - 1; i >= 0; i--) {
            printf("%d ", vizinhos[i]);
        }

        printf("\n");
    }
}
