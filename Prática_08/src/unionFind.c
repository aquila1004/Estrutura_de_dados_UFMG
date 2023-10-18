#include "../include/unionFind.h"

UnionFind* NovoUnionFind(int quantidade_subconjuntos){
    UnionFind* dsu = (UnionFind*) malloc(sizeof(UnionFind)*quantidade_subconjuntos);
    for(int i = 0; i < quantidade_subconjuntos; i++){
        dsu[i].representante = i;
        dsu[i].rank = 0;
    }
    return dsu;
}


void DeletaUnionFind(UnionFind* dsu){
    free(dsu);
}

void Make(UnionFind* dsu, int x){
    dsu[x].representante = x;
    dsu[x].rank = 0;
}

int Find(UnionFind* dsu, int x){
    if(dsu[x].representante != x){
        dsu[x].representante = Find(dsu, dsu[x].representante);
    }
    return dsu[x].representante;
}

void Union(UnionFind* dsu,int x, int y){
    int xroot = Find(dsu, x);
    int yroot = Find(dsu, y);
    if(dsu[xroot].rank < dsu[yroot].rank){
        dsu[xroot].representante = yroot;
    }else if(dsu[xroot].rank > dsu[yroot].rank){
        dsu[yroot].representante = xroot;
    }else{
        dsu[yroot].representante = xroot;
        dsu[xroot].rank++;
    }
}