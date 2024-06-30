#include "modulologin.h"

int op;
void cadastro(char arq[])//cadastra somente usuarios
{
    USUARIO u;
    int quantidade = 1;

    FILE *f = fopen(arq, "ab+");

    while(fread(&u, sizeof(USUARIO), 1, f))
    {
        quantidade++;
    }
    u.ncadastro = quantidade;



    fflush(stdin);
    strcpy(u.nome, entradastr("\nDigite o nome: "));

    do
    {
        fflush(stdin);
        strcpy(u.CPF, entradastr("\nDigite o cpf: "));

    }
    while (cpf_f(u.CPF)==0);

    do
    {
        fflush(stdin);
        strcpy(u.email, entradastr("\nDigite o email: "));

    }
    while(email_f(u.email)==0);

    do
    {
        fflush(stdin);
        strcpy(u.senha, entradastr("\nDigite o senha: "));

    }

    while (senha_f(u.senha)==0);
    printf("Seu n�mero de cadastro � %d\n", u.ncadastro);
    u.tipocad = 2;

    fwrite(&u, sizeof(USUARIO), 1, f);

    quantidade++;

    print("\n****************************\nCadastro feito com sucesso\n****************************\n");

    op = entradaint("\n Deseja voltar para a p�gina principal? \n1- Sim \n2- N�o\n");

    fclose(f);
}

void login(char arq[])// realiza login
{
    limpatela();
    int opcao = 0;
    char email_i[50];
    char senha_i[50];
    int log=0;
    int op=0;
    USUARIO u;

    do
    {
        fflush(stdin);
        strcpy(email_i, entradastr("\nDigite seu email: "));

        fflush(stdin);
        strcpy(senha_i, entradastr("\nDigite sua senha: "));

        FILE *f = fopen(arq, "rb");

        if(f==NULL)
        {
            print("\nErro ao tentar ler o arquivo. \n");
        }
        else
        {
            while(fread(&u, sizeof(USUARIO), 1, f))
            {
                if(strcmp(email_i,u.email) == 0 && strcmp( senha_i, u.senha) == 0)
                {
                    print("\nAutorizado!\n");
                    pausa();
                    limpatela();
                    //ADMINISTRADOR//
                    if(u.tipocad == 1)
                    {
                        do
                        {
                            print("********************************************\n\n****** SEJA BEM VINDO AO PAINEL DE ADMINISTRADOR ******\n\n********************************************\n\n");

                            print("1) - JOGAR\n\n2) - CADASTRAR NOVO ADMINISTRADOR\n\n3) - ALTERAR DADOS DE UM USU�RIO\n\n");
                            print("4) - EXCLUIR UM USU�RIO\n\n5) - RELATORIO DE USUARIOS CADASTRADOS NO SISTEMA\n\n6) - RELATORIO DE LOGIN DE ADMINISTRADORES\n\n0) - SAIR DO PAINEL\n\n");

                            opcao = entradaint("DIGITE A OP��O DESEJADA: ");

                            getchar();
                            switch (opcao)
                            {
                            case 1 : // ACESSA MENU DE JOGOS
                                menudejogos();
                                break;
                            case 2 : // CADASTRAR NOVO LOGIN ADMIN
                                CadastroAdmin(arquivo);
                                break;
                            case 3 : // ALTERAR USU�RIO
                                alteracao(arquivo);
                                break;
                            case 4:// EXCLUIR USU�RIO
                                exclusao(arquivo);
                            case 5 : // RELATORIO DE USUARIOS CADASTRADOS
                                relatorio(arquivo);
                                getchar();
                                break;
                            case 6 : // RELATORIO DE LOGIN
                                print("\tRELATORIO DE LOGIN\n");
                                relatoriologin(arquivo);
                                getchar();
                                break;
                            case 0 : // Sair
                                print("\tPainel Fechado!");
                                exit(1);
                                break;
                            default :
                                print("Op��o Invalida!");
                                break;
                            }
                        }
                        while(opcao != 0);
                    }
                    else if(u.tipocad == 2)
                    {
                        do
                        {
                            print("*************************************************\n\n****** SEJA BEM VINDO AO PAINEL DO USU�RIO ******\n\n*************************************************\n\n");

                            print("1 - JOGAR\n2 - ALTERAR CADASTRO\n3 - SAIR DO SISTEMA\n\n");
                            opcao = entradaint("DIGITE A OP��O DESEJADA: ");

                            switch (opcao)

                            {
                            case 1 : // ACESSA JOGOS
                                menudejogos();
                                break;
                            case 2 : // ALTERAR DADOS
                                alteracaousuario(arquivo);
                                break;
                            case 3 : // Sair
                                print("\tPainel Fechado!");
                                exit(1);
                                break;
                            default :
                                print("Op��o Invalida!");
                                break;
                            }
                            getchar();
                        }
                        while(opcao != 2);
                    }
                    //USU�RIO//
                    else if(u.tipocad==2)
                    {
                        print("======================== \nUSU�RIO \n========================");
                    }
                }
                //FINALIZA��O//
                else if(strcmp(email_i,u.email) != 0 && strcmp( senha_i, u.senha) != 0)
                {
                    //print("\nEmail ou senha incorretos, tente novamente!\n");
                    log=2;
                }
            }
        }
        fclose(f);
    }
    while (log == 2);

    op = entradaint("\n Deseja voltar para a p�gina principal? \n1- Sim \n2- N�o\n");
}

