#include "bibentsaida.h"

void inicializarlocal()
{
   setlocale(LC_ALL,"");
}

char *entradastr(char *titulo)
{
    setbuf(stdin, NULL);
    char string[50];
    printf("%s", titulo);
    return(gets(string));
}

void saidastr(char *titulo, char *valorstr)
{
    printf("%s%s",titulo, valorstr);
}

char entradachar(char *titulo)
{
    setbuf(stdin, NULL);
    char l;
    printf("%s", titulo);
    scanf(" %c", &l);
    return l;
}

void saidachar(char *titulo, char valorchar)
{
    printf("%s%c",titulo, valorchar);
}

long int entradalint(char *titulo)
{
    setbuf(stdin, NULL);
    printf("%s", titulo);
    long int valor;
    scanf("%ld",&valor);
    return valor;
}

void saidalint(char *titulo,long int valorlint)
{
    printf("%s", titulo);
    printf("%ld", valorlint);
}

int entradaint(char *titulo)
{
    int valor;
    printf("%s", titulo);
    scanf("%d", &valor);
    return valor;
}
int saidaint(char *titulo, int valorint)
{
    printf("%s", titulo);
    return valorint;
}
double entradadouble(char * titulo)
{
    setbuf(stdin, NULL);
    printf("%s", titulo);
    double valor;
    scanf("%lf",&valor);
    return valor;
}
void saidadouble(char *titulo, double valordouble)
{
    printf("%s", titulo);
    printf("%lf",valordouble);
}
float entradafloat(char * titulo)
{
    setbuf(stdin, NULL);
    printf("%s", titulo);
    float valor;
    scanf("%f",&valor);
    return valor;
}
void saidafloat(char *titulo, float valorfloat)
{
    printf("%s", titulo);
    printf("%f",valorfloat);
}

char arquivo[] = {"usuarios.dat"};
char arquivol[] = {"logs.dat"};
int op=0;

void print(char *titulo){
 printf("%s", titulo);
}
void pausa()//Fun��o apenas para windows
{
    system("pause");
}
void limpatela()//Fun��o apenas para windows
{
    system("cls");
}
