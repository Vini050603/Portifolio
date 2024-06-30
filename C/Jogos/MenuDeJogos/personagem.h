
    //estrutura de um personagem
    typedef struct {
        char nome[30];
        int idade;
        float altura;
        char aparencia[30];
        char classe[10];
        char reino[15];
        int nivel;
        int gold;
        int hp;
        int forca;
        int resist;
        int veloc;
        int mente;
        int mana;
    } Player;

    //criacao de personagem
    void cria_personagem(Player *P){
        int aux;
        fflush(stdin);
        printf("\n\n- Vamos criar seu personagem.");
        printf("\n\n- Digite o nome: ");
        fgets(P->nome,30,stdin);
        fflush(stdin);
        printf("\n- Digite a idade: ");
        scanf("%d",&P->idade);
        fflush(stdin);
        printf("\n- Digite a altura: ");
        scanf("%f",&P->altura);
        fflush(stdin);
        printf("\n- Digite a aparencia: ");
        fgets(P->aparencia,30,stdin);
        fflush(stdin);
        strcpy(P->reino,"ausente");
        fflush(stdin);
    };

    //definicao de atributos
    void define_atributos(Player *P){
        P->nivel = 1;
        P->gold = 100;
        P->hp = 1000;
        int pontos;
        do{
            pontos = 500;
            printf("\n- Voce possui %d pontos, e precisa distribui-los entre seus atributos.",pontos);
            printf("\n\n- Digite quantos pontos quer colocar em forca: ");
            scanf("%d",&P->forca);
            fflush(stdin);
            pontos = pontos-P->forca;
            printf("\n- Restam %d pontos. Digite quantos pontos quer colocar em resistencia: ",pontos);
            scanf("%d",&P->resist);
            fflush(stdin);
            pontos = pontos-P->resist;
            printf("\n- Restam %d pontos. Digite quantos pontos quer colocar em velocidade: ",pontos);
            scanf("%d",&P->veloc);
            fflush(stdin);
            pontos = pontos-P->veloc;
            printf("\n- Restam %d pontos. Digite quantos pontos quer colocar em mente: ",pontos);
            scanf("%d",&P->mente);
            fflush(stdin);
            pontos = pontos-P->mente;
            printf("\n- Restam %d pontos. Digite quantos pontos quer colocar em mana: ",pontos);
            scanf("%d",&P->mana);
            fflush(stdin);
            pontos = pontos-P->mana;
            if(pontos<0){
                printf("\n [!] SEUS PONTOS FICARAM NEGATIVOS, DISTRIBUA ELES CORRETAMENTE!, VAMOS TENTAR DE NOVO... \n");
            }
        }while(pontos<0);
    }

    //impressao de personagem
    void imprime_personagem(Player P){
        printf("\n Nome: %s \n Idade: %d \n Altura: %.2f \n Aparencia: %s \n Classe: %s \n Reino: %s", P.nome,P.idade,P.altura,P.aparencia,P.classe,P.reino);
    }
    void imprime_atributos(Player P){
        printf("\n Nivel: %d \n Gold: %d \n hp: %d \n forca: %d \n resistencia: %d \n velocidade: %d \n mente: %d \n mana: %d \n\n Classe: %s (definida com base na arma que voce escolheu) \n Reino escolhido: %s (definido com base no reino que voce escolheu ir)\n\n",P.nivel,P.gold,P.hp,P.forca,P.resist,P.veloc,P.mente,P.mana,P.classe,P.reino);
    }

