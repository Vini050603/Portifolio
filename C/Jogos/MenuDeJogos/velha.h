#ifndef VELHA_H_INCLUDED
#define VELHA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

#define DIM 3

int vez;
void passoapasso();
int menu(void);
void clear(void);
void zeraTabuleiro(int tabuleiro[][DIM]);
void exibeTabuleiro(int tabuleiro[][DIM]);
void jogar(int tabuleiro[][DIM]);
int checaLocal(int tabuleiro[][DIM], int linha, int coluna);
int checaLinha(int tabuleiro[][DIM]);
int checaColuna(int tabuleiro[][DIM]);
int checaDiagonal(int tabuleiro[][DIM]);
int checaEmpate(int tabuleiro[][DIM]);
int checaTermino(int tabuleiro[][DIM], int vez);
void jogada(int tabuleiro[][DIM]);
void jogovelha();

#endif // VELHA_H_INCLUDED
