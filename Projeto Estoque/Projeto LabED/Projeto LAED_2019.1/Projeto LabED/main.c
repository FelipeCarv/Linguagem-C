#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "Lista_itens.h"
#include "controle.h"
#include "relacao.h"

#define OP1 '1'
#define OP2 '2'
#define OP3 '3'
#define OP4 '4'
#define OP5 '5'

#define TITULO_OP1 "CADASTRAR PRODUTO"
#define TITULO_OP2 "APRESENTAR PRODUTOS DISPONIVEIS"
#define TITULO_OP3 "REMOVER PRODUTO"
#define TITULO_OP4 "RELACAO DE PRODUTOS REMOVIDOS"
#define TITULO_OP5 "SAIR DO PROGRAMA"

#define NUM_OP 5

int main(){
    setlocale(LC_ALL, "portuguese");
    int interacao = 1;
    int op;
     //ABRINDO OS ARQUIVOS PRODUTO E RELACAO
    FILE* produto = fopen("produtos.txt", "rt");
        if(produto == NULL){
            printf("\nERRO NA ABERTURA DO ARQUIVO produto.");
            exit(1);
        }
    FILE* relacao = fopen("relacao.txt", "rt");
        if(relacao == NULL){
            printf("\nERRO NA ABERTURA DO ARQUIVO relacao.");
            exit(1);
        }
        //VARIAVEIS PARA MANIPULAR A RELA플O DE REMO플O
    char nome_produto[50];
    char nome[50];
    char data[20];

    Relacao* lista_relacao = relacao_cria();//CRIANDO UMA LISTA PARA A RELA플O
    lista_relacao = relacao_carrega(relacao);//CARREGANDO UMA RELA플O PARA UM ARQUIVO

        //VARIAVEIS PARA MANIPULAR O PRODUTO
    char nomeproduto[50];
    char quantidade[50];
    char preco[50];

    Produto* lista_produto = lst_cria();//CRIANDO UMA LISTA DE PRODUTOS
    lista_produto = lst_insereArq(produto);//CARREGANDO O PRODUTO PARA UM ARQUIVO

    while(interacao){
        apresentacao("==== >>>> :::: BEM VINDO AO SISTEMA DE PRODUTOS :::: <<<< ====\n");
        apresenta_menu(NUM_OP, OP1, TITULO_OP1, TITULO_OP2, TITULO_OP3, TITULO_OP4, TITULO_OP5);
            op = le_opcao(OP1, OP1 + NUM_OP - 1);

            switch(op){
            case OP1://OPERA플O 1 - INSERIR UM PRODUTO NA LISTA
                 limpa_tela();
                        printf("\n DIGITE O NOME DO PRODUTO: ");
                        strcpy(nomeproduto, le_string());
                        printf("\n DIGITE A QUANTIDADE DO PRODUTO: ");
                        strcpy(quantidade, le_string());
                        printf("\n DIGITE O PRECO: ");
                        strcpy(preco, le_string());
                        //INSERINDO O PRODUTO NA LISTA
                        lista_produto = lst_insere(lista_produto, nomeproduto, quantidade, preco);
                        printf("\n --->>> ::: %s CADASTRADO ::: <<<--- \n\n\n", nomeproduto);
                        system("pause");
                        limpa_tela();
                        break;
            case OP2: // OPERACÃO 2 - APRESENTAR PRODUTOS NA LISTA
                limpa_tela();
                    lst_imprime(lista_produto);
                    system("pause");
                    limpa_tela();
                    break;


            case OP3: // OPERA플O 3 - REMOVENDO PRODUTO DA LISTA
                limpa_tela();
                printf("\n DIGITE O NOME DA PESSOA: ");
                        strcpy(nome, le_string());
                        printf("\n DIGITE O PRODUTO: ");
                        strcpy(nome_produto, le_string());
                        printf("\n DIGITE A DATA DA REMOCAO: ");
                        strcpy(data, le_string());

                        if(lst_busca(lista_produto, nome_produto)){//BUSCAR NA LISTA SE O PRODUTO EXISTE
                            lista_produto = lst_remove(lista_produto, nome_produto);//REMOVENDO O PRODUTO DA LISTA
                            printf("\n --->>> ::: PRODUTO REMOVIDO POR %s ::: <<<---\n\n\n",nome);
                            lista_relacao = relacao_insere(lista_relacao, nome, nome_produto, data);//ATUALIZANDO A RELA플O
                        } else{
                            printf("\n\n--->>>> :::: PRODUTO INEXISTENTE :::: <<<<---\n\n");
                        }
                        system("pause");
                        limpa_tela();
                        break;

            case OP4: // OPERA플O 4 - IMPRIMINDO A RELA플O
                limpa_tela();
                relacao_imprime(lista_relacao);
                  system("pause");
                        limpa_tela();
                        break;

            case OP5: // SAINDO DO PROGRAMA
                limpa_tela();
                msgm_desp("\n\n---->>>> :::: ATE A PROXIMA :::: <<<< ----\n\n");
                interacao = 0;
                break;

                   default:

                    printf("ALGO DE ERRADO NAO ESTA CERTO.");//ERRO NO PROGRAMA
                    return 1;
            }
    }
    // ABRINDO OS ARQUIVOS PARA O MODO DE ESCRITA E SALVANDO OS DADOS
    relacao = fopen("relacao.txt", "rw");
        if(relacao == NULL){
            printf("\n\n erro na abertura do arquivo.\n\n");
            exit(1);
        }

        relacao_salva(relacao, lista_relacao);// SALVANDO

    produto = fopen("produtos.txt", "rw");
        if(produto == NULL){
            printf("\n\n erro na abertura do arquivo\n\n");
            exit(1);
        }
        lst_salvarq(produto, lista_produto); // SALVANDO

        //FECHANDO OS AQUIVOS E LIBERANDO AS LISTAS
        fclose(relacao);
        fclose(produto);

        lst_libera(lista_produto);
        relacao_libera(lista_relacao);

    return 0;
}
