#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdlib.h>

typedef struct pilha *Pilha;
typedef char* Itemp;

Pilha pilha(int m);
int vaziap(Pilha P);
int cheiap(Pilha P);
void empilha(Itemp x, Pilha P);
Itemp desempilha(Pilha P);
Itemp topo(Pilha P);


#endif // PILHA_H_INCLUDED
