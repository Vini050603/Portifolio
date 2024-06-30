#include "forca.h"

    //Declarando e incializando array cores
char cores_f[55][15]= {
"Anil",
"Azul",
"Bege",
"Branco",
"Bronze",
"Caramelo",
"Carmesim",
"Cobre",
"Ferrugem",
"Gelo",
"Amarelo",
"Ameixa",
"Ametista",
"Gris",
"Preto",
"Jade",
"Carmim",
"Castanho",
"Ciano",
"Cinza",
"Cinzento",
"Jambo",
"Laranja",
"Lavanda",
"Loiro",
"Marrom",
"Mostarda",
"Negro",
"Ocre",
"Oliva",
"Ouro",
"Prata",
"Magenta",
"Malva",
"Marfim",
"Coral",
"Cereja",
"Chocolate",
"Creme",
"Damasco",
"Dourado",
"Escarlate",
"Esmeralda",
"Rosa",
"Roxo",
"Rubro",
"Terracota",
"Tijolo",
"Turquesa",
"Uva",
"Verde",
"Vermelho",
"Vinho",
"Violeta"};

//Declarando e incializando array pa�ses
char paises[55][15] = {
"Akrotiri",
"Alemanha",
"Andorra",
"Chade",
"Chile",
"China",
"Chipre",
"Comores",
"Cuba",
"Angola",
"Anguila",
"Argentina",
"Botsuana",
"Brasil",
"Camboja",
"Catar",
"Curacao",
"Dhekelia",
"Egipto",
"Iraque",
"Irlanda",
"Israel",
"Jamaica",
"Dinamarca",
"Jersey",
"Jibuti",
"Equador",
"Guatemala",
"Guernsey",
"Guiana",
"Haiti",
"Honduras",
"Hungria",
"Kosovo",
"Kuwait",
"Laos",
"Lesoto",
"Niue",
"Noruega",
"Palau",
"Paraguai",
"Peru",
"Portugal",
"Ruanda",
"Salvador",
"Samoa",
"Togo",
"Pitcairn",
"Tokelau",
"Vanuatu",
"Vaticano",
"Venezuela",
"Vietname"
};

//Declarando e incializando array objetos
char objetos [55][15]  = {
"Abajur",
"abridor",
"alicate",
"almofada",
"�ncora",
"andador",
"anel",
"antena",
"anzol",
"apagador",
"apito",
"apontador",
"aquecedor",
"arco",
"balan�a",
"bolha",
"banco",
"bandeira",
"batom",
"ba�",
"bengala",
"ber�o",
"berimbau",
"bexiga",
"bicicleta",
"bid�",
"bigorna",
"borracha",
"bota",
"bot�o",
"cadeado",
"cadeira",
"caderno",
"cajado",
"colar",
"colch�o",
"colher",
"copo",
"Dado",
"dardo",
"dedal",
"dentadura",
"desentupidor",
"desfibrilador",
"desodorante",
"despertador",
"detergente",
"diadema",
"disco",
"disquete",
"DVD",
"Faca",
"xilofone"
};
//Declarando e incializando array nomes
char nome[55][15] = {
"Isabella",
"Valentina",
"Melissa",
"Ana vivela",
"Clara",
"Catarina",
"Ana",
"Aurora",
"Leticia",
"Sara",
"Rebeca",
"Marcia",
"Brenda",
"Diana",
"Estela",
"Micaela",
"Clarissa",
"Miguel",
"Davi",
"Bernardo",
"Nicolas",
"Samuel",
"Theo",
"Gustavo",
"Jo�o Lucas",
"Eduardo",
"Leonardo",
"Benjamin",
"Joaquim",
"Jo�o Miguel",
"Jo�o Vitor",
"Enzo Gabriel",
"Lorenzo",
"Felipe",
"David",
"Samuel",
"Jo�o",
"Hugo",
"Andr�",
"Kevin",
"Filipe",
"Fernando",
"�ngelo",
"J�lio",
"Pablo",
"F�bio",
"Alexander",
"Renato",
"Edgar",
"Duarte",
"Wanderson",
"Igor",
"Luis"
};

