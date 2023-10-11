#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.hpp"

Heap* NovoHeap(int maxsize) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->tamanho = 0;
    h->dados = (int*)malloc(maxsize * sizeof(int));
    return h;
}

void DeletaHeap(Heap* h) {
    free(h->dados);
    free(h);
}

void Inserir(Heap* h, int x) {
    int t = h->tamanho;
    h->dados[t] = x;

    int i = t;
    int p = (i - 1) / 2;
    while (i > 0 && h->dados[i] < h->dados[p]) {
        // Troca os valores de v[i] e v[p]
        int temp = h->dados[i];
        h->dados[i] = h->dados[p];
        h->dados[p] = temp;

        i = p;
        p = (i - 1) / 2;
    }

    h->tamanho++;
}

int Remover(Heap* h) {
    if (Vazio(h)) {
        // Tratar erro, o Heap está vazio
        return -1;
    }

    int x = h->dados[0];
    h->dados[0] = h->dados[h->tamanho - 1];
    h->tamanho--;
    int i = 0;

    while (1) {
        int s = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->tamanho && h->dados[left] < h->dados[s]) {
            s = left;
        }

        if (right < h->tamanho && h->dados[right] < h->dados[s]) {
            s = right;
        }

        if (s == i) {
            break;
        }

        // Troca os valores de v[i] e v[s]
        int temp = h->dados[i];
        h->dados[i] = h->dados[s];
        h->dados[s] = temp;

        i = s;
    }

    return x;
}

int GetAncestral(Heap* h, int posicao) {
    if (posicao <= 0 || posicao >= h->tamanho) {
        // Tratar erro, posição inválida
        return -1;
    }
    return h->dados[(posicao - 1) / 2];
}

int GetSucessorEsq(Heap* h, int posicao) {
    int left = 2 * posicao + 1;
    if (left < h->tamanho) {
        return h->dados[left];
    } else {
        // Tratar erro, posição inválida
        return -1;
    }
}

int GetSucessorDir(Heap* h, int posicao) {
    int right = 2 * posicao + 2;
    if (right < h->tamanho) {
        return h->dados[right];
    } else {
        // Tratar erro, posição inválida
        return -1;
    }
}

int Vazio(Heap* h) {
    return (h->tamanho == 0);
}