void relatorio(char arq[]) // relatorio de usuarios
{
    USUARIO u;
    FILE* arquivo;
    arquivo = fopen (arq,"rb");
    int quantidade = 1;
    if(arquivo==NULL)
    {
        print("Erro na leitura do arquivo\n");
    }
    else
    {
        while( fread(&u, sizeof(USUARIO), 1, arquivo) == 1)
        {
            u.ncadastro = quantidade;
            printf("----------------N� de Cadastro do Usu�rio: %d -------------------------", u.ncadastro);
            saidastr("\nNome: ", u.nome);
            saidastr("\nEmail:  ", u.email);
            saidastr("\nSenha:  ", u.senha);
            saidastr("\nCPF:  ", u.CPF);
            print("\n---------------------------------------------------------------------\n\n");
            quantidade ++;
        }
    }
    fclose(arquivo);
}

void alteracao(char arq[]) //altera��o de usuarios via administradores
{
    USUARIO u;
    FILE* arquivo;
    arquivo = fopen (arq,"rb+");
    int quantidade = 1;
    int ncadastroaux;
    if(arquivo==NULL)
    {
        printf("Erro na leitura do arquivo\n");
    }
    else
    {
        while(fread(&u, sizeof(USUARIO), 1, arquivo))
        {
            quantidade++;
        }
        ncadastroaux = entradaint("Digite seu n�mero de cadastro");
        ncadastroaux--;
        if(ncadastroaux >= 0 && ncadastroaux < quantidade -1 )
        {
            fflush(stdin);
            strcpy(u.nome, entradastr("Digite o novo nome: "));
            fflush(stdin);
            do
            {
                fflush(stdin);
                strcpy(u.email, entradastr("\nDigite o email: "));

            }
            while(email_f(u.email)==0);
            do
            {
                fflush(stdin);
                strcpy(u.senha, entradastr("\nDigite o senha: "));
            }
            while (senha_f(u.senha)==0);

            do
            {
                fflush(stdin);
                strcpy(u.CPF, entradastr("\nDigite o cpf: "));
            }
            while (cpf_f(u.CPF)==0);

            fseek(arquivo, ncadastroaux * sizeof(USUARIO), SEEK_SET);
            fwrite(&u, sizeof(USUARIO), 1, arquivo);
        }

    }
    fclose(arquivo);
}

void exclusao(char arq[]) //exclui usuarios
{
    USUARIO u;
    FILE* arquivo;
    arquivo = fopen (arq,"rb+");
    int quantidade = 1;
    int ncadastroaux;
    if(arquivo==NULL)
    {
        printf("Erro na leitura do arquivo\n");
    }
    else
    {
        while(fread(&u, sizeof(USUARIO), 1, arquivo))
        {
            quantidade++;
        }
        ncadastroaux = entradaint("Digite o n�mero de cadastro que deseja excluir: ");
        ncadastroaux--;
        if(ncadastroaux >= 0 && ncadastroaux < quantidade -1 )
        {
            fflush(stdin);
            strcpy(u.nome, "excluido");
            strcpy(u.email, "excluido");
            strcpy(u.senha, "excluido");
            strcpy(u.CPF, "excluido");
            print("Usu�rio exclu�do com sucesso!\n");
            fseek(arquivo, ncadastroaux * sizeof(USUARIO), SEEK_SET);
            fwrite(&u, sizeof(USUARIO), 1, arquivo);
        }

    }
    fclose(arquivo);
}

