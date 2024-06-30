#include "snake.h"

//Variaveis Globais de definição de itens
int c[300][2], pontos=1, cx=2, cy=2;
int comida[2], velo=150;

//Instruções do jogo em pilha
void instru()
{
    char inst5[250] = "5 - Bom jogo!\n";
    char inst4[250] = "4 - Movimente a cobra com as teclas w - cima, a - esquerda, d- direita e s - baixo\n";
    char inst3[250] = "3 - Voce deve comer as bolinhas na tela\n";
    char inst2[250] = "2 - Nao encoste na parede nem toque o proprio corpo!\n";
    char inst1[250] = "1 - Aguarde a parede do jogo ser carregada por completo!\n";
    char inst0[250] = "\n\tInstrucoes do jogo!\n";
    Pilha p = pilha(6);
    empilha(inst5, p);
    empilha(inst4, p);
    empilha(inst3, p);
    empilha(inst2, p);
    empilha(inst1, p);
    empilha(inst0, p);
    for(int i = 0; i < 6; i++)
    {
        print(desempilha(p));
    }
    free(p);
}

//Função de coordenada da cobra
void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x,y
    });
}

//Desenha a cobra
void desenha()
{
    int i;
    for(i=0; i<pontos; i++)
    {
        gotoxy(c[i][0],c[i][1]);
        printf("%c",219);
    }
}


//Atualiza a posição da cobrinha
void atualiza()
{
    int i;
    gotoxy(c[pontos][0],c[pontos][1]);
    printf(" ");
    for(i=pontos; i>=0; i--)
    {
        c[i+1][0] = c[i][0];
        c[i+1][1] = c[i][1];
    }
}


// Vê se a cobrinha encostou em seu proprio corpo
int analiza()
{
    int i, retorno=0;
    for(i=1; i<pontos; i++)
    {
        if(cx==c[i][0] && cy==c[i][1])
        {
            retorno=1;
        }
    }
    return retorno;
}


//Gera comida em um local aleatiorio
void geraComida()
{
    gotoxy(comida[0],comida[1]);
    printf(" ");
    srand(time(NULL));
    comida[0] = (rand() % 48) +1;
    comida[1] = (rand() % 18) +1;
    gotoxy(comida[0],comida[1]);
    printf("%c",4);
}


//Função Main
void jogosnake()
{
    instru();
    getch();
    system("cls");
    int i, gameover=0;
    int tecla;

    for(i=0; i<50; i++)
    {
        gotoxy(i,0);
        printf("%c",219);
        Sleep(5);
    }
    for(i=0; i<20; i++)
    {
        gotoxy(50,i);
        printf("%c",219);
        Sleep(5);
    }
    for(i=50; i>=0; i--)
    {
        gotoxy(i,20);
        printf("%c",219);
        Sleep(05);
    }
    for(i=20; i>0; i--)

    {
        gotoxy(0,i);
        printf("%c",219);
        Sleep(5);
    }

    geraComida();
    desenha();
    tecla='d';
    while(gameover==0)
    {
        gotoxy(52,2);
        printf("Pontos: %d\t",pontos);
        gotoxy(52,4);
        printf("Velocidade: %.2f caracteres/s",(float)1000/velo);
        c[0][0]=cx;
        c[0][1]=cy;

        if(kbhit())
            tecla=getch();

        if(tecla=='w' || tecla=='W' || tecla==72)
        {
            cy--;
            if(cy==0) break;
        }
        if(tecla=='a' || tecla=='A' || tecla==75)
        {
            cx--;
            if(cx==0) break;
        }
        if(tecla=='s' || tecla=='S' || tecla==80)
        {
            cy++;
            if(cy==20) break;
        }
        if(tecla=='d' || tecla=='D' || tecla==77)
        {
            cx++;
            if(cx>=50) break;
        }

        if(cx==comida[0] && cy==comida[1])
        {
            pontos++;
            if(velo>50) velo-=10;
            geraComida();
        }
        gameover=analiza();
        atualiza();
        desenha();
        gotoxy(50,20);
        Sleep(velo);
    }
    system("cls");
    printf("Voce perdeu! Fez %d pontos.\n",pontos);
    system("pause");
}
