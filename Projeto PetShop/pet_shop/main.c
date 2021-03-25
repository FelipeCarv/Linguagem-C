#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "avl.h"

/// ------------------------- OPCOES ---------------------------|
#define TITULO_OPCAO1 "LISTAR OS DADOS DOS ANIMAIS"        ///|
    #define TITULO_SUBOPCAO1 "IMPRIMIR NA TELA"              ///|
    #define TITULO_SUBOPCAO2 "SALVAR DADOS EM ARQUIVOS"      ///|
    #define TITULO_SUBOPCAO3 "VOLTAR AO MENU PRINCIPAL"      ///|
                                                             ///|
#define TITULO_OPCAO2 "CADASTRAR NOVO ANIMAL"              ///|
    #define TITULO_SUBOPCAOCASE2_1 "CADASTRAR ANIMAL"      ///|
    #define TITULO_SUBOPCAOCASE2_2 "VOLTAR AO MENU PRINCIPAL"///|
                                                             ///|
#define TITULO_OPCAO3 "REALIZAR CONSULTA"                    ///|
                                                             ///|
#define TITULO_OPCAO4 "SAIR "                                ///|
                                                             ///|
#define OPCAO1  1                                            ///|
    #define SUBOPCAO1  1                                     ///|
    #define SUBOPCAO2  2                                     ///|
    #define SUBOPCAO3  3                                     ///|
                                                             ///|
#define OPCAO2  2                                            ///|
    #define SUBOPCAOCASE2_1 1                                ///|
    #define SUBOPCAOCASE2_2 2                                ///|
                                                             ///|
#define OPCAO3  3                                            ///|
                                                             ///|
#define OPCAO4  4                                            ///|
                                                             ///|
#define N_OPCOES 4                                           ///|
#define N_SUBOPCOES 3                                        ///|
#define N_SUBOPCOESCASE2 2                                   ///|
///-------------------------------------------------------------|

int main(void){

    int op, subop;
    char nome[121], raca[121], procedimento[121], sexo; float horario; int idade;
///----------------------- CRIAÇÃO E CARREGAMENTO DA ARVORE ---------------------------------
    Arv* arvore = arv_cria();
    carrega_dados(arvore);
///------------------------------------------------------------------------------------------

   do{
        system("cls");
        printf(" _-_-_-_-_-_-_-_-_-_MENU PRINCIPAL_-_-_-_-_-_-_-_-_-_\n");
        printf("|                                                    |\n");
        ApresentaMenu(N_OPCOES, OPCAO1, TITULO_OPCAO1, TITULO_OPCAO2, TITULO_OPCAO3, TITULO_OPCAO4);
        printf("|____________________________________________________|\n");

        op = LeOpcao(OPCAO1,N_OPCOES);

       switch (op){
        case 1:
            do{
                    system("cls");
                    printf("_-_-_-_-_-_-_-_-_-_%s_-_-_-_-_-_-_-_-_-_\n",TITULO_OPCAO1);
                    printf("|                                                                  |\n");
                    ApresentaMenu(N_SUBOPCOES, SUBOPCAO1, TITULO_SUBOPCAO1, TITULO_SUBOPCAO2, TITULO_SUBOPCAO3);
                    printf("|__________________________________________________________________|\n");
                    subop = LeOpcao(SUBOPCAO1,SUBOPCAO3);

                    switch (subop){
                        case 1:
                            system("cls");
                            printf("%s >> %s\n\n",TITULO_OPCAO1,TITULO_SUBOPCAO1);
                            arv_imprime(arvore);
                            system("Pause");
                            break;
                        case 2:
                            arv_imprime_saida(arvore);
                            printf("DADOS DOS ANIMAIS SALVOS NO ARQUIVO\n.");
                            system("Pause");
                            break;
                        case 3:
                            subop = -1;
                            break;
                        default:
                            printf("OPCAO INVALIDA.\nTENTE NOVAMENTE.");
                            break;
                    }

                }while((subop >= 1) && (subop <=3));
            break;
        case 2:

            do{
            system("cls");
                printf("_-_-_-_-_-_-_-_-_-_%s_-_-_-_-_-_-_-_-_-_\n",TITULO_OPCAO2);
                printf("|                                                            |\n");
                ApresentaMenu(N_SUBOPCOESCASE2, SUBOPCAOCASE2_1, TITULO_SUBOPCAOCASE2_1, TITULO_SUBOPCAOCASE2_2);
                printf("|____________________________________________________________|\n");
                subop = LeOpcao(SUBOPCAOCASE2_1,SUBOPCAOCASE2_2);

            switch (subop){
                case 1:

                    system("cls");
                    printf("%s >> %s\n",TITULO_OPCAO2,TITULO_SUBOPCAOCASE2_1);
                    printf("\nDIGITE NOME DO ANIMAL: ");
                    strcpy(nome, camelcase(LeString()));

                    printf("\nDIGITE A RACA DO ANIMAL: ");
                    strcpy(raca, camelcase(LeString()));

                    printf("\nINFORME IDADE DO ANIMAL: ");
                    idade = LeInteiro();

                    printf("\nINFORME SEXO DO ANIMAL: ");
                    sexo = ValidSexo();

                    printf("\nDIGITE O PROCEDIMENTO: ");
                    strcpy(procedimento, camelcase(LeString()));

                    printf("\nDIGITE O HORARIO: ");
                    horario = LeFloat();

                    arv_insere(arvore,arvno_cria(animal_cria(nome, sexo,idade, horario, procedimento, raca)));

                    printf("\nCADASTRO EFETUADO COM SUCESSO.\n\n");
                    system("Pause");
                    //system("Pause");


                    system("cls");
                    break;

                case 2:
                    system("cls");
                    subop = -2;
                    break;
                default:

                    printf("OPCAO INVALIDA.\n");
                    break;

                    }


                }while((subop >= 1) && (subop <=3));
        break;

        case 3:
            system("cls");
                printf("_-_-_-_-_-_-_-_-_-_%s_-_-_-_-_-_-_-_-_-_\n", TITULO_OPCAO3);
                printf("\nDIGITE O NOME DO ANIMAL: ");scanf("%120[^\n]", nome);
                consulta(arv_busca(arvore,camelcase(nome)));
                system("Pause");
            break;
        case 4:
            system("cls");
            arv_libera(arvore);
            printf("\n\nPROGRAMA FINALIZADO!\n\n");
            break;
        default:
            printf("OPCAO INVALIDA.\n");
            break;
       }

    }while(op != OPCAO4);
    return 0;
}
