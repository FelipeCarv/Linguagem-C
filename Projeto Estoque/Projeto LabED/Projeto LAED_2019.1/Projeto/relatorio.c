#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"

    struct relatorio
    {
        char nome[80];
        char telefone[30];
        char endereco[100];
        char nome_animal[50];
        struct relatorio* prox;
    };

    Relatorio* list_RelatorioCria(void)
    {
        return NULL;
    }

    Relatorio* list_RelatorioInsere(Relatorio* lr, char* nome, char* t, char* endereco, char* animal)
    {
        Relatorio* novo = (Relatorio*) malloc (sizeof(Relatorio));
        strcpy(novo->nome, nome);
        strcpy(novo->telefone, t);
        strcpy(novo->endereco, endereco);
        strcpy(novo->nome_animal, animal);

        Relatorio* ant = NULL;
        Relatorio* aux = lr;

        //PROCURA A POSIÇÃO DE INSERÇÃO
        while(aux != NULL && strcmp(aux->nome, nome) < 0)
        {
            ant = aux;
            aux = aux->prox;
        }

        //INSERE O ELEMENTO
        if(ant == NULL) //INSERE O ELEMENTO NO INÍCIO
        {
            novo->prox = lr;
            lr = novo;
        }
        else //INSERE O ELEMENTO NO MEIO DA LISTA
        {
            novo->prox = ant->prox;
            ant->prox = novo;
        }

        return lr;
    }

    int list_RelatorioVazia(Relatorio* lr)
    {
        return (lr == NULL);
    }

    void list_RelatorioImprime(Relatorio* lr)
    {
        if(list_RelatorioVazia(lr))
        {
            printf("\n\n---LISTA DE RELATORIO DE ADOCAO DE ANIMAIS VAZIA---\n\n\n");
        }
        else
        {
            Relatorio* aux;
            printf("------------RELATORIO DE ADOCOES DE ANIMAIS------------\n\n");
            for(aux = lr; aux != NULL; aux = aux->prox)
            {
                printf("NOME: %s\nTELEFONE: %s\nENDERECO: %s\nNOME DO ANIMAL: %s\n\n", aux->nome, aux->telefone, aux->endereco, aux->nome_animal);
            }
        }
    }

    Relatorio* list_RelatorioCarrega(FILE* relatorio)
    {
        char nome[80];
        char telefone[30];
        char endereco[100];
        char nome_animal[50];

        Relatorio* lr = list_RelatorioCria();

        while(fscanf(relatorio, "\t%79[^\n] %29[^\n] %99[^\n] %49[^\n]", nome, telefone, endereco, nome_animal) != EOF)
        {
            Relatorio* novo = (Relatorio*) malloc (sizeof(Relatorio));
            strcpy(novo->nome, nome);
            strcpy(novo->telefone, telefone);
            strcpy(novo->endereco, endereco);
            strcpy(novo->nome_animal, nome_animal);

            Relatorio* ant = NULL;
            Relatorio* aux = lr;

            //PROCURA A POSIÇÃO DE INSERÇÃO
            while(aux != NULL && strcmp(aux->nome, nome) < 0)
            {
                ant = aux;
                aux = ant->prox;
            }

            //INSERE O ELEMENTO
            if(ant == NULL) //INSERE O ELEMENTO NO INÍCIO
            {
                novo->prox = lr;
                lr = novo;
            }
            else //INSERE O ELEMENTO NO MEIO DA LISTA
            {
                novo->prox = ant->prox;
                ant->prox = novo;
            }
        }

        return lr;
    }

    void list_RelatorioSalva(FILE* relatorio, Relatorio* lr)
    {
        char nome[80];
        char telefone[30];
        char endereco[100];
        char nome_animal[50];

        Relatorio* aux = lr;
        while(aux != NULL)
        {
            strcpy(nome, aux->nome);
            strcpy(telefone, aux->telefone);
            strcpy(endereco, aux->endereco);
            strcpy(nome_animal, aux->nome_animal);
            //COPIANDO PARA O ARQUIVO 'RELATORIO'
            fprintf(relatorio,"%s\t%s\t%s\t%s\t", nome, telefone, endereco, nome_animal);
            aux = aux->prox;
        }
    }

    void list_RelatorioLibera(Relatorio* lr)
    {
        Relatorio* r = lr;
        while(r != NULL)
        {
            Relatorio* aux = r->prox;
            free(r);
            r = aux;
        }
    }