void alteracaousuario(char arq[]) // altera��o via usuario
{
    USUARIO u;
    FILE* arquivo;
    arquivo = fopen (arq,"rb+");
    int quantidade = 1;
    int ncadastroaux;
    if(arquivo==NULL)
    {
        printf("Erro na leitura do arquivo\n");
    }
    else
    {
        while(fread(&u, sizeof(USUARIO), 1, arquivo))
        {
            quantidade++;
        }
        ncadastroaux = entradaint("Digite seu n�mero de cadastro");
        ncadastroaux--;
        if(ncadastroaux >= 0 && ncadastroaux < quantidade -1 )
        {
            fflush(stdin);
            strcpy(u.nome, entradastr("Digite o novo nome: "));
            fflush(stdin);

            do
            {
                fflush(stdin);
                strcpy(u.senha, entradastr("\nDigite a nova senha: "));
            }
            while (senha_f(u.senha)==0);

            fseek(arquivo, ncadastroaux * sizeof(USUARIO), SEEK_SET);
            fwrite(&u, sizeof(USUARIO), 1, arquivo);
        }

    }
    fclose(arquivo);
}

void CadastroAdmin(char arq[]) //cadastra administradores no sistema
{
    USUARIO u;
    int quantidade = 1;

    FILE *f = fopen(arq, "ab+");

    while(fread(&u, sizeof(USUARIO), 1, f))
    {
        quantidade++;
    }
    u.ncadastro = quantidade;

    fflush(stdin);
    strcpy(u.nome, entradastr("\nDigite o nome: "));

    do
    {
        fflush(stdin);
        strcpy(u.CPF, entradastr("\nDigite o cpf: "));

    }
    while (cpf_f(u.CPF)==0);

    do
    {
        fflush(stdin);
        strcpy(u.email, entradastr("\nDigite o email: "));

    }
    while(email_f(u.email)==0);

    do
    {
        fflush(stdin);
        strcpy(u.senha, entradastr("\nDigite o senha: "));
    }
    while (senha_f(u.senha)==0);
    printf("Seu n�mero de cadastro � %d\n", u.ncadastro);
    u.tipocad = 1;
    quantidade++;

    print("\n----------------------------\nCadastro admin feito com sucesso\n----------------------------\n");

    fwrite(&u, sizeof(USUARIO), 1, f);

    fclose(f);
}

