#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avl.h"
#include "menu.h"

struct animal{
    char nome[121];
    char raca[81];
    char procedimento[121];
    char sexo;
    int idade;
    float horario;
};

struct arvno{
    Animal* info;
    int altdir, altesq;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv{
    ArvNo* raiz;
};



/**MARCOS--------------------------------------------------*/
Arv* arv_cria(void){

    Arv* novo = (Arv*)malloc(sizeof(Arv));

    if(novo == NULL){
        printf("Memoria insuficiente,\nO programa será abortado.\n");
        exit(1);
    }

    novo->raiz = NULL;
    return novo;
}

Animal* animal_cria(char* nome, char sexo, int idade, float horario, char* procedimento, char* raca){

    Animal* novo = (Animal*) malloc(sizeof(Animal));

    if(novo == NULL){
        printf("Erro de alocacao de memoria.\nO Programa será abortado.\n");
        exit(1);
    }

    strcpy(novo->nome, nome);
    novo->sexo = sexo;
    novo->idade = idade;
    novo->horario = horario;
    strcpy(novo->procedimento, procedimento);
    strcpy(novo->raca, raca);

    return novo;
}


ArvNo* arvno_cria(Animal* a){
    ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));

    if(novo == NULL){
        printf("Memoria insuficiente\n.O programa sera abortado.\n");
        exit(1);
    }

    novo->info = a;
    novo->esq = novo->dir = NULL;
    novo->altesq = novo->altdir = 0;

    return novo;
}



static ArvNo* busca(ArvNo* r, char* nome){
    if(r == NULL){
        return NULL;
    }else if(strcmp(r->info->nome, nome) > 0){
        return busca(r->esq, nome);
    }else if(strcmp(r->info->nome, nome) < 0){
        return busca(r->dir, nome);
    }else{
        return r;
    }
    return NULL;
}

ArvNo* arv_busca(Arv* a, char* nome){
    return busca(a->raiz, nome);
}













/**FELIPE--------------------------------------------------*/
static ArvNo* RotDir (ArvNo* r){
    ArvNo *aux1, *aux2;
    aux1 = r->esq;
    aux2 = r->dir;
    r->esq = aux2;
    aux1->dir = r;

    /**se a altura da esquerda for maior que a altura da direita, logo a altura da esquerda vai receber a altura +1*/
    if(r->esq == NULL){
        r->altesq = 0;
    }else if(r->esq->altesq > r->esq->altdir){
        r->altesq = r->esq->altesq +1;
    }else{
        r->altesq = r->esq->altdir + 1; // se não, vai receber a altura da direita +1
    }
    /** se a altura da subarvore esquerda for maior que a altura dos nós da subarvore direita, logo a altura direita vai receber a esquerda +1*/
    if(aux1->dir->altesq > aux1->dir->altdir){
        aux1->altdir = aux1->dir->altesq + 1;
    }else{
        aux1->altdir = aux1->dir->altdir + 1;
    }
    return aux1;
}

static ArvNo* RotEsq(ArvNo* r){

    ArvNo *aux1, *aux2;
    aux1 = r->dir;
    aux2 = aux1->esq;
    r->dir = aux2;
    aux1->esq = r;

    if(r->dir == NULL){
        r->altdir = 0;
    }else if(r->dir->altesq > r->dir->altdir){
        r->altdir = r->dir->altesq + 1;
    }else{
        r->altdir = r->dir->altdir + 1;
    }
    if(aux1->esq->altesq > aux1->esq->altdir){
        aux1->altesq = aux1->esq->altesq + 1;
    }else{
        aux1->altesq = aux1->esq->altdir + 1;
    }

    return aux1;
}




/**XANDY--------------------------------------------------*/
static void imprime(ArvNo* r){
    if(r != NULL){

        imprime(r->esq);
        animal_imprime(r->info);
        imprime(r->dir);

    }
}

void arv_imprime(Arv* a){
    imprime(a->raiz);
}

static void libera(ArvNo* r){
    if(r != NULL){
        libera(r->esq);
        libera(r->dir);
        free(r->info);
        free(r);
    }
}

void arv_libera (Arv* a){
    libera(a->raiz);
}




static ArvNo* Balanceamento(ArvNo* r){

    int d, df;
    d = r->altdir - r->altesq;
    if(d == 2){

        df = r->dir->altdir - r->dir->altesq;
        if(df >= 0)
        {
            r = RotEsq(r);
        }
        else
        {
            r->dir = RotDir(r->dir);
            r = RotEsq(r);
        }
    }
    else if(d == -2){

        df = r->esq->altdir - r->esq->altesq;
        if(df <= 0)
        {
            r = RotDir(r);
        }
        else
        {
            r->esq = RotEsq(r->esq);
            r = RotDir(r);
        }
    }

    return r;
}

