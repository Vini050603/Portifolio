#include "rpg.h"

    void atualiza_atributos(Player *P,int Bforca,int Bresist,int Bveloc,int Bmente,int Bmana){
        P->forca = P->forca*Bforca;
        P->resist = P->resist*Bresist;
        P->veloc = P->veloc*Bveloc;
        P->mente = P->mente*Bmente;
        P->mana = P->mana*Bmana;
    }

void JogoRpg()
{
    int s;
    int b;
    Player A;
    cria_personagem(&A);
    define_atributos(&A);

    Item espada;
    strcpy(espada.desc,"Uma espada vermelha, usada por grandes guerreiros, que possui a capacidade de invocar chamas. Nao se sabe como ativar isso.");
    espada.nivel = 1;
    espada.dano = 1000;
    espada.resist = 10000;

    Item arco;
    strcpy(arco.desc,"Um arco com uma misteriosa flecha verde, usado por grandes arqueiros, que possui a capacidade de invocar plantas. Nao se sabe como ativar isso.");
    arco.nivel = 1;
    arco.dano = 1000;
    arco.resist = 10000;

    Item grimorio;
    strcpy(grimorio.desc,"Um grimorio azul, usado por grandes magos, que possui a capacidade de invocar raios. Nao se sabe como ativar isso.");
    grimorio.nivel = 1;
    grimorio.dano = 1000;
    grimorio.resist = 10000;

    srand((unsigned)time(NULL));
    int dado;
    dado = 1+rand()%6;

    s = inicia_tutorial(&A);
    switch(s)
    {
    case 1:
        b = inicia_c1(&A,espada,arco,grimorio,dado);
        break;
    case 2:
        b = inicia_c2(&A,espada,arco,grimorio,dado);
        break;
    case 3:
        b = inicia_c3(&A,espada,arco,grimorio,dado);
        break;
    default:
        break;
    }

    Pilha forca = pilha(10);
    empilha(b,forca);
    Pilha resist = pilha(10);
    empilha(b,resist);
    Pilha veloc = pilha(10);
    empilha(b,veloc);
    Pilha mente = pilha(10);
    empilha(b,mente);
    Pilha mana = pilha(10);
    empilha(b,mana);
    int Bforca = topo(forca);
    int Bresist = topo(resist);
    int Bveloc = topo(veloc);
    int Bmente = topo(mente);
    int Bmana = topo(mana);

    printf("\n Assim ficou seu personagem no final deste tutorial: \n");
    atualiza_atributos(&A,Bforca,Bresist,Bveloc,Bmente,Bmana);
    imprime_atributos(A);
    printf("Sequencia correta do bau era: a %d \n\n",dado);
}
