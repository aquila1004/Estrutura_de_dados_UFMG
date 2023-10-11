#include "../include/graph.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Grafo* LeGrafo(int numVertices) {
    Grafo* grafo = NovoGrafo();

    // Insere os vértices no grafo
    for (int i = 0; i < numVertices; ++i) {
        InsereVertice(grafo);
    }

    // Leitura dos vizinhos
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
    if (argc < 2 || (strcmp(argv[1], "-n") != 0 && strcmp(argv[1], "-d") != 0 && strcmp(argv[1], "-k") != 0)) {
        fprintf(stderr, "Uso: %s <operacao> [-n|-d|-k]\n", argv[0]);
        return 1;
    }

    // Verifica a operação a ser realizada
    char* operacao = argv[1];
    int numVertices;

    // Lê o número de vértices diretamente sem mensagem
    if (strcmp(operacao, "-n") == 0 || strcmp(operacao, "-d") == 0 || strcmp(operacao, "-k") == 0) {
        scanf("%d", &numVertices);
    } else {
        fprintf(stderr, "Uso: %s <operacao> [-n|-d|-k]\n", argv[0]);
        return 1;
    }

    // Aguarda a entrada do grafo antes de prosseguir
    Grafo* grafo = LeGrafo(numVertices);

    if (strcmp(operacao, "-d") == 0) {
        // Operação para imprimir dados básicos do grafo
        printf("%d\n", QuantidadeVertices(grafo));
        printf("%d\n", QuantidadeArestas(grafo));
        printf("%d\n", GrauMinimo(grafo));
        printf("%d\n", GrauMaximo(grafo));
    } else if (strcmp(operacao, "-n") == 0) {
        // Operação para imprimir as vizinhanças dos vértices
        for (int i = 0; i < QuantidadeVertices(grafo); ++i) {
            ImprimeVizinhos(grafo, i);
        }
    } else if (strcmp(operacao, "-k") == 0) {
        // Operação para verificar se o grafo é completo
        int numArestas = QuantidadeArestas(grafo);
        int numMaxArestas = numVertices * (numVertices - 1) / 2;

        if (numArestas == numMaxArestas) {
            printf("1\n"); // O grafo é completo
        } else {
            printf("0\n"); // O grafo não é completo
        }
    }

    // Deleta o grafo para liberar memória
    DeletaGrafo(grafo);

    return 0;
}
