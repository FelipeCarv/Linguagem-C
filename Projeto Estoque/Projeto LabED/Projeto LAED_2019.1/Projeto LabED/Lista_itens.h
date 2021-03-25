#ifndef LISTA_ITENS_H_INCLUDED
#define LISTA_ITENS_H_INCLUDED

typedef struct produto Produto;

Produto* lst_cria(void);
Produto* lst_insere(Produto* p, char* nome, char* quantidade, char* preco);
Produto* lst_remove(Produto* p, char* nome);
Produto* lst_insereArq(FILE* prod);
int lst_vazia(Produto* p);
int lst_busca(Produto* p, char* nome);
void lst_imprime(Produto* p);
void lst_salvarq(FILE* produtos, Produto* p);
void lst_libera(Produto* p);


#endif // LISTA_ITENS_H_INCLUDED
