#include "velha.h"

//Instruções do jogo em pilha
void passoapasso()
{
    char inst4[250] = "4 - Bom jogo!\n";
    char inst3[250] = "3 - O objectivo e conseguir tres circulos ou tres xis em linha, quer horizontal, vertical ou diagonal , e ao mesmo tempo, quando possivel, impedir o adversario de ganhar na proxima jogada!\n";
    char inst2[250] = "2 - Escolha uma coluna e tabela ate o numero 9!\n";
    char inst1[250] = "1 - Caso seja o segundo aguarde o oponente jogar!\n";
    char inst0[250] = "\n\tInstrucoes do jogo!\n";
    Pilha p = pilha(5);
    empilha(inst4, p);
    empilha(inst3, p);
    empilha(inst2, p);
    empilha(inst1, p);
    empilha(inst0, p);
    for(int i = 0; i < 5; i++)
    {
        print(desempilha(p));
    }
    free(p);
}

// Menu de Interação para o inicio do jogo
int menu(void)
{
    int opcao;
        passoapasso();
        getch();
        printf("\t\tJogo da Velha 1.0 \n");
        printf("\n1.Jogar\n");
        printf("0.Sair\n");
        printf("\nOpcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
           case 1:
           case 0:
                break;
           default:
                clear();
                printf("Opcao invalida. Tente de novo!\n");
        }

    return opcao;
}

// Função para limpeza de opções
void clear(void)
{
    int count=0;

    while(count != 100)
    {
        putchar('\n');
        count++;
    }
}


//Insere zero em cada espaço da matriz
void zeraTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            tabuleiro[linha][coluna] = 0;
}

//Função para exibir o tabuleiro e preencher a opção selecionada
void exibeTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    putchar('\n');

    for(linha = 0 ; linha < DIM ; linha++)
    {
        for(coluna = 0 ; coluna < DIM ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else if(tabuleiro[linha][coluna] == 1)
                printf("  X ");
            else
                printf("  O ");

            if(coluna != (DIM-1))
                printf("|");
        }
        putchar('\n');
    }
    putchar('\n');
}


//Essa função basicamente faz o jogo iniciar
void jogar(int tabuleiro[][DIM])
{
    zeraTabuleiro(tabuleiro);

    do
    {
        clear();
        exibeTabuleiro(tabuleiro);
        jogada(tabuleiro);

    }
    while(checaTermino(tabuleiro, vez) != 1);
}


//Aqui verifica em a linha e coluna que o usuario inseriu
int checaLocal(int tabuleiro[][DIM], int linha, int coluna)
{
    if(linha < 0 || linha > (DIM-1) || coluna < 0 || coluna > (DIM-1) || tabuleiro[linha][coluna] != 0)
        return 0;
    else
        return 1;
}


//Essa função checa a soma de de cada linha do tabuleiro
int checaLinha(int tabuleiro[][DIM])
{
    int linha, coluna,
        soma;

    for(linha = 0 ; linha < DIM ; linha++)
    {
        soma=0;

        for(coluna = 0 ; coluna < DIM ; coluna++)
            soma += tabuleiro[linha][coluna];

        if(soma==DIM || soma == (-1)*DIM)
            return 1;
    }

    return 0;
}

//Faz a mesma coisa da função anterior mas checa as colunas
int checaColuna(int tabuleiro[][DIM])
{
    int linha, coluna,
        soma;


    for(coluna = 0 ; coluna < DIM ; coluna++)
    {
        soma=0;

        for(linha = 0 ; linha < DIM ; linha++)
            soma += tabuleiro[linha][coluna];

        if(soma==DIM || soma == (-1)*DIM)
            return 1;
    }

    return 0;
}

//Essa função checa as duas diagonais do tabuleiro
int checaDiagonal(int tabuleiro[][DIM])
{
    int linha,
        diagonal_principal=0,
        diagonal_secundaria=0;

    for(linha = 0 ; linha < DIM ; linha++)
    {
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][DIM-linha-1];
    }

    if(diagonal_principal==DIM || diagonal_principal==(-1)*DIM ||
            diagonal_secundaria==DIM || diagonal_secundaria==(-1)*DIM)
        return 1;

    return 0;
}

//Verifica se houve empate
int checaEmpate(int tabuleiro[][DIM])
{
    int linha, coluna;

    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;

    return 1;
}


// Checkup final para determinar quem venceu
int checaTermino(int tabuleiro[][DIM], int vez)
{
    if(checaLinha(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        system("cls");
        return 1;
    }

    if(checaColuna(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        system("cls");
        return 1;
    }

    if(checaDiagonal(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        system("cls");
        return 1;
    }

    if(checaEmpate(tabuleiro))
    {
        printf("Jogo encerrado. Ocorreu um empate! !\n\n");
        exibeTabuleiro(tabuleiro);
        system("cls");
        return 1;
    }

    return 0;
}

// Insere cada jogada de acordo com o jogador
void jogada(int tabuleiro[][DIM])
{
    int linha, coluna;
    vez++;
    printf("\n--> Jogador %d \n", (vez % 2) + 1);

    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;

        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;

        if(checaLocal(tabuleiro, linha, coluna) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");

    }
    while(checaLocal(tabuleiro, linha, coluna) == 0);

    if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}


//Função Main para iniciar o jogo
void jogovelha()
{
    int tabuleiro[DIM][DIM],
        continuar;

    do
    {
        vez=1;
        continuar = menu();
        if(continuar == 1)
            jogar(tabuleiro);

    }
    while(continuar);
}
