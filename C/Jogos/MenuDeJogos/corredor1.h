
    int inicia_c1(Player *P, Item I, Item J, Item K, int dado){
        int b = 1;
        int acao;
        int aux = 0;
        printf("\n\n - Certo, creio que voce tenha entendido a dinamica de decisoes, entao a partir de agora irei narrar de forma mais direta.");
        printf("\n [...]");
        printf("\n ''Seguindo pelo corredor frio, em determinado ponto voce se deparou com 3 cadaveres deitados no chao. Todos eram de homens, na faixa dos 30-40 anos, mas cada um estava segurando algo diferente, ou melhor dizendo, uma arma diferente. Um estava segurando uma espada vermelha, outro um arco com uma flecha verde, e o terceiro um grimorio azul (livro magico).'' ");
        printf("\n 1) Pego e analiso a espada.");
        printf("\n 2) Pego e analiso o arco.");
        printf("\n 3) Pego e analiso o grimorio.");
        fflush(stdin);
        do{
            printf("\n- Acao: ");
            scanf("%d",&acao);
            switch(acao){
                case 1:
                    printf("\n ''Estas foram as informacoes que vc obteve:'' ");
                    printf("\n nivel do item: %d \n dano: %d \n resist: %d \n",I.nivel,I.dano,I.resist);
                    strcpy(P->classe,"guerreiro");
                    aux = 1;
                    break;
                case 2:
                    printf("\n ''Estas foram as informacoes que vc obteve:'' ");
                    printf("\n nivel do item: %d \n dano: %d \n resist: %d \n",J.nivel,J.dano,J.resist);
                    strcpy(P->classe,"arqueiro");
                    aux = 2;
                    break;
                case 3:
                    printf("\n ''Estas foram as informacoes que vc obteve:'' ");
                    printf("\n nivel do item: %d \n dano: %d \n resist: %d \n",K.nivel,K.dano,K.resist);
                    strcpy(P->classe,"mago");
                    aux = 3;
                    break;
                default:
                    acao = 0;
                    printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                    break;
            }
        }while(acao==0);
        printf("\n ''Apos analisar este item, voce percebeu que os demais desapareceram, como se nunca tivessem existido. Tambem percebeu que o final do corredor ja era visivel, e aparentemente levava ate um salao.'' ");
        printf("\n 1) Sigo ate o final do corredor com a arma.");
        printf("\n 2) Largo a arma e sigo ate o final do corredor.");
        printf("\n 3) Uso a arma para me suicidar.");
        do{
            printf("\n- Acao: ");
            scanf("%d",&acao);
            switch(acao){
                case 1:
                    printf("\n ''Apos alguns segundos, voce chegou ate o salao no final do corredor, percebendo que havia um zumbi no centro dele, protegendo um belo bau de tesouros. O local eh circular e possui um raio de aproximadamente 25 metros, contendo duas portas de saida.'' ");
                    break;
                case 2:
                    strcpy(P->classe,"\n (nao foi possivel determinar sua classe pois voce nao escolheu uma arma)");
                    aux = 0;
                    printf(" ''\n Apos alguns segundos, voce chegou ate o salao no final do corredor, percebendo que havia um zumbi no centro dele, protegendo um belo bau de tesouros. O local eh circular e possui um raio de aproximadamente 25 metros, contendo duas portas de saida.'' ");
                    break;
                case 3:
                    P->hp=0;
                    b = 0;
                    return b;
                default:
                    acao = 0;
                    printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                    break;
            }
        }while(acao==0);
        printf("\n ''Felizmente, o zumbi esta de costas para voce, e ainda nao percebeu sua presenca, pois esta fixamente olhando para o bau do salao.'' ");
        printf("\n 1) Avanco contra o zumbi e utilizo a arma/punhos para tentar atingi-lo por tras, mirando em sua cabeca.");
        printf("\n 2) Avanco contra o zumbi realizando uma voadora mirada em suas costas.");
        do{
            printf("\n- Acao: ");
            scanf("%d",&acao);
            switch(acao){
                case 1:
                    if(aux==1){
                        printf("\n ''Voce acertou sua espada na cabeca do zumbi, e eis que imediatamente o corpo dele comecou a ser consumido por chamas que foram invocadas atraves do fio de sua arma. Agora voce sabe que atingir oponentes com ela faz eles serem incendiados. O zumbi foi consumido ate virar cinzas, mas um pequeno objeto que estava no corpo dele sobreviveu ao incendio, caindo no chao. Este objeto era uma chave.'' ");
                    }
                    else if(aux==2){
                        printf("\n ''Voce acertou a flecha de seu arco na cabeca do zumbi, e eis que imediatamente brotou uma planta carnivora saindo do corpo dele e o consumiu por completo. Apos isso, a planta adentrou no solo e desapareceu. Agora voce sabe que atingir oponentes com a flecha do arco faz eles serem devorados. Apesar do zumbi ter sido inteiramente comido, voce percebeu que um pequeno objeto havia caido do corpo dele, atingindo o chao. Este objeto era uma chave.'' ");
                    }
                    else if(aux==3){
                        printf("\n ''Voce conseguiu fazer o grimorio disparar um raio na cabeca do zumbi, e eis que imediatamente o corpo dele foi eletrocutado por completo, o fazendo cair no chao imovel. Agora voce sabe que mirar em alvos com este item faz ele invocar seu poder eletrico. Com a queda do zumbi, voce percebeu que um pequeno objeto havia saido do corpo dele, atingindo o chao. Este objeto era uma chave.'' ");
                    }
                    else{
                        printf("\n ''Voce atingiu o zumbi em cheio, mas ele nao sofreu danos, e ainda se virou velozmente para te atacar, conseguindo morder seu pescoco e te matar. Isso nao teria acontecido se voce tivesse usado uma arma.'' ");
                        P->hp=0;
                        b = 0;
                        return b;
                    }
                    break;
                case 2:
                    printf("\n ''Voce atingiu o zumbi com a voadora, mas ele era tao resistente que nem foi empurrado, inves disso virou em sua direcao em alta velocidade e mordeu seu pescoco, te matando. Isso nao teria acontecido se voce tivesse usado uma arma.'' ");
                    P->hp=0;
                    b = 0;
                    return b;
                default:
                    acao = 0;
                    printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                    break;
            }
        }while(acao==0);
        aux = 0;
        printf(" ''\n Uma das portas de saida do salao aparentava ter a fechadura ideal para esta chave, e a outra nao tinha fechadura, inves disso possuia uma bomba colada em sua estrutura. Alem disso, o bau de tesouros do salao agora esta desprotegido, mas ele possui um cadeado de senha, cujas opcoes de sequencia sao: \n sequencia 1: 123 \n sequencia 2: 132 \n sequencia 3: 213 \n sequencia 4: 231 \n sequencia 5: 312 \n sequencia 6: 321");
        printf("\n 1) Escolho a sequencia 1 para tentar abrir o cadeado.");
        printf("\n 2) Escolho a sequencia 2 para tentar abrir o cadeado.");
        printf("\n 3) Escolho a sequencia 3 para tentar abrir o cadeado.");
        printf("\n 4) Escolho a sequencia 4 para tentar abrir o cadeado.");
        printf("\n 5) Escolho a sequencia 5 para tentar abrir o cadeado.");
        printf("\n 6) Escolho a sequencia 6 para tentar abrir o cadeado.");
        printf("\n 7) Ignoro o bau e vou ate a porta com a fechadura ideal, usando a chave para abrir a mesma.");
        printf("\n 8) Ignoro o bau e vou ate a porta com a bomba colada, analisando o item para descobrir algo.");
        do{
            printf("\n- Acao: ");
            scanf("%d",&acao);
                if(acao==dado){
                    printf("\n ''Voce conseguiu acertar a sequencia e abrir o bau, obtendo um total de 10000 de Gold.'' ");
                    P->gold = P->gold+10000;
                    printf("\n 1) Sigo para a porta da fechadura, usando a chave para abrir a mesma.");
                    do{
                        printf("\n- Acao: ");
                        scanf("%d",&acao);
                        switch(acao){
                            case 1:
                                break;
                            default:
                                acao = 0;
                                printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                break;
                        }
                    }while(acao==0);
                }
                else if((acao>=1) && (acao<=6) && (acao!=dado)){
                    printf("\n ''Infelizmente voce errou a sequencia, deseja tentar novamente?'' ");
                    printf("\n 1-sim \n 2-nao \n decisao: ");
                    scanf("%d",&acao);
                    if(acao==1){
                        aux++;
                        if(aux==3){
                            printf("\n ''Infelizmente o cadeado enferrujou e suas chances acabaram.'' ");
                            printf("\n 1) Sigo para a porta da fechadura, usando a chave para abrir a mesma.");
                            do{
                                printf("\n- Acao: ");
                                scanf("%d",&acao);
                                switch(acao){
                                    case 1:
                                        break;
                                    default:
                                        acao = 0;
                                        printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                        break;
                                }
                            }while(acao==0);
                        }
                        else{
                            acao=0;
                        }
                    }
                    else if(acao==2){
                        break;
                    }
                    else{
                        printf("[!] VOU ENTENDER COMO UM NAO");
                        break;
                    }
                }
                else if(acao==7){
                    printf("\n ''Voce conseguiu abrir a porta, se deparando com uma escadaria que leva ate a saida desse calabouco. Neste momento voce tambem se lembrou de que possuia um mapa em seu bolso, indicando as localizacoes dos principais reinos do continente: Dorian, Liturq e Valberik. De repente, o calabouco comecou a desmoronar, entao voce precisa fugir agora.'' ");
                    printf("\n 1) Sigo para fora do calabouco e inicio minha viagem ate Dorian.");
                    printf("\n 2) Sigo para fora do calabouco e inicio minha viagem ate Liturq.");
                    printf("\n 3) Sigo para fora do calabouco e inicio minha viagem ate Valberik.");
                    do{
                        printf("\n- Acao: ");
                        scanf("%d",&acao);
                        switch(acao){
                            case 1:
                                strcpy(P->reino,"Dorian");
                                return b;
                            case 2:
                                strcpy(P->reino,"Liturq");
                                return b;
                            case 3:
                                strcpy(P->reino,"Valberik");
                                return b;
                            default:
                                acao = 0;
                                printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                break;
                        }
                    }while(acao==0);
                }
                else if(acao==8){
                    printf("\n ''Voce observou que a bomba possui 3 fios: um vermelho, um verde e um azul. Havia o simbolo da cabeca de um zumbi impresso nessa bomba, talvez isso seja uma pista que indique qual fio eh o correto para se cortar, ou seja, o que permitira a abertura da porta de forma segura.'' ");
                    printf("\n 1) Corto o fio vermelho.");
                    printf("\n 2) Corto o fio verde.");
                    printf("\n 3) Corto o fio azul.");
                    do{
                        printf("\n- Acao: ");
                        scanf("%d",&acao);
                        switch(acao){
                            case 1:
                                printf("\n  ''A bomba explodiu violentamente e voce morreu.'' ");
                                P->hp=0;
                                b = 0;
                                return b;
                            case 2:
                                printf("\n ''A bomba explodiu de forma contida e apenas afetou a porta, que se abriu, revelando um pequeno armazem de 1 metro quadrado, onde haviam diversos frascos com pocoes magicas, todas de coloracao branca.'' ");
                                printf("\n 1) pego e bebo uma pocao.");
                                printf("\n 2) ignoro as pocoes e sigo para a porta da fechadura, usando a chave para abrir a mesma.");
                                do{
                                    printf("\n- Acao: ");
                                    scanf("%d",&acao);
                                    switch(acao){
                                        case 1:
                                            printf("\n ''Voce sentiu sua forca, resistencia, velocidade, mente e mana sendo dobradas apos beber esta pocao.'' ");
                                            b = 2;
                                            printf("\n 1) Sigo para a porta da fechadura, usando a chave para abrir a mesma.");
                                            do{
                                                printf("\n- Acao: ");
                                                scanf("%d",&acao);
                                                switch(acao){
                                                    case 1:
                                                        break;
                                                    default:
                                                        acao = 0;
                                                        printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                                        break;
                                                }
                                            }while(acao==0);
                                            break;
                                        case 2:
                                            break;
                                        default:
                                            acao = 0;
                                            printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                            break;
                                    }
                                }while(acao==0);
                                break;
                            case 3:
                                printf("\n  ''A bomba explodiu violentamente e voce morreu.'' ");
                                P->hp=0;
                                b = 0;
                                return b;
                            default:
                                acao = 0;
                                printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                break;
                        }
                    }while(acao==0);
                }
                else{
                    acao = 0;
                    printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                }
        }while(acao==0);
        printf("\n ''Voce conseguiu abrir a porta, se deparando com uma escadaria que leva ate a saida desse calabouco. Neste momento voce tambem se lembrou de que possuia um mapa em seu bolso, indicando as localizacoes dos principais reinos do continente: Dorian, Liturq e Valberik. De repente, o calabouco comecou a desmoronar, entao voce precisa fugir agora.'' ");
        printf("\n 1) Sigo para fora do calabouco e inicio minha viagem ate Dorian.");
        printf("\n 2) Sigo para fora do calabouco e inicio minha viagem ate Liturq.");
        printf("\n 3) Sigo para fora do calabouco e inicio minha viagem ate Valberik.");
        do{
            printf("\n- Acao: ");
            scanf("%d",&acao);
            switch(acao){
                case 1:
                    strcpy(P->reino,"Dorian");
                    return b;
                case 2:
                    strcpy(P->reino,"Liturq");
                    return b;
                case 3:
                    strcpy(P->reino,"Valberik");
                    return b;
                default:
                    acao = 0;
                    printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                    break;
            }
        }while(acao==0);
}
