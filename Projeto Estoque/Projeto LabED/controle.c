#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "controle.h"

// FUNÇÕES PARA AUXILIAR NO CONTROLE DAS AÇÕES DO PROGRAMA
void apresentacao(char* mensagem){
      printf("\n%s\n",mensagem);
}

void msgm_desp(char* mensagem){
        printf("\n%s\n",mensagem);
}

void limpa_tela(void){
        system("cls");
}

void limpa_buffer(void){
        int valorLido;
        do {
            valorLido = getchar();
        }
        while
        ((valorLido != '\n') && (valorLido != EOF));

}

int le_opcao(int menor_valor, int maior_valor){
        int op;
        while (1) {

            printf("\nDIGITE SUA OPCAO: ");
            op = getchar();

            if (op >= menor_valor && op <= maior_valor) {
                limpa_buffer();
                break;
            }

            else {
                printf("\nOPCAO INVALIDA. TENTE NOVAMENTE.");
                printf("\nA OPCAO DEVE ESTAR ENTRE '%c' E '%c'. \n",menor_valor, maior_valor);
                limpa_buffer();
            }
        }

        return op;
}

 char* le_string(void){ // LÊ UMA STRING
        char* string = (char*) malloc (81 * sizeof(char));
        scanf(" %80[^\n]", string);
        limpa_buffer();
        return string;
}

void apresenta_menu(int n_itens, int menor_opcao, ...){
        int i;
        va_list argumentos;
        //INICIA A LISTA DE ARGUMENTO
        va_start(argumentos,menor_opcao);
        //LÊ CADA ARGUMENTO E IMPRIME NA TELA
        for(i = 0;i < n_itens; ++i){
            printf(" %c-%s\n",menor_opcao++,va_arg(argumentos,char *));
        }
        va_end(argumentos);
}
