#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <stdlib.h>
#include <stdio.h>

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */


/*  Você deve implementar struct s_grafo como um TAD que irá armazenar
 * os dados de um grafo. Lembrando que a estratégia utilizada deve ser uma
 * lista de adjacencia e deve ser implementada como uma lista encadeada.
 */
struct Node {
    int data;
    struct Node* next;
};

struct s_grafo {
    int V; // Número de vértices
    struct Node** adjList; // Lista de adjacência
};
typedef struct s_grafo Grafo;




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