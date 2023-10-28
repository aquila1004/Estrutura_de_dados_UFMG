#include "../include/graph.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int* colors;
} CoresVertices;


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

void ImprimeCoresDosVizinhos(Grafo* g, int v, CoresVertices* cores) {
    if (g && v >= 0 && v < g->V) {
        struct Node* current = g->adjList[v];

        int corVertice = ObtemCor(cores, v);

       printf("%d de cor %d: ", v, corVertice);
        while (current) {
            int vizinho = current->data;
           
            int corVizinho = ObtemCor(cores, vizinho);
            //printf("v%d ", vizinho);
            printf(" %d ", corVizinho);
            current = current->next;
        
        }

       printf("\n");
    }
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


int VerificaColoracaoGulosa(Grafo* grafo, CoresVertices* cores) {
    int numCores = 0; // Variável para rastrear o número máximo de cores usadas.

    for (int v = 0; v < grafo->V; v++) {
        if (ObtemCor(cores, v) > numCores) {
            numCores = ObtemCor(cores, v);
        }
    }

    for (int v = 0; v < grafo->V; v++) {
        struct Node* current = grafo->adjList[v];
        int corVerticeAtual = ObtemCor(cores, v);
        int* coresMenores = (int*)calloc(corVerticeAtual, sizeof(int)); // Array para rastrear as cores menores que a cor atual.

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



int main(int argc, char* argv[]) {
    
    if (argc < 2 || (strcmp(argv[1], "-n") != 0 && strcmp(argv[1], "-d") != 0 && strcmp(argv[1], "-k") != 0)) {
        fprintf(stderr, "Uso: %s <operacao> [-n|-d|-k]\n", argv[0]);
        return 1;
    }

    char* operacao = argv[1];
    int numVertices;

    if (strcmp(operacao, "-n") == 0 || strcmp(operacao, "-d") == 0 || strcmp(operacao, "-k") == 0) {
        scanf("%d", &numVertices);
    } else {
        fprintf(stderr, "Uso: %s <operacao> [-n|-d|-k]\n", argv[0]);
        return 1;
    }

    
    Grafo* grafo = LeGrafo(numVertices);


    CoresVertices* cores = InicializaCores(numVertices);


    for (int i = 0; i < numVertices; ++i) {
        int cor;
        scanf("%d", &cor);
        DefineCor(cores, i, cor);
    }

    if (strcmp(operacao, "-d") == 0) {
        printf("%d\n", QuantidadeVertices(grafo));
        printf("%d\n", QuantidadeArestas(grafo));
        printf("%d\n", GrauMinimo(grafo));
        printf("%d\n", GrauMaximo(grafo));
    } else if (strcmp(operacao, "-n") == 0) {
        
        for (int i = 0; i < QuantidadeVertices(grafo); ++i) {
             ImprimeCoresDosVizinhos(grafo, i, cores);
             //ImprimeVizinhos(grafo, i);
        }
        // mostrar o resultado da verifica se é uma coloração gulosa
        int resultadoColoracaoGulosa = VerificaColoracaoGulosa(grafo, cores);
        if (resultadoColoracaoGulosa) {
            printf("É uma coloração gulosa.\n");
        } else {
            printf("Não é uma coloração gulosa.\n");
        }
        
    } else if (strcmp(operacao, "-k") == 0) {
        
        int numArestas = QuantidadeArestas(grafo);
        int numMaxArestas = numVertices * (numVertices - 1) / 2;

        if (numArestas == numMaxArestas) {
            printf("1\n"); 
        } else {
            printf("0\n"); 
        }
    }
    DeletaGrafo(grafo);
    LiberaCores(cores);

    return 0;
}