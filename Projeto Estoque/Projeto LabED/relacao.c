#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relacao.h"

struct relacao{// LISTA DO TIPO RELA플O
    char nome[50];
    char data[20];
    char nome_produto[50];
    struct relacao* prox;
};

Relacao* relacao_cria(void){// FUN플O PARA CRIAR A RELA플O
    return NULL;
}
//INSERINDO INFORMA합ES NA ESTRUTURA RELA플O
Relacao* relacao_insere(Relacao* p, char* nome, char* data, char* produto){
    Relacao* novo = (Relacao*)malloc(sizeof(Relacao));

    strcpy(novo->nome, nome);
    strcpy(novo->data, data);
    strcpy(novo->nome_produto, produto);

    Relacao* ant = NULL;
    Relacao* aux = p;

    while(aux != NULL && strcmp(aux->nome, nome) < 0){
            ant = aux;
            aux = aux->prox;
    }

    if(ant == NULL){
        novo->prox = p;
        p = novo;
    }
       else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return p;
}

int relacao_vazia(Relacao* p){// VERIFICA SE A RELA플O EST� VAZIA
    return(p==NULL);
}
// IMPRIMINDO A RELA플O
void relacao_imprime(Relacao* p){
    if(relacao_vazia(p)){
        printf("\n-X-X-X-X-X-O SISTEMA ESTA SEM CADASTROS-X-X-X-X-X-.");
    } else{
        Relacao* aux;
        printf("-X-X-X-X-X-X-X-X-X-X-RELACAO DE PRODUTOS-X-X-X-X-X-X-X-X-X-X-\n\n");
            for(aux = p; aux != NULL; aux = aux->prox){
                    printf("NOME: %s\nDATA: %s\nPRODUTO: %s\n\n", aux->nome, aux->data, aux->nome_produto);
            }
    }
}
// CARREGANDO EM UMA ARQUIVO OS DADOS DA LISTA RELA플O
Relacao* relacao_carrega(FILE* relacao){
    char nome[50];
    char data[20];
    char nome_produto[50];

    Relacao* p = relacao_cria();

    while(fscanf(relacao,"\n%49[^\n] %19[^\n] %49[^\n]", nome, data, nome_produto)!= EOF){
        Relacao* novo = (Relacao*)malloc(sizeof(Relacao));
        strcpy(novo->nome, nome);
        strcpy(novo->data, data);
        strcpy(novo->nome_produto, nome_produto);

        Relacao* ant = NULL;
        Relacao* aux = p;

          while(aux != NULL && strcmp(aux->nome, nome) < 0){
                ant = aux;
                aux = ant->prox;
          }

          if(ant == NULL){
            novo->prox = p;
            p = novo;

          } else{
            novo->prox = ant->prox;
            ant->prox = novo;
          }
    }
    return p;
}
//SALVANDO OS DADOS EM ARQUIVO
Relacao* relacao_salva(FILE* relacao, Relacao* p){
    char nome[50];
    char data[20];
    char nome_produto[50];

    Relacao* aux = p;

    while(aux!=NULL){
        strcpy(nome, aux->nome);
        strcpy(data, aux->data);
        strcpy(nome_produto, aux->nome_produto);

        fprintf(relacao,"%s\n%s\n%s\n", nome, data, nome_produto);
        aux = aux->prox;
    }
}

// LIBERANDO A LISTA RELA플O
void relacao_libera(Relacao* p){
    Relacao* r = p;

    while(r!=NULL){
        Relacao* aux = p->prox;
        free(r);
        r = aux;
    }
}
