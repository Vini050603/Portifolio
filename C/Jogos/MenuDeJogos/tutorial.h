
    int inicia_tutorial(Player *P){
        int acao;
        printf("\n\n- Agora voce esta pronto para o tutorial, onde sera explicado como este rpg funciona :D");
        printf("\n\n- Eu sempre irei narrar a situacao do seu personagem, e em seguida apresentarei as opcoes do que voce pode fazer diante de cada contexto.");
        printf("\n\n- Para exemplificar, imagine que a narracao seja:");
        printf("\n ''Voce acorda no chao de um local mal iluminado. Aparentemente, voce esta numa sala de um calabouco (prisao subterranea). Existem 3 portas ao seu redor (uma em sua direita, uma em sua esquerda, e uma em sua frente) e mais nenhuma outra forma de saida.");
        printf("\n\n- Agora, voce devera escolher o que fazer diante dessa situacao, suas escolhas serao listadas abaixo:");
        printf("\n 1) Abro a porta em minha direita.");
        printf("\n 2) Abro a porta em minha esquerda.");
        printf("\n 3) Abro a porta em minha frente.");
        printf("\n\n- Apos analisar com atencao, e ter certeza de sua decisao, apenas digite o numero da acao no campo solicitado...");
        do{
            printf("\n- Acao: ");
            scanf("%d",&acao);
            switch(acao){
                case 1:
                    printf("\n\n ''Voce se deparou com um longo corredor frio que exala um forte odor de cadaveres.'' ");
                    printf("\n\n - O que voce faz agora?");
                    printf("\n 1) Sigo por esse corredor.");
                    printf("\n 2) Abro as outras portas.");
                    do{
                        printf("\n- Acao: ");
                        scanf("%d",&acao);
                        switch(acao){
                            case 1:
                                return 1;
                            case 2:
                                printf("\n\n ''Na porta em sua esquerda, voce se deparou com um longo corredor quente que possui diversos ossos humanos espalhados pelo chao.'' ");
                                printf("\n\n ''Na porta em sua frente, voce se deparou com um longo corredor umido que possui diversas teias de aranha pelo teto.'' ");
                                printf("\n\n - Voce precisara tomar uma decisao crucial !, qual corredor escolher..?");
                                printf("\n 1) Sigo pelo corredor em minha direita.");
                                printf("\n 2) Sigo pelo corredor em minha esquerda.");
                                printf("\n 3) Sigo pelo corredor em minha frente.");
                                do{
                                    printf("\n- Acao: ");
                                    scanf("%d",&acao);
                                    switch(acao){
                                        case 1:
                                            return 1;
                                        case 2:
                                            return 2;
                                        case 3:
                                            return 3;
                                        default:
                                            acao = 0;
                                            printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                            break;
                                    }
                                }while(acao==0);
                            default:
                                acao = 0;
                                printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                break;
                        }
                    }while(acao==0);
                    break;
                case 2:
                    printf("\n\n ''Voce se deparou com um longo corredor quente que possui diversos ossos humanos espalhados pelo chao.'' ");
                    printf("\n\n - O que voce faz agora?");
                    printf("\n 1) Sigo por esse corredor.");
                    printf("\n 2) Abro as outras portas.");
                    do{
                        printf("\n- Acao: ");
                        scanf("%d",&acao);
                        switch(acao){
                            case 1:
                                return 2;
                            case 2:
                                printf("\n\n ''Na porta em sua direita, voce se deparou com um longo corredor frio que exala um forte odor de cadaveres.'' ");
                                printf("\n\n ''Na porta em sua frente, voce se deparou com um longo corredor umido que possui diversas teias de aranha pelo teto.'' ");
                                printf("\n\n - Voce precisara tomar uma decisao crucial !, qual corredor escolher..?");
                                printf("\n 1) Sigo pelo corredor em minha direita.");
                                printf("\n 2) Sigo pelo corredor em minha esquerda.");
                                printf("\n 3) Sigo pelo corredor em minha frente.");
                                do{
                                    printf("\n- Acao: ");
                                    scanf("%d",&acao);
                                    switch(acao){
                                        case 1:
                                            return 1;
                                        case 2:
                                            return 2;
                                        case 3:
                                            return 3;
                                        default:
                                            acao = 0;
                                            printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                            break;
                                    }
                                }while(acao==0);
                            default:
                                acao = 0;
                                printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                break;
                        }
                    }while(acao==0);
                    break;
                case 3:
                    printf("\n\n ''Voce se deparou com um longo corredor umido que possui diversas teias de aranha pelo teto.'' ");
                    printf("\n\n - O que voce faz agora?");
                    printf("\n 1) Sigo por esse corredor.");
                    printf("\n 2) Abro as outras portas.");
                    do{
                        printf("\n- Acao: ");
                        scanf("%d",&acao);
                        switch(acao){
                            case 1:
                                return 3;
                            case 2:
                                printf("\n\n ''Na porta em sua direita, voce se deparou com um longo corredor frio que exala um forte odor de cadaveres.'' ");
                                printf("\n\n ''Na porta em sua esquerda, voce se deparou com um longo corredor quente que possui diversos ossos humanos espalhados pelo chao.'' ");
                                printf("\n\n - Voce precisara tomar uma decisao crucial !, qual corredor escolher..?");
                                printf("\n 1) Sigo pelo corredor em minha direita.");
                                printf("\n 2) Sigo pelo corredor em minha esquerda.");
                                printf("\n 3) Sigo pelo corredor em minha frente.");
                                do{
                                    printf("\n- Acao: ");
                                    scanf("%d",&acao);
                                    fflush(stdin);
                                    switch(acao){
                                        case 1:
                                            return 1;
                                        case 2:
                                            return 2;
                                        case 3:
                                            return 3;
                                        default:
                                            acao = 0;
                                            printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                            break;
                                    }
                                }while(acao==0);
                            default:
                                acao = 0;
                                printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                                break;
                        }
                    }while(acao==0);
                    break;
                default:
                    acao = 0;
                    printf("\n\n [!] DIGITE UM NUMERO VALIDO, VAMOS TENTAR NOVAMENTE...");
                    break;
            }
        }while(acao==0);
    }

