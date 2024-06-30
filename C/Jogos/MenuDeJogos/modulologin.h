#ifndef MODULOLOGIN_H_INCLUDED
#define MODULOLOGIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "snake.c"
#include "velha.c"
#include "bibentsaida.c"
#include "pacman.c"
#include "forca.c"
#include "rpg.c"


struct usuario
{
    char nome[50];
    char email[30];
    char senha[100];
    int tipocad;
    int ncadastro;
    char CPF[15];
};

typedef struct usuario USUARIO;
//typedef struct records RECORDS;
void cadastro(char arq[]);

void login(char arq[]);

void relatorio(char arq[]);

void alteracao(char arq[]);

void exclusao(char arq[]);

void alteracaousuario(char arq[]);

void CadastroAdmin(char arq[]);

int cpf_f(char cpf[15]);

int email_f(char email[50]);

int senha_f(char senha[100]);

void relatoriologin(char arq[]);

void menudejogos();

void chamamenu();


#endif // MODULOLOGIN_H_INCLUDED
