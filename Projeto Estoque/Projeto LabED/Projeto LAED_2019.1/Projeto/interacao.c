#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "interacao.h"

    //PARAMETRO (I) APRESENTAÇÃO DO PROGRAMA
    void apresenta_programa(char* msg)
    {
        printf("\n%s\n\n",msg);
    }

    //PARAMETRO (II) DESPEDIDA DO PROGRAMA
    void mensagem_despedida(char* msg)
    {
        printf("\n%s\n\n",msg);
    }

    //PARAMETRO (III) LIMPA A TELA DE ÚSUARIO
    void limpa_tela(void)
    {
        system("cls");//FUNÇÃO DA 'STDLIB.H'
    }

    //PARAMETRO (IV) LIMPA O BUFFER DE ENTRADA
    void limpa_buffer(void)
    {
        int valorLido; // VALOR LIDO DEVE SER 'INT'
        do {
            valorLido = getchar();

        } while ((valorLido != '\n') && (valorLido != EOF));
    }

    //PARAMETRO (V) INTERAÇÃO E VALIDAÇÃO DE UMA OPÇÃO DIGITADA PELO ÚSUARIO
    int le_opcao(int menor_valor, int maior_valor)
    {   //LÊ E VALIDA A OPÇÃO DIGITADA PELO USUARIO
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

    //PARAMETRO (VI) LÊ UMA UMA CADEIA DE CARACTERES
    char* le_string(void)
    {
        char* string = (char*) malloc (81 * sizeof(char));
        scanf(" %80[^\n]", string);
        limpa_buffer();
        return string;
    }

    //PARAMETRO (VII) APRESENTA UM MENU COM NÚMERO INDETERMINADO DE OPÇÕES
    void apresenta_menu(int n_itens, int menor_opcao, ...)
    {
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
