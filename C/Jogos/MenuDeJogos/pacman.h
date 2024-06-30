#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#ifndef _PACMAN_H_
#define  _PACMAN_H_
#define BOMBA 'b'
#define PILULA 'P'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bibentsaida.h"
#include "pilha.c"

struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;
struct posicao
{
    int x;
    int y;
};
typedef struct posicao POSICAO;

//come�o das fun��es do pacman
MAPA m;
POSICAO heroi;

int acabou();

void instrucoes();

void dificuldade();

void fantasmas();

int paraondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino );

int direcoes(char direcao);

void move_pers(char direcao);

void alocamapa(MAPA* m);

void destroimapa(MAPA* m);

int valida(MAPA* m, int x, int y);

int vazia(MAPA* m, int x, int y);

int encontramapa(MAPA* m, POSICAO* p, char c);

int paredes(MAPA* m, int x, int y);

int pacman(MAPA* m, char personagem, int x, int y);

int podeandar(MAPA* m, char personagem, int x, int y);

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);

void fandanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);

void copiamapa(MAPA* destino, MAPA* origem);

void lemapa(MAPA* m, int escolha);

void explodepilula ();

void explodepilula2 (int x, int y, int somax, int somay, int qtd);

void imprimeparte(char desenho[4][7], int parte);

void imprime_mapa(MAPA* m);

void felicitacoes();

void jogopacman();

# endif