void forca(int estado){
    if(estado == 0){
        printf("--------------");
        printf("\n|            |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
    }
     else if(estado == 1){
        printf("--------------");
        printf("\n|            |");
        printf("\n|            o");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
     }
     else if(estado == 2){
        printf("--------------");
        printf("\n|            |");
        printf("\n|            o");
        printf("\n|            |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
     }
     else if(estado == 3){
        printf("--------------");
        printf("\n|            |");
        printf("\n|            o");
        printf("\n|           -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
     }
     else if(estado == 4){
        printf("--------------");
        printf("\n|            |");
        printf("\n|            o");
        printf("\n|           -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
     }
     else if(estado == 5){
        printf("--------------");
        printf("\n|            |");
        printf("\n|            o");
        printf("\n|           -|-");
        printf("\n|           / ");
        printf("\n|");
        printf("\n|");
     }
     else if(estado == 6){
        printf("--------------");
        printf("\n|            |");
        printf("\n|            o");
        printf("\n|           -|-");
        printf("\n|           / \\");
        printf("\n|");
        printf("\n| \n      GAME OVER\n\n");
     }
}

void grande_vencedor(int vencedor1, int erros1, int vencedor2, int erros2){

    if((vencedor1>0)||(vencedor2>0)){
            if(vencedor1>vencedor2){
                printf("\nO Jogador numero 1 foi o vencedor da partida!\n\n");
            }
            else if(vencedor1<vencedor2){
                printf("\nO Jogador numero 2 foi o vencedor da partida!\n\n");
            }
            else{
                if(erros1>0 || erros2>0){
                    if(erros1<erros2){
                        printf("\nO Jogador numero 1 foi o vencedor da partida!\n\n");
                    }
                    else if(erros1>erros2){
                        printf("\nO Jogador numero 2 foi o vencedor da partida!\n\n");
                    }
                else{
                    printf("\nPartida empatada, tente novamente!\n\n");
                }

                }
                else{
                    printf("\nPartida empatada, tente novamente!\n\n");
                }
            }
       }
       else{
        printf("Ambos os competidores perderam a rodada\n\n");
       }
}

void ordena_cores(){
    int x, y, r;
    char aux[20];
    for(x=0; x<=53; x++){
        for(y=x+1; y<=53; y++){
            r = strcmp(cores_f[x], cores_f[y]);
            if(r>0){
                strcpy(aux, cores_f[x]);
                strcpy(cores_f[x], cores_f[y]);
                strcpy(cores_f[y], aux);
            }
        }
    }
}

void ordena_paises(){
    int x, y, r;
    char aux[20];
    for(x=0; x<=53; x++){
        for(y=x+1; y<=53; y++){
            r = strcmp(paises[x], paises[y]);
            if(r>0){
                strcpy(aux, paises[x]);
                strcpy(paises[x], paises[y]);
                strcpy(paises[y], aux);
            }
        }
    }
}

void ordena_objetos(){
    int x, y, r;
    char aux[20];
    for(x=0; x<=53; x++){
        for(y=x+1; y<=53; y++){
            r = strcmp(objetos[x], objetos[y]);
            if(r>0){
                strcpy(aux, objetos[x]);
                strcpy(objetos[x], objetos[y]);
                strcpy(objetos[y], aux);
            }
        }
    }
}

void ordena_nome(){
    int x, y, r;
    char aux[20];
    for(x=0; x<=53; x++){
        for(y=x+1; y<=53; y++){
            r = strcmp(nome[x], nome[y]);
            if(r>0){
                strcpy(aux, nome[x]);
                strcpy(nome[x], nome[y]);
                strcpy(nome[y], aux);
            }
        }
    }
}

void forca_dupla(){
    setlocale(LC_ALL, "Portuguese");

    //vari�veis chaves
    char dica[15];
    char c_aberta[30];
    char chave[30];
    char letra;

    //contadores
    char confirmacao;
    int N_erros=0;
    int possivel_erro=1; //1-sim e 0- n�o
    int j=0;
    char let[15];

    // Vari�veis para contagem do jogador 1
    int vencedor1=0;
    int erros1=0;

    //FUN��O IN�CIO MULTIPLAYER
    do{

        printf("-------Multiplayer-------\n\n");
        printf("Jogador 1 jogando...\n\n");

        printf("Jogador 2:\nInsira palavra secreta:");
        fflush(stdin);
        fgets(chave, 100, stdin);

        //Copiando chave
        chave[strlen(chave)-1] = '\0';
        strcpy(c_aberta, chave);

        printf("Digite tema:");
        fflush(stdin);
        fgets(dica, 15, stdin);

        int tam = strlen(chave);

        //Verificando informa��es inseridas
        printf("\nA palavra secreta digitada �: %s", chave);
        printf("\nA palavra possui %d caracteres\n\n", tam);

        //Lendo confirma��o
        printf("Digite (C/c) para confirmar chave e (E/e) para reescrever:");
        scanf(" %c", &confirmacao);

        //Se valor n�o consizente: digite novamente
        if(strcmp(&confirmacao,"e") == 1 && strcmp(&confirmacao,"E") == 1 && strcmp(&confirmacao,"c") == 1 && strcmp(&confirmacao,"C") == 1){
            printf("\n\nErro Inesperado: A op��o escolhida n�o consta na plica��o!");
            printf("\nDigite (C/c) para confirmar chave e (E/e) para reescrever:");
            scanf(" %s", &confirmacao);
            fflush(stdin);
        }

        //Limpando tela em windows
        system("cls");

        //Fazer passos anteriores enquanto n�o confirmaado
        }while(strcmp(&confirmacao,"e") == 0 || strcmp(&confirmacao,"E") == 0);

        //Imprimindo chave para teste
        //printf("\nchave: %c", c_aberta[strlen(chave)]);

        //Declarando espa�os em chave aberta
        for(int i=0; i<strlen(c_aberta); i++){
            c_aberta[i]='_';
       }

       //Come�ando jogo
       while(1){

            //Imprimindo dica
            printf("\n      %s",dica);

            //chamando forca
            forca(N_erros);

            //Imprimindo palavras preenchidas
            printf("\nPalavra: ");
            for(int i=0; i<=strlen(c_aberta); i++){
                printf(" %c", c_aberta[i]);
            }

            //Lendo letra
            printf("\nLetra: ");
            fflush(stdin);
            scanf(" %c", &letra);

            //Inserindo letra em array
            let[j]=letra;
            j++;

            //Inicializando possivel erro
            //Utilizando ele para contagem de erros
            possivel_erro=1;

            //Comparando letra com cada caracter da chave
            for(int i=0; i<=strlen(c_aberta); i++){
                if(letra == chave[i]){
                    c_aberta[i] = letra;
                    possivel_erro=0;
                }
            }

            //somando um caso erro
            if(possivel_erro == 1){
                N_erros++;
            }

            //Jogador1 recendo erros
            erros1 = N_erros;

            system("cls");

            //se chave igual as palavra jogador venceu
            if(strcmp(chave,c_aberta) == 0){
                forca(N_erros);
                printf("Palavra: %s", c_aberta);
                printf("\n\n            YOU WIN!\n\n");
                vencedor1 =1;
                break;
            }

            //Se numero de erros = 6: Jogador1 perdeu
            if(N_erros==6){
                forca(N_erros);
                printf("A palavra chave era: %s\n\n", chave);
                printf("\n Letras digitadas:\n");
                for(j=0; j<strlen(chave); j++){
                    printf("tentativa %i: %c\n",j+1, let[j]);
                }
                vencedor1 = 0;
                break;
            }
        }

//SEGUNDO JOGADOR

int vencedor2;
int erros2;

    do{

        printf("-------Multiplayer-------\n\n");
        printf("Jogador 2 jogando...\n\n");

        printf("Jogador 1:\nInsira palavra secreta:");
        fflush(stdin);
        fgets(chave, 100, stdin);

        //Copiando chave
        chave[strlen(chave)-1] = '\0';
        strcpy(c_aberta, chave);

        printf("Digite tema:");
        fflush(stdin);
        fgets(dica, 15, stdin);

        int tam2 = strlen(chave);

        //Verificando informa��es inseridas
        printf("\nA palavra secreta digitada �: %s", chave);
        printf("\nA palavra possui %d caracteres\n\n", tam2);

        //Lendo confirma��o
        printf("Digite (C/c) para confirmar chave e (E/e) para reescrever:");
        scanf(" %c", &confirmacao);

        //Se valor n�o consizente: digite novamente
        if(strcmp(&confirmacao,"e") == 1 && strcmp(&confirmacao,"E") == 1 && strcmp(&confirmacao,"c") == 1 && strcmp(&confirmacao,"C") == 1){
            printf("\n\nErro Inesperado: A op��o escolhida n�o consta na plica��o!");
            printf("\nDigite (C/c) para confirmar chave e (E/e) para reescrever:");
            scanf(" %s", &confirmacao);
            fflush(stdin);
        }

        //Limpando tela em windows
        system("cls");

    //Fazer passos anteriores enquanto n�o confirmaado
    }while(strcmp(&confirmacao,"e") == 0 || strcmp(&confirmacao,"E") == 0);

    //Imprimindo chave para teste
    //printf("\nchave: %c", c_aberta[strlen(chave)]);

    //Declarando espa�os em chave aberta
    for(int i=0; i<strlen(c_aberta); i++){
        c_aberta[i]='_';
    }

    //Come�ando jogo
    while(1){

        //Imprimindo dica
        printf("\n      %s",dica);

        //chamando forca
        forca(N_erros);

        //Imprimindo palavras preenchidas
        printf("\nPalavra: ");
        for(int i=0; i<=strlen(c_aberta); i++){
            printf(" %c", c_aberta[i]);
        }

        //Lendo letra
        printf("\nLetra: ");
        fflush(stdin);
        scanf(" %c", &letra);

        //Inserindo letra em array
        let[j]=letra;
        j++;

        //Inicializando possivel erro
        //Utilizando ele para contagem de erros
        possivel_erro=1;

        //Comparando letra com cada caracter da chave
        for(int i=0; i<=strlen(c_aberta); i++){
            if(letra == chave[i]){
                c_aberta[i] = letra;
                possivel_erro=0;
            }
        }

        //somando um caso erro
        if(possivel_erro == 1){
            N_erros++;
        }

        //Jogador1 recendo erros
        erros2 = N_erros;

        system("cls");

        //se chave igual as palavra jogador venceu
        if(strcmp(chave,c_aberta) == 0){
            forca(N_erros);
            printf("Palavra: %s", c_aberta);
            printf("\n\n            YOU WIN!\n\n");
            vencedor2 =1;
            break;
        }

        //Se numero de erros = 6: Jogador1 perdeu
        if(N_erros==6){
            forca(N_erros);
            printf("A palavra chave era: %s\n\n", chave);
            printf("\n Letras digitadas:\n");
            for(j=0; j<strlen(chave); j++){
                printf("tentativa %i: %c\n",j+1, let[j]);
            }
            vencedor2 = 0;
            break;
        }
    }

// GRANDE VENCEDOR

   grande_vencedor(vencedor1,erros1,vencedor2,erros2);
}

//FUN��O: FORCA SOLO
void forca_solo(){

    //Declarando vari�veis
    setlocale(LC_ALL, "Portuguese");
    char chave[55][10];
    char c_aberta[30];
    char letra;
    int N_erros=0;
    int possivel_erro=1; //1-sim e 0- n�o
    char dica[15];
    int op_clas;
    int posicao;
    int palavr;
    int j=0;
    char let[15];

        //FUN��O IN�CIO
            do{

                printf("-------SOLO-------\n\n");
                printf("Jogador \n");
                printf("\n Escolha classifica��o:");
                printf("\n 1 - Cores");
                printf("\n 2 - Pa�ses");
                printf("\n 3 - Objetos");
                printf("\n 4 - Nomes");
                printf("\n");
                scanf("%i", &op_clas);
            }while(op_clas != 1 && op_clas != 2 &&op_clas != 3 && op_clas != 4);

        //Gera valor aleat�rorio entre zero e 53
        srand(time(NULL));
        posicao = (rand() % 53);

        //Limpando tela
        system("cls");

        //Caso de op��o escolhida
        switch (op_clas){

        case (1):
            palavr = strlen(cores_f[posicao]);
            cores_f[posicao][palavr] = '\0';
            strcpy(dica,"Cores");
            strcpy(c_aberta, cores_f[posicao]);
            strcpy(chave[posicao], cores_f[posicao]);
            break;

        case (2):
            //Inserindo quebra de linha no array
            palavr = strlen(paises[posicao]);
            paises[posicao][palavr] = '\0';
            //copiando dica e palavra chave
            strcpy(dica,"Pa�ses");
            strcpy(c_aberta, paises[posicao]);
            strcpy(chave[posicao], paises[posicao]);
            break;

        case (3):
            palavr = strlen(objetos[posicao]);
            objetos[posicao][palavr] = '\0';
            strcpy(dica,"Objetos");
            strcpy(c_aberta, objetos[posicao]);
            strcpy(chave[posicao], objetos[posicao]);
            break;

        case (4):
            palavr = strlen(nome[posicao]);
            nome[posicao][palavr] = '\0';
            strcpy(dica,"Nomes");
            strcpy(c_aberta, nome[posicao]);
            strcpy(chave[posicao], nome[posicao]);
            break;

        default:
        printf("\nERRO");
        }

        //Escrevendo palavra para teste
        //printf("\nchave: %s", chave[posicao]);

        //Declarando espa�os em chave aberta
       for(int i=0; i<palavr; i++){
            c_aberta[i]='_';
       }

       while(1){

       //Iniciando jogo -- mesma forma do multiplayer
            printf("\n      %s\n",dica);
            forca(N_erros);
            printf("\nPalavra: ");

            for(int i=0; i<=strlen(c_aberta); i++){
                printf(" %c", c_aberta[i]);
            }

            printf("\nLetra: ");
            fflush(stdin);
            scanf(" %c", &letra);

            let[j]=letra;
            j++;

            possivel_erro=1;

            for(int i=0; i<=strlen(c_aberta); i++){

                if(tolower(letra) == chave[posicao][i] || toupper(letra) == chave[posicao][i]){
                    c_aberta[i] = letra;
                    possivel_erro=0;
                    chave[posicao][i] = tolower(chave[posicao][i]);
                }

            }

            if(possivel_erro == 1){
                N_erros++;
            }
            system("cls");
            printf("c_aberta: %s \nchave: %s",c_aberta, chave[posicao]);

            //c_aberta = tolower(c_aberta);
            if(strcmp(c_aberta,chave[posicao]) == 0){
                printf("\n");
                forca(N_erros);
                printf("Palavra: %s", c_aberta);
                printf("\n\n            YOU WIN!\n\n");
                break;
            }

            if(N_erros==6){
                forca(N_erros);
                printf("A palavra chave era: %s\n\n", chave[posicao]);
                printf("\nLetras digitadas:\n");
                for(int i=0; i<strlen(let)-1; i++){
                    printf("tentativa %i: %c\n",i+1, let[i]);
                }
                break;
            }
        }
}

//FUN��O: ORDENA PALAVRAS
void palavras_ordenadas(){

    setlocale(LC_ALL, "Portuguese");
    int op_orden;

    system("cls");

    //Escolhendo ordenadas
    printf("\nDeseja:");
    printf("\n1- Cores Ordenadas");
    printf("\n2- Pa�ses Ordenados");
    printf("\n3- Objetos Ordenadas");
    printf("\n4- Nomes Ordenados");
    printf("\n5- todas as op��es a cima\n");
    scanf("%i", &op_orden);

    switch (op_orden){

    case (1):

          printf("\n Cores ordenadas:\n");
          ordena_cores();                   //Fun��o que ordena cores
          for(int c=0; c<=55; c++){
                printf("\n%s", cores_f[c]);
          }
          break;

   case (2):

          printf("\n\n Pa�ses ordenados:\n");
          ordena_paises();                   //Fun��o que ordena pa�ses
          for(int c=0; c<55; c++){
                printf("\n%s", paises[c]);
          }
        break;

    case (3):

          printf("\n\n Objetos ordenados:\n");
          ordena_objetos();                 //Fun��o ordena objetos
          for(int c=0; c<55; c++){
                printf("\n%s", objetos[c]);
          }
        break;

    case (4):

          printf("\n\n Nomes ordenados:\n");
          ordena_nome();                    //Fun��o ordena nomes
          for(int c=0; c<55; c++){
                printf("\n%s", nome[c]);
          }
        break;

    case (5):

          printf("\n Cores ordenadas:\n");
          ordena_cores();
          for(int c=0; c<55; c++){
                    printf("\n%s", cores_f[c]);
          }

          printf("\n\n Pa�ses ordenados:\n");
          ordena_paises();
          for(int c=0; c<55; c++){
                    printf("\n%s", paises[c]);
          }

          printf("\n\n Objetos ordenados:\n");
          ordena_objetos();
          for(int c=0; c<55; c++){
                    printf("\n%s", objetos[c]);
          }

          printf("\n\n Nomes ordenados:\n");
          ordena_nome();
          for(int c=0; c<55; c++){
                    printf("\n%s", nome[c]);
          }
          break;

    }

}

//FUN��O: INSTRU��ES DE JOGO
void regra_forca(){

    setlocale(LC_ALL, "Portuguese");

    printf("REGRAS: FORCA\n");
    printf("SOLO\n");
    printf("\n1 - Ao iniciar o jogo solo o jogador poder� escolher 4 classifica��es a serem jogadas, sendo elas:\n        1.1 - Cores\n        1.2 - Pa�ses\n        1.3 - Objetos\n        1.4 - Nomes");
    printf("\n2 - Logo ap�s a escolha da classifica��o o jogador poder� adivinhar a determinada letra da palavra em c�digo: \n      2.1 - O jogador poder� errar aapenas 6 vezes, morrendo na forca se ultrapassado \n      2.2-Caso a palavra  esta errada aumentar� um caracter no corpo do boneco at� o final de 6 letras errradas \n        2.3 - caso o  jogador acerte a uma das letras da palavra chave ele continua a jogar sem a perca de pontos");
    printf("\n3 - Caso a palavra esteja completa o jogador ganha");
    printf("\n4 - Caso, ao final dos tr�s erros, ele n�o colpete a palavra ele perde");
    printf("\n\n");

    printf("MULTIPLAYER\n");
    printf("\n1 - O jogador 2 inicia inserindo a palavra chave para seu oponente acertar");
    printf("\n2 - O jogador 1 tem a oportunidade de errar apenas 6 vezes a letra da palavra e completa-la antes de perder");
    printf("\n3 - O jogador 1 ganha se acertar a palavra antes dos seis erros");
    printf("\n4 - Logo depois: O jogador 1 inicia inserindo a palavra chave para seu oponente acertar");
    printf("\n5 - O jogador 2 tem a oportunidade de errar apenas 6 vezes a letra da palavra e completa-la antes de perder");
    printf("\n6 - O jogador 2 ganha se acertar a palavra antes dos seis erros");
    printf("\n7 - Definindo jogador:");
    printf("    \n7.1 - Caso os dois n�o acertem a palavra do oponente os dois perdem a partida");
    printf("         \n7.1.1 - Caso o jogador 1 tenha acertado a palavra e o jogador 2 n�o, temos que o vencedor � o jogador 1");
    printf("         \n7.1.2 - Caso o jogador 2 tenha acertado a palavra e o jogador 1 n�o, temos que o vencedor � o jogador 2");
    printf("    \n7.2 - Caso os dois jogadores tenham ganhado a partida iremos para o crit�rio de desempate:");
    printf("         \n7.2.1 - O que tiver o menor n�mero de erros ganha");
    printf("    \n7.3 - Se caso todos tenham ganhado e com a meesma quantidade de erros ocorrer� um empate");

    printf("FIM");
}

void jogoforca(){

        int op_p;
        int op_menu_forca;

        do{
        //Lendo menu inicial
        system("cls");
        printf(">>> JOGO DA FORCA <<<\n\n");
        printf("Escolha opcao:\n");
        printf("1- Solo\n");
        printf("2- Multiplayers\n");
        printf("3- Imprimir palavras ordenadas do banco\n");
        printf("4- regras do jogo\n");
        scanf("%i", &op_p);

        system("cls");
        //aplicando op escolhida
        switch (op_p){

    case (1):

        forca_solo();
        break;

    case (2):

        forca_dupla();
        break;

    case (3):
        palavras_ordenadas();
        break;

    case (4):
        regra_forca();
        break;

        }
    //Caso desejado voltando ao menu do jogo
    printf("\n\nDeseja retornar ao menu:\n1- Sim\n2- N�o\n");
    scanf("%i", &op_menu_forca);

    }while(op_menu_forca == 1);

}
