#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "menu.h"


void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int LeOpcao(int menorValor, int maiorValor){
  int op;
  while (1) {
    printf("\nDIGITE SUA OPCAO: ");
    scanf("%i", &op);
    if (op >= menorValor && op <= maiorValor){
      LimpaBuffer();
      break;
    }else{
      printf("\nOPCAO INVALIDA. TENTE NOVAMENTE");
      printf("\nA OPCAO DEVE ESTAR ENTRE %i E %i. \n",
      menorValor, maiorValor);
      LimpaBuffer();
    }
  }
  return op;
}

int LeInteiro(void) {
    int umInt, nValoresLidos;
    nValoresLidos = scanf("%d", &umInt);
    while ((nValoresLidos == 0) || (umInt < 0)) { //Nenhum inteiro foi lido
        LimpaBuffer();
        printf("ENTRADA INCORRETA. DIGITE UM VALOR INTEIRO: ");
        nValoresLidos = scanf("%d", &umInt);
    }
    LimpaBuffer();
    return umInt;
}

void ApresentaMenu(int nItens, int menorOpcao, ...) {
    //setlocale(LC_ALL, "Portuguese");
    int /*i,*/ j;
    va_list argumentos;
    /* Inicia lista de argumentos vari�veis */
    va_start(argumentos, menorOpcao);
    /* L� cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento � char *, que � o tipo que */
    /* representa strings em C */
    //for(i = 0; i < 2; ++i) {
            for(j = 0; j < nItens; ++j){
                printf("|\t%i-%s\n", menorOpcao++, va_arg(argumentos, char *));
            }
        //printf("\n");

    //}
    va_end(argumentos);/* Encerra processamento de argumentos */
}

char* LeString(void) {
    char aux[121];
    scanf(" %120[^\n]", aux);
    int n = strlen(aux);
    char* string = (char*) malloc((n+1)*sizeof(char));
    strcpy(string, aux);
    int i = 0;
    while(string[i] != '\0'){
        if(isdigit(string[i])||(ispunct(string[i]))){
            printf("\nENTRADA INCORRETA. DIGITE SOMENTE CARACTERES: ");
            return LeString();
        }
        i++;
    }
    return string;
}

static char* recebe(){
    char* valor = (char*) malloc(10*sizeof(char));
    int i = 0;
    scanf(" %9[^\n]", valor);
    while(valor[i] != '\0'){
        if(valor[i] == ','){
            valor[i] = ':';
            break;
        }
        i++;
    }
    return valor;
}

float LeFloat(void) {
    float umFloat;
    int nValoresLidos;
    nValoresLidos = sscanf(recebe(),"%f", &umFloat);
    while ((nValoresLidos == 0) || (umFloat < 0)) { //Nenhum inteiro foi lido
        LimpaBuffer();
        printf("ENTRADA INCORRETA. DIGITE UM VALOR REAL: ");
        nValoresLidos = sscanf(recebe(),"%f", &umFloat);
    }
    LimpaBuffer();
    return umFloat;
}
