#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>


void forca(int estado);

void grande_vencedor(int vencedor1, int erros1, int vencedor2, int erros2);

void ordena_cores();

void ordena_paises();

void ordena_objetos();

void ordena_nome();

void ordena_string(char *vet[]);

void palavras_ordenadas();

void regra_forca();

void forca_dupla();

void forca_solo();

void jogoforca();

#endif
