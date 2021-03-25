#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Lista_itens.h"

struct produto{// ESTRUTURA PRODUTO
    char nome[40];
    char quantidade[50];
    char preco[50];
    struct produto* prox;
};

Produto* lst_cria(void){// CRIANDO UMA LISTA DE PRODUTOS
    return NULL;
}
//INSERINDO NA LISTA OS DADOS REFERENTE A UM PRODUTO
Produto* lst_insere(Produto* p, char* nome, char* quantidade, char* preco){
    Produto* prod = (Produto*) malloc(sizeof(Produto));

    strcpy(prod->nome, nome);
    strcpy(prod->quantidade, quantidade);
    strcpy(prod->preco, preco);

    Produto* anterior = NULL;
    Produto* aux = p;

    // VERIFICANDO PARA INSERIR ELEMENTOS
    while(aux != NULL && strcmp(aux->nome, nome) < 0){
            anterior = aux;
            aux = aux->prox;
        }
    if(anterior == NULL){
            prod->prox = p;
            p = prod;
        }

        else {
            prod->prox = anterior->prox;
            anterior->prox = prod;
        }

        return p;
    }

//FUNÇÃO PARA REMOVER ELEMENTOS DA LISTA
Produto* lst_remove(Produto* p, char* nome){
    Produto* ant = NULL;
    Produto* prod = p;

       while(prod != NULL && strcmp(prod->nome, nome) != 0){
            ant = prod;
            prod = prod->prox;
        }

         if(prod == NULL){
            printf("\n\n-X-X-PRODUTO NAO ENCONTRADO-X-X-\n\n\n");
                return p;
        }
    if(ant == NULL){
        p = prod->prox;
    }
    else{
        ant->prox = prod->prox;
    }
    free(prod);
    return p;
}
// VERIFICA SE A LISTA ESTÁ VAZIA
int lst_vazia(Produto* p){
    return(p == NULL);
}
//BUSCANDO UM ELEMENTO NA LISTA
int lst_busca(Produto* p, char* nome){
    Produto* aux;

    for(aux = p; aux != NULL; aux = aux->prox){
         if(strcmp(aux->nome, nome)== 0){
                return 1;
         }
    }
    return 0; //CASO N ACHE O NOME.
}
// IMPRIMINDO ELEMENTOS DA LISTA
void lst_imprime(Produto* p){
    if(lst_vazia(p)){
        printf("\n\n\n---O CONTROLE DE ITENS ESTA VAZIO---\n\n\n");
    } else{
        Produto* aux;

        printf("-X-X-X-X-X- PRODUTOS -X-X-X-X-X-\n\n\n");

        for(aux = p; aux != NULL; aux = aux->prox){
            printf("\n\nNOME: %s\nQUANTIDADE: %s\nPRECO: %s\n\n", aux->nome, aux->quantidade, aux->preco);
        }
    }
}
//CARREGANDO DADOS PARA UM ARQUIVO
Produto* lst_insereArq(FILE* prod){
    char nome[50];
    char quantidade[50];
    char preco[10];

    Produto* p1 = lst_cria();

    while(fscanf(prod,"\n%49[^\n] %49[^\n] %9[^\n]", nome, quantidade, preco)!= EOF){
        Produto* p = (Produto*)malloc(sizeof(Produto));

        strcpy(p->nome, nome);
        strcpy(p->quantidade, quantidade);
        strcpy(p->preco, preco);

        Produto* ant = NULL;
        Produto* aux = p1;

        while(aux != NULL && strcmp(aux->nome, nome) < 0){
                ant = aux;
                aux = ant->prox;
            }
        if(ant == NULL){
                p->prox = p1;
                p1 = p;
    } else{
            p->prox = ant->prox;
            ant->prox = p;
    }

   }
   return p1;
}
//SALVANDO DADOS EM UM ARQUIVO
void lst_salvarq(FILE* produtos, Produto* p){
    char nome[50];
    char quantidade[50];
    char preco[50];

    Produto* aux = p;

    while(aux != NULL){
        strcpy(nome, aux->nome);
        strcpy(quantidade, aux->quantidade);
        strcpy(preco, aux->preco);
        //fprintf(produtos, "NOME: %s\nQUANTIDADE: %s\nPRECO: %s\n", nome, quantidade, preco);
        fprintf(produtos,"NOME:%s\nQUANTIDADE:%s\nPREÇO%s\n", nome, quantidade, preco);
        aux = aux->prox;
    }
}

void lst_libera(Produto* p){// LIBERANDO A LISTA PRODUTO
    Produto* prod = p;

    while(prod != NULL){
        Produto* aux = prod->prox;
        free(prod);
        prod = aux;
    }
}
