#include "pacman.h"

//variaveis globais do pacman
int vidas = 3;
int tempilula = 0;

int  acabou ()//verifica se o jogo acabou
{
    POSICAO pos;
    int ganhou = !encontramapa(&m,&pos,FANTASMA);
    int perdeu = !encontramapa(&m, &pos, PILULA);
    if(perdeu == 1 && tempilula == 0)
    {
        print("Acabou suas p�lulas!\nGAME OVER!!!\n");
        getch();
        destroimapa(&m);
        vidas = 3;
        return perdeu;
    }
    else if(ganhou == 1){
        felicitacoes();
        vidas = 3;
        return ganhou;
    }
    else if(vidas == 0){
        vidas = 3;
        return 1;
    }
    return  ganhou;
}
void instrucoes()// instru��es para o jogador
{
    char inst5[250] = "5 - Bom jogo!\n";
    char inst4[250] = "4 - Movimente o pacman com w - cima, a - esquerda, d- direita e s - baixo\n";
    char inst3[250] = "3 - Voc� ter� 3 vidas em qualquer dificuldade, use-as com cuidado!\n";
    char inst2[250] = "2 - Pegue a pilula e exploda os fantasmas!(Obs: uma de cada vez, seu heroi s� pode carregar uma!\n";
    char inst1[250] = "1 - N�o deixe os fantasmas chegarem perto de voc�!\n";
    char inst0[250] = "\n\tInstru��es do jogo!\n";
    Pilha p = pilha(6);
    empilha(inst5, p);
    empilha(inst4, p);
    empilha(inst3, p);
    empilha(inst2, p);
    empilha(inst1, p);
    empilha(inst0, p);
    for(int i = 0; i < 6; i++){
    print(desempilha(p));
    }
    free(p);
}

void dificuldade()//para usuario escolher a dificuldade do jogo
{
    int level;
    level = entradaint("Digite o level que deseja jogar: (1 - (F�cil), 2 - (M�dio), 3 - (Dificil) )\n");//primeira edi��o copilado

    switch(level)
    {
    case 1:
        lemapa(&m, 1);
        break;
    case 2:
        lemapa(&m, 2);
        break;
    case 3:
        lemapa(&m, 3);
        break;
    default:
        print("ERRO, Level inv�lido!, Jogo na dificuldade dificil!\n");
        lemapa(&m, 3);
        break;
    }
}

void fantasmas()//verefica onde o fantasma esta para mover-lo
{
    MAPA copia;
    copiamapa(&copia, &m);
    for(int i = 0; i < m.linhas; i++)
    {
        for(int j = 0; j < m.colunas; j++)
        {
            if(copia.matriz[i][j] == FANTASMA)
            {
                int xdestino;
                int ydestino;
                int encontrou = paraondefantasmavai(i, j, &xdestino, &ydestino);
                if(encontrou)
                {
                    fandanomapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }
    destroimapa(&copia);
}

int paraondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino )// seta o destino do fanstama aleatoriamente
{
    int opcoes[4][2] =
    {
        { xatual, yatual +1},
        { xatual +1, yatual},
        { xatual, yatual -1},
        { xatual -1, yatual}
    };
    srand(time(0));
    for(int i = 0; i < 17; i++)
    {
        int posicao = rand() % 4;

        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1]))
        {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
}

int direcoes(char direcao)// dire��es que podem ser usadas
{
    return      direcao == 'a' ||
                direcao == 'w' ||
                direcao == 's' ||
                direcao == 'd';
}

void move_pers(char direcao)//move o personagem pelo o mapa de acordo com a dire��o passada por parametro
{
    if(!direcoes(direcao))
        return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao)
    {
    case ESQUERDA:
        proximoy--;
        break;
    case CIMA:
        proximox--;
        break;
    case BAIXO:
        proximox++;
        break;
    case DIREITA:
        proximoy++;
        break;
    }
    if(!podeandar(&m, HEROI, proximox, proximoy))
        return;

    if (pacman(&m, PILULA, proximox, proximoy))
        tempilula= 1 ;

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
}

