#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animais.h"

    struct animal
    {
        char nome[50];
        char tipo[50];
        char raca[50];
        char genero[50];
        struct animal* prox;
    };

    Animal* list_AnimalCria(void)
    {
        return NULL;
    }

    Animal* list_AnimalInsere(Animal* la, char* nome, char* tipo, char* raca, char* genero)
    {
        Animal* novo = (Animal*) malloc (sizeof(Animal));
        strcpy(novo->nome, nome);
        strcpy(novo->tipo, tipo);
        strcpy(novo->raca, raca);
        strcpy(novo->genero, genero);

        Animal* ant = NULL;
        Animal* aux = la;

        //PROCURA A POSIÇÃO DE INSERÇÃO
        while(aux != NULL && strcmp(aux->nome, nome) < 0)
        {
            ant = aux;
            aux = aux->prox;
        }

        //INSERE O ELEMENTO
        if(ant == NULL) //INSERE O ELEMENTO NO INÍCIO
        {
            novo->prox = la;
            la = novo;
        }
        else //INSERE O ELEMENTO NO MEIO DA LISTA
        {
            novo->prox = ant->prox;
            ant->prox = novo;
        }

        return la;
    }

    Animal* list_AnimalRemove(Animal* la, char* nome)
    {
        Animal* ant = NULL;
        Animal* p = la;

        while(p != NULL && strcmp(p->nome, nome) != 0 )
        {
            ant = p;
            p = p->prox;
        }
        if(p == NULL)
        {
            printf("\n\n---ANIMAL NAO ENCONTRADO---\n\n\n");
                return la; //NÃO ACHOU
        }
        if(ant == NULL)
        {
            la = p->prox;
        }
        else
        {
            ant->prox = p->prox;
        }
        free(p);
        return la;
    }

    int list_AnimalVazia(Animal* la)
    {
        return (la == NULL);
    }

    int list_AnimalBusca(Animal* la, char* nome)
    {
        Animal* aux;
        for(aux = la; aux != NULL; aux = aux->prox)
        {
            if(strcmp(aux->nome, nome)== 0)
                return 1;
        }
        return 0; //NÃO ACHOU O NOME
    }

    void list_AnimalImprime(Animal* la)
    {
        if(list_AnimalVazia(la))
        {
            printf("\n\n---LISTA DE ANIMAIS PARA ADOCAO VAZIA---\n\n\n");
        }
        else
        {
            Animal* aux;
            printf("------------ANIMAIS------------\n\n");
            for(aux = la; aux != NULL; aux = aux->prox)
            {
                printf("NOME: %s\nTIPO: %s\nRACA: %s\nGENERO: %s\n\n", aux->nome, aux->tipo, aux->raca, aux->genero);
            }
        }
    }

    Animal* list_AnimalCarrega(FILE* animais)
    {
        char nome[50];
        char tipo[50];
        char raca[50];
        char genero[50];

        Animal* la = list_AnimalCria();

        while(fscanf(animais, "\n%49[^\n] %49[^\n] %49[^\n] %49[^\n]", nome, tipo, raca, genero) != EOF)
        {
            Animal* novo = (Animal*) malloc (sizeof(Animal));
            strcpy(novo->nome, nome);
            strcpy(novo->tipo, tipo);
            strcpy(novo->raca, raca);
            strcpy(novo->genero, genero);

            Animal* ant = NULL;
            Animal* aux = la;

            //PROCURA A POSIÇÃO DE INSERÇÃO
            while(aux != NULL && strcmp(aux->nome, nome) < 0)
            {
                ant = aux;
                aux = ant->prox;
            }

            //INSERE O ELEMENTO
            if(ant == NULL) //INSERE O ELEMENTO NO INÍCIO
            {
                novo->prox = la;
                la = novo;
            }
            else //INSERE O ELEMENTO NO MEIO DA LISTA
            {
                novo->prox = ant->prox;
                ant->prox = novo;
            }
        }

        return la;
    }

    void list_AnimalSalva(FILE* animais, Animal* la)
    {
        char nome[50];
        char tipo[50];
        char raca[50];
        char genero[50];

        Animal* aux = la;
        while(aux != NULL)
        {
            strcpy(nome, aux->nome);
            strcpy(tipo, aux->tipo);
            strcpy(raca, aux->raca);
            strcpy(genero, aux->genero);

            //COPIANDO PARA O ARQUIVO 'RELATORIO'
            fprintf(animais,"%s\n%s\n%s\n%s\n", nome, tipo, raca, genero);
            aux = aux->prox;
        }
    }

    void list_AnimalLibera(Animal* la)
    {
        Animal* a = la;
        while(a != NULL)
        {
            Animal* aux = a->prox;
            free(a);
            a = aux;
        }
    }
