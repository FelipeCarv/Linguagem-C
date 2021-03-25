#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct animal Animal;
typedef struct arvno ArvNo;
typedef struct arv Arv;

Arv* arv_cria(void);
ArvNo* arvno_cria(Animal* a);
ArvNo* arv_busca(Arv* a, char* nome);
Animal* animal_cria(char* nome, char sexo, int idade, float horario, char* procedimento, char* raca);

void arv_imprime(Arv* a);
void arv_libera (Arv* a);
void arv_insere(Arv* a, ArvNo* no);
void carrega_dados (Arv* a);

void arv_imprime_saida(Arv* a);
void animal_imprime(Animal* a);
void consulta (ArvNo* no);
char* camelcase(char* strings);
char ValidSexo(void);

#endif // AVL_H_INCLUDED
