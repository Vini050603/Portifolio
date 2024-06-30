#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include "pilha.h"

void gotoxy(int x, int y);

void desenha();

void atualiza();

int analiza();

void geraComida();

void jogosnake();

void instru();

#endif // SNAKE_H_INCLUDED