static ArvNo* insere (ArvNo* r, ArvNo* no){

    if( r == NULL){
        r = no;
        r->esq = NULL;
        r->dir = NULL;
    }else if(strcmp(r->info->nome,no->info->nome) > 0){
        r->esq = insere(r->esq, no);
        if(r->esq->altdir > r->esq->altesq){
            r->altesq = r->esq->altdir + 1;
        }else{
            r->altesq = r->esq->altesq + 1;
        }
        r = Balanceamento(r);
    }else{
        r->dir = insere(r->dir, no);

        if(r->dir->altdir < r->dir->altesq){
            r->altdir = r->dir->altdir + 1;
        }else{
            r->altdir = r->dir->altesq + 1;
        }
        r = Balanceamento(r);
    }

    return r;
}

void arv_insere(Arv* a, ArvNo* no){
    a->raiz = insere(a->raiz,no);
}




/**FELIPE--------------------------------------------------*/
void carrega_dados(Arv* a){

    char string[121];
    FILE* arq = fopen("entrada.txt", "rt");
    if(arq == NULL){
        printf("Erro na abertura do arquivo.\nO programa será encerrado.\n");
        exit(1);
    }
    while(fgets(string, 121, arq)){

        Animal* an = (Animal*) malloc(sizeof(Animal));
        sscanf(string, "%30[^\t] %30[^\t] %c %d %30[^\t] %f", an->nome, an->raca, &an->sexo, &an->idade, an->procedimento, &an->horario);

        ArvNo* no = arvno_cria(animal_cria(an->nome, an->sexo, an->idade, an->horario, an->procedimento, an->raca));

        arv_insere(a, no);
    }

    fclose(arq);
}

void animal_imprime(Animal* a){
    if(a != NULL)
        printf("NOME: %s\tIDADE: %d\nSEXO: %c\tHORARIO: %.2f\tPROCEDIMENTO: %s\nRACA: %s\n\n",a->nome,a->idade,a->sexo,a->horario,a->procedimento,a->raca);
    else
        printf("ANIMAL NAO ENCONTRADO.\n");
}

void consulta (ArvNo* a){

    if(a == NULL){
        printf("ANIMAL NAO ENCONTRADO.\n");
    }else{
        animal_imprime(a->info);
        printf("\nPROCEDIMENTO:\n"); scanf(" %499[^\n]",a->info->procedimento);

        char* aux = (char*) malloc(30*sizeof(char));
        aux = strcat(strcpy(aux,a->info->nome),".txt");

        FILE* arqconsult = fopen(aux, "wt");
        if(arqconsult == NULL){
            printf("ERRO AO ABRIR O ARQUIVO DE SAIDA.\nO PROGRAMA SERA ABORTADO");
            exit(1);
        }

        fprintf(arqconsult,"NOME: %s\tIDADE: %d\nSEXO: %c\tHORARIO: %.2f\tPROCEDIMENTO: %s\nRACA: %s\n\n",a->info->nome,a->info->idade,a->info->sexo,a->info->horario,a->info->procedimento,a->info->raca);

        fclose(arqconsult);
        free(aux);
    }
}


static void imprime_saida(ArvNo* r, FILE* saida){
    if(r != NULL){

        imprime_saida(r->esq, saida);
        fprintf(saida,"%s\t %s\t %s\n %f\n",r->info->nome, r->info->raca, r->info->procedimento, r->info->horario);
        imprime_saida(r->dir, saida);
    }
}

void arv_imprime_saida(Arv* a){
    FILE* arqsaida = fopen("saida.txt","wt");
    if(arqsaida == NULL){
        printf("ERRO AO ABRIR O ARQUIVO DE SAIDA.\nO PROGRAMA SERA ABORTADO");
        exit(1);
    }
    imprime_saida(a->raiz,arqsaida);
    fclose(arqsaida);
}


char* camelcase(char* strings){
	int i = 0;
	while(strings[i] != '\0'){

		if(strings[0] != ' '){
			strings[0] = toupper(strings[0]);
		}
		if(strings[i-1] == ' ' && strings[i-1] != '\0'){
			strings[i] = toupper(strings[i]);
		}else{
			strings[i] = tolower(strings[i]);
		}
		i++;
	}
	return strings;
}

char ValidSexo(void){
    int nlidos;
    char sexo;
    nlidos = scanf(" %c", &sexo);
    sexo = toupper(sexo);
    while((nlidos != 0) && ((sexo != 'M') && (sexo != 'F'))){
        LimpaBuffer();
        printf("INFORME APENAS O CARACTERE M OU F: ");
        nlidos = scanf(" %c", &sexo);
        sexo = toupper(sexo);
    }
    LimpaBuffer();
    return sexo;
}
