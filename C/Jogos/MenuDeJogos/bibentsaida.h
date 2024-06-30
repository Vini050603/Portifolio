#ifndef BIBENTSAIDA_H_INCLUDED
#define BIBENTSAIDA_H_INCLUDED
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializarlocal();

char *entradastr(char *titulo);

void saidastr(char *titulo, char *valorstr);

char entradachar(char * titulo);

void saidachar(char *titulo, char valorchar);

long int entradalint(char *titulo);

void saidalint(char *titulo,long int valorlint);

int entradaint(char *titulo);

int saidaint(char *titulo, int valorint);

double entradadouble(char * titulo);

void saidadouble(char *titulo, double valordouble);

float entradafloat(char * titulo);

void saidafloat(char *titulo, float valorfloat);

void print(char *titulo);

void pausa();

void limpatela();

#endif // BIBENTSAIDA_H_INCLUDED