int cpf_f(char cpf[15])//verifica CPF
{
    char dig_char, dig2_char;
    int dig, dig2, test=0;

    if(cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')
    {

        dig = ((((cpf[0]- '0') * 1) + ((cpf[1]- '0') * 2) + ((cpf[2]- '0') * 3) + ((cpf[4]- '0') * 4) + ((cpf[5]- '0') * 5) + ((cpf[6]- '0') * 6) + ((cpf[8]- '0') * 7) + ((cpf[9]- '0') * 8) + ((cpf[10]- '0') * 9)) % 11);

    }

    dig_char=dig+'0';

    if(dig_char==cpf[12])
    {
        dig2 = ((((cpf[0]- '0') * 9) + ((cpf[1]- '0') * 8) + ((cpf[2]- '0') * 7) + ((cpf[4]- '0') * 6) + ((cpf[5]- '0') * 5) + ((cpf[6]- '0') * 4) + ((cpf[8]- '0') * 3) + ((cpf[9]- '0') * 2) + ((cpf[10]- '0') * 1) + ((cpf[12]- '0') * 0)) % 11);


        dig2_char=dig2+'0';

        if(cpf[13]==dig2_char)
        {
            test=1;
        }
    }
    else
    {
        printf("\nO valor digitado n�o corresponde as regras do Cadastro F�sico de Pessoas \nTente novamente...\n");
        test=0;

    }
    return (test);
}

int email_f (char email[50]) // verifica email
{
    int arroba = 0, antesPonto = 0, depoisPonto = 0, i, test_email = 0;
    for (i = 0; email[i]; i++)
    {
        char c = email[i];
        if(c == '@')
        {
            if (i > 3)
            {
                //printf("\n2\n");
                arroba=1;

            }
            else
            {
                break;
            }

        }
        if(c=='.')
        {
            if(email[i+1] != '\0' && email[i+2] != '\0'/* && email[i+3] != '\0'*/)
            {
                depoisPonto = 1;
            }
            if(email[i-1] != '@' && email[i-2] != '@' && email[i-3] != '@')
            {
                antesPonto = 1;
            }
            else
            {
                break;
            }
        }
    }

    if(arroba == 1 && depoisPonto == 1 && antesPonto == 1)
    {
        test_email = 1;
    }
    else
    {
        printf("\nErro ao tentar cadastrar email \nTente novamente seguindo os passos sugeridos...\n");
        printf("\nO cadastro deve haver: \n1-Ao menos tres caracteres antes do '@'. \n2-Ao menos tres caracteres antes e dois caracteres depois do ponto.");
        test_email = 0;
    }
    return (test_email);
}

int senha_f(char senha[100]) // verifica senha
{
    char senha_i[100];
    int total=0, total2=0, total3=0, cont, cont2, cont3, test_senha=0;

    for(cont=0; senha[cont]; cont++)
    {
        if((senha[cont]>='0') && (senha[cont]<='9'))         //contar +1 para n�meros de 0 a 9
        {
            total++;

        }
    }
    for(cont2=0; senha[cont2]; cont2++)
    {
        if((senha[cont2]>='a') && (senha[cont2]<='z'))     //contar +1 para n�meros de a at� z
        {
            total2 ++;
        }
    }
    for(cont3=0; senha[cont3]; cont3++)
    {
        if((senha[cont3]>='A') && (senha[cont3]<='Z'))     //contar +1 para n�meros de a at� z
        {
            total3 ++;
        }
    }

    if(total==0 || total2==0 || total3==0)
    {
        printf("\nSenha n�o atende os requisitos estipulados(Obs: coloque uma Letra maiscula e um n�mero no min�mo!)\n");
        test_senha=0;
    }
    else
    {
        do
        {
            fflush(stdin);
            strcpy(senha_i, entradastr("\nConfirme a Senha: "));

            if(strcmp(senha, senha_i)!=0)
            {
                printf("\nAs senhas n�o s�o id�nticas!\n");
                test_senha=0;
            }
            else if (strcmp(senha, senha_i)!=1)
            {
                printf("\nSenha confirmada!\n");
                /*ARQUIVAR SENHA*/
                test_senha=1;
            }
        }
        while(strcmp(senha, senha_i)!=0);
    }
    return (test_senha);

}

void relatoriologin(char arq[]) //relatorio de login de adminstradores
{
    USUARIO u;
    FILE* arquivo;
    arquivo = fopen (arq,"rb");
    if(arquivo==NULL)
    {
        printf("Erro na leitura do arquivo\n");
    }
    else
    {
        while( fread(&u, sizeof(USUARIO), 1, arquivo) == 1)
        {
            if(u.tipocad == 1)
            {
                saidastr("\nNome: ", u.nome);
                saidastr("\nEmail:  ", u.email);
            }

        }
    }
    fclose(arquivo);
}

void menudejogos()
{
    limpatela();
    int escolha;
    do
    {
        escolha = entradaint("Escolha um jogo:\n1 - Forca\n2 - Jogo da Velha\n3 - RPG\n4 - Snake\n5 - PacMan\n6 - Sair!\n");
        switch(escolha)
        {
        case 1:
            jogoforca();
            break;
        case 2:
            jogovelha();
            break;
        case 3:
            JogoRpg();
            break;
        case 4:
            system("cls");
            jogosnake();
            break;
        case 5:
            jogopacman();
            break;
        case 6:
            print("Menu de jogos encerrado!\n");
            exit(1);
            break;
        default:
            print("Erro!Op��o invalida");
            exit(1);
            break;
        }
    }
    while(escolha != 6);
}

void chamamenu()
{
    char arquivo[] = {"usuarios.text"};
    inicializarlocal();
    int possui_cad;
    do
    {
        print("*************************************************\n\n******** SEJA BEM VINDO AO MENU DE JOGOS ********\n\n*************************************************\n\n");
        possui_cad =entradaint("\n\t\t POSSUI CADASTRO?\n\t\n1 - SIM\n\t\n2 - N�O\n\n\t CASO QUEIRA SAIR DIGITE 0\n*************************************************\n\n");
        switch(possui_cad)
        {
        case 1:
            login(arquivo);
            break;
        case 2:
            cadastro(arquivo);
            break;
        case 0:
            print("\tMENU DE JOGOS ENCERRADO!");
            exit(1);
        default :
            print("Opcao Invalida!");
            break;
        }
    }
    while(op != 2);
}