void alocamapa(MAPA* m)//aloca o mapa dinamicamente
{
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i < m->linhas; i++)
    {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void destroimapa(MAPA* m)//  detroi o mapa depois que finaliza o jogo
{
    for(int i = 0; i < m->linhas; i++)
    {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

int valida(MAPA* m, int x, int y)//valida se a posi��o existe
{
    if(x >= m->linhas)
        return 0;
    if(y >= m->colunas)
        return 0;
    return 1;
}

int vazia(MAPA* m, int x, int y)//deixa vazio um espa�o no mapa
{
    return m->matriz[x][y] == VAZIO;
}

int encontramapa(MAPA* m, POSICAO* p, char c)//encontra no mapa coisas passadas pelo o parametro char c
{
    for(int i = 0; i < m->linhas; i++)
    {
        for(int j = 0; j < m->colunas; j++)
        {
            if(m->matriz[i][j] == c)
            {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

int paredes(MAPA* m, int x, int y)//seta paredes no mapa
{
    return m->matriz[x][y] == PAREDE_VERTICAL ||
           m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int pacman(MAPA* m, char personagem, int x, int y)//seta o pacman no mapa
{
    return m->matriz[x] [y] == personagem;

}

int podeandar(MAPA* m, char personagem, int x, int y)// ver se � possivel andar, ou seja, se � parede ou personagem
{
    return
        valida(m, x, y) &&
        !paredes(m, x, y) &&
        !pacman(m, personagem, x, y);
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino)// pacman anda no mapa por onde for possivel
{
    char personagem = m->matriz[xorigem][yorigem];
    if(m->matriz[xdestino][ydestino] == FANTASMA)
    {
        m->matriz[xorigem][yorigem] = VAZIO;
        m->matriz[xdestino][ydestino] = FANTASMA;
        xdestino = 5;
        ydestino = 8;
        m->matriz[xdestino][ydestino] = personagem;
        heroi.x = xdestino;
        heroi.y = ydestino;
        vidas--;
        if(vidas ==0)
        {
            return;
        }
        printf("\n\tVoc� tem %d vidas agora, cuidado!\n", vidas);
        getch();
    }
    else
    {
        m->matriz[xdestino][ydestino] = personagem;
        m->matriz[xorigem][yorigem] = VAZIO;
        heroi.x = xdestino;
        heroi.y = ydestino;
    }
}

void fandanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino)// fantasma anda no mapa por onde for possivel
{
    char personagem = m->matriz[xorigem][yorigem];
    if(m->matriz[xdestino][ydestino] == PILULA)
    {
        m->matriz[xdestino][ydestino] = personagem;
        m->matriz[xorigem][yorigem] = PILULA;
    }
    else if(m->matriz[xdestino][ydestino] == VAZIO)
    {
        m->matriz[xdestino][ydestino] = personagem;
        m->matriz[xorigem][yorigem] = VAZIO;
    }
    else if(m->matriz[xdestino][ydestino] == HEROI)
    {
        m->matriz[xorigem][yorigem] = VAZIO;
        m->matriz[xdestino][ydestino] = FANTASMA;
        xdestino = 5;
        ydestino = 8;
        m->matriz[xdestino][ydestino] = HEROI;
        heroi.x = xdestino;
        heroi.y = ydestino;
        vidas--;
        if(vidas ==0)
        {
            return;
        }
        printf("\n\tVoc� tem %d vidas agora, cuidado!\n", vidas);
        getch();
    }
}

void copiamapa(MAPA* destino, MAPA* origem)
{
    destino->linhas = origem->linhas;
    destino->colunas= origem->colunas;
    alocamapa(destino);
    for(int i = 0; i < origem->linhas; i++)
    {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void lemapa(MAPA* m, int escolha)
{
    FILE* f;
    if(escolha == 1)
    {
        f = fopen("mapa1.txt", "r");
    }
    else if(escolha == 2)
    {
        f = fopen("mapa2.txt", "r");
    }
    else if(escolha == 3)
    {
        f = fopen("mapa3.txt", "r");
    }
    if (f == 0)
    {
        printf("Erro na leitura do mapa\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocamapa(m);
    for(int i = 0; i < 8; i++)
    {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void explodepilula ()//explode pilula que esta com pacman
{
    if (!tempilula) return;
    explodepilula2(heroi.x, heroi.y, 0,1,4);
    explodepilula2(heroi.x, heroi.y, 0,-1,4);
    explodepilula2(heroi.x, heroi.y, 1,0,4);
    explodepilula2(heroi.x, heroi.y, -1,0,4);
    tempilula=0;
}

void explodepilula2 (int x, int y, int somax, int somay, int qtd)// seta os lugares vazio onde n�o for parede apos a explos�o
{
    if (qtd == 0) return;
    int novox = x + somax;
    int novoy = y + somay;
    if (!valida(&m, novox, novoy)) return;
    if (paredes(&m, novox, novoy)) return;
    m.matriz[novox][novoy] = VAZIO;
    explodepilula2(novox, novoy, somax, somay, qtd - 1);
}

char desenhoparedehorizontal[4][7] =
{
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhofantasma[4][7] =
{
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoheroi[4][7] =
{
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhopilula[4][7] =
{
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] =
{
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeparte(char desenho[4][7], int parte)
{
    printf("%s", desenho[parte]);
}

void imprime_mapa(MAPA* m)
{
    for( int i = 0; i < m->linhas; i++)
    {
        for( int parte = 0; parte < 4; parte++)
        {
            for( int j = 0; j < m->colunas; j++)
            {
                switch(m->matriz[i][j])
                {
                case FANTASMA:
                    imprimeparte(desenhofantasma, parte);
                    break;
                case HEROI:
                    imprimeparte(desenhoheroi, parte);
                    break;
                case PILULA:
                    imprimeparte(desenhopilula, parte);
                    break;
                case PAREDE_VERTICAL:
                case PAREDE_HORIZONTAL:
                    imprimeparte(desenhoparedehorizontal, parte);
                    break;
                case VAZIO:
                    imprimeparte(desenhovazio, parte);
                    break;
                }

            }
            print("\n");
        }

    }
}

void felicitacoes()
{
    //filas
print("\tParab�ns voc� venceu!!!\n");
print("                              Y\\     /Y       \n");
print("                              | \\ _ / |       \n");
print("        _____                 | =(_)= |        \n");
print("    ,-~'     '~-.           ,-~\\/^ ^\\/~-.    \n");
print("  ,^ ___     ___ ^.       ,^ ___     ___ ^.    \n");
print(" / .^   ^. .^   ^. \\     / .^   ^. .^   ^. \\   \n");
print("Y  l    O! l    O!  Y   Y  lo    ! lo    !  Y  \n");
print("l_ `.___.' `.___.' _[   l_ `.___.' `.___.' _[  \n");
print("l^~'-------------'~^I   l^~'-------------'~^I  \n");
print("!\\,               ,/!   !                   ! \n");
print(" \\ ~-.,_______,.-~ /     \\                 /  \n");
print("  ^.             .^       ^.             .^    \n");
print("    '-.._____.,-'           '-.._____.,-'      \n");
}

void jogopacman()//chama jogo do pacman
{
    limpatela();
    instrucoes();
    pausa();
    limpatela();
    dificuldade();
    limpatela();
    encontramapa(&m, &heroi, HEROI);
    do
    {
        printf("Pilula: %s\n", (tempilula ? "SIM" : "NAO"));
        imprime_mapa(&m);
        char comando;
        comando = getch();
        if (direcoes(comando))
            move_pers(comando);
        if (comando == BOMBA)
            explodepilula();
        fantasmas();
        limpatela();//fun��o apenas para windows
    }
    while (!acabou());
}
