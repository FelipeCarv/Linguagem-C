#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define N 200
#define O 200

void ler_arquivo(FILE* f, char* vet){

while(fgets(vet, N, f) != NULL){
        printf("%s", vet);
    }
}

int main(){
    setlocale(LC_ALL, "portuguese");
    char cad[N];
    int valor, quant;
    char prod[O];
    float preco;

    printf("-X-X-X-X-X-DADOS DOS PRODUTOS-X-X-X-X-X-:\n ");

    FILE* f1 = fopen("Produtos.txt", "rt");
    if(f1 == NULL){
        printf("Erro de abertura no arquivo");
        exit(1);
    }
    ler_arquivo(f1, cad);
    fclose(f1);

    printf("\nDeseja adicionar algo? SIM = 1 / NÃO = 0: ");
    scanf("%d", &valor);

    if(valor == 1){
    f1 = fopen("Produtos.txt", "at");
        if(f1 == NULL){
        printf("Erro de abertura no arquivo");
        exit(1);
        }
    printf("\nDIGITE O PRODUTO: ");
    scanf("%s", &prod);
    printf("\nDIGITE A QUANTIDADE: ");
    scanf("%d", &quant);
    printf("\nDIGITE O PREÇO: ");
    scanf("%f", &preco);

    fprintf(f1, "\n%s       \t\t%d         \t\tR$%.2f", prod, quant, preco);
    printf("\nCONTEÚDO ADICIONADO NO ARQUIVO!!\n");
    } else if(valor == 0){
        printf("\nX-X-X-X-X-PROGRAMA ENCERRADO!!-X-X-X-X-X\n");
        exit(1);
    }

    fclose(f1);

return 0;

}



