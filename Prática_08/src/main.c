#include "../include/unionFind.h"

int CompararArestas(const void *a, const void *b) {
    return ((Aresta*)a)->custo - ((Aresta*)b)->custo;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Aresta* arestas = (Aresta*)malloc(sizeof(Aresta) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].custo);
    }

    // Ordenar as arestas em ordem crescente de custo
    qsort(arestas, m, sizeof(Aresta), CompararArestas);

    UnionFind* dsu = NovoUnionFind(n);
    int custo_total = 0;
    for (int i = 0; i < m; i++) {
        if (Find(dsu, arestas[i].u) != Find(dsu, arestas[i].v)) {
            Union(dsu, arestas[i].u, arestas[i].v);
            custo_total += arestas[i].custo;
        }
    }
    printf("%d\n", custo_total);

    free(arestas);
    free(dsu);
    return 0;
}