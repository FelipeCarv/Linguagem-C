#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interacao.h"
#include "animais.h"
#include "relatorio.h"


#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'


#define TITULO_OPCAO1 "CADASTRAR ANIMAL"
#define TITULO_OPCAO2 "MOSTRAR ANIMAIS DISPONIVEIS"
#define TITULO_OPCAO3 "ADOTAR UM ANIMAL"
#define TITULO_OPCAO4 "RELATORIO DE ADOCAO DE ANIMAIS"
#define TITULO_OPCAO5 "SAIR DO PROGRAMA"


#define N_OPCOES 5

int main(void)
{
    //VARIÁVEIS DE INTERAÇÃO DO MENU
    int interacao = 1;
    int op;

    //ARQUIVOS ABERTURA MODO LEITURA
    FILE* animais;
    animais = fopen("animais.txt", "r");
    if(animais == NULL)
    {
        printf("\n\nERRO NA ABERTURA DO ARQUIVO\n\n");
        exit(1);
    }

    FILE* relatorio;
    relatorio = fopen("relatorio.txt", "r");
    if(relatorio == NULL)
    {
        printf("\n\nERRO NA ABERTURA DO ARQUIVO\n\n");
        exit(1);
    }

    //VARIÁVEIS DE INTERAÇÃO RELATÓRIO
    char nome[80];
    char telefone[30];
    char endereco[100];
    char nome_animal[50];
    Relatorio* lista_Relatorio = list_RelatorioCria();
    lista_Relatorio = list_RelatorioCarrega(relatorio);

    //VARIÁVEIS DE INTERAÇÃO ANIMAIS
    char nomeAnimal[50];
    char tipo[50];
    char raca[50];
    char genero[50];
    Animal* lista_Animais = list_AnimalCria();
    lista_Animais = list_AnimalCarrega(animais);


    while(interacao)
    {
        apresenta_programa("========SEJA BEM VINDO A PROJETO BENEVOLENCIA========");//'MENSAGEM' APRESENTACAO DO PROGRAMA
        apresenta_menu(N_OPCOES, OPCAO1,TITULO_OPCAO1, TITULO_OPCAO2,TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5); //APRESENTA O 'MENU'
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1); //LÊ OPCAO DIGITADA

        switch(op)
        {

            //OPCAO 1 CADASTRAR ANIMAL
            case OPCAO1:

                        limpa_tela();
                        printf("\n DIGITE O NOME (apelido): ");
                        strcpy(nomeAnimal, le_string());
                        printf("\n DIGITE O TIPO DO ANIMAL (Ex:. Cachorro, Gato ...): ");
                        strcpy(tipo, le_string());
                        printf("\n DIGITE A RACA: ");
                        strcpy(raca, le_string());
                        printf("\n DIGITE O GENERO: ");
                        strcpy(genero, le_string());
                        lista_Animais = list_AnimalInsere(lista_Animais, nomeAnimal, tipo, raca, genero);
                        printf("\n --- %s CADASTRADO --- \n\n\n", nomeAnimal);
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 2 MOSTRAR ANIMAIS DISPONIVEIS
            case OPCAO2:
                        limpa_tela();
                        list_AnimalImprime(lista_Animais);
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 3 ADOTAR UM ANIMAL
            case OPCAO3:
                        limpa_tela();
                        printf("\n DIGITE O NOME DA PESSOA: ");
                        strcpy(nome, le_string());
                        printf("\n DIGITE O TELEFONE: ");
                        strcpy(telefone, le_string());
                        printf("\n DIGITE O ENDERECO (Ex:. Rua/Bairro - Numero da casa): ");
                        strcpy(endereco, le_string());
                        printf("\n DIGITE O NOME DO ANIMAL AO QUAL DESEJA ADOTAR: ");
                        strcpy(nome_animal, le_string());
                        if(list_AnimalBusca(lista_Animais, nome_animal))
                        {
                            lista_Animais = list_AnimalRemove(lista_Animais, nome_animal);
                            printf("\n --- %s ADOTADO POR %s --- \n\n\n", nome_animal, nome);
                            lista_Relatorio = list_RelatorioInsere(lista_Relatorio, nome, telefone, endereco, nome_animal);
                        }
                        else
                        {
                            printf("\n --- %s NAO E UM NOME DE UM ANIMAL CADASTRADO PARA ADOCAO --- \n\n\n", nome_animal);
                        }
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 4 RELATORIO DE ADOCAO DE ANIMAIS
            case OPCAO4:
                        limpa_tela();
                        list_RelatorioImprime(lista_Relatorio);
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 5 SAIR DO PROGRAMA
            case OPCAO5:

                        limpa_tela();
                        mensagem_despedida("\n\n---OBRIGADO E ATE LOGO!---\n\n");//'MENSAGEM' DESPEDIDA DO PROGRAMA
                        interacao = 0;
                        break;

            default:

                    printf("ESTE PROGRAMA POSSUI UM BUG.");//ERRO NO PROGRAMA
                    return 1;
        }
    }

    //ARQUIVOS ABERTURA MODO ESCRITA
    relatorio = fopen("relatorio.txt", "w");
    if(relatorio == NULL)
    {
        printf("\n\nERRO NA ABERTURA DO ARQUIVO\n\n");
        exit(1);
    }
    list_RelatorioSalva(relatorio, lista_Relatorio);

    animais = fopen("animais.txt", "w");
    if(animais == NULL)
    {
        printf("\n\nERRO NA ABERTURA DO ARQUIVO\n\n");
        exit(1);
    }
    list_AnimalSalva(animais, lista_Animais);

    //FECHAMENTO DE ARQUIVOS
    fclose(relatorio);
    fclose(animais);

    //LIBERANDO MEMORIA
    list_AnimalLibera(lista_Animais);
    list_RelatorioLibera(lista_Relatorio);


    return 0;
}

