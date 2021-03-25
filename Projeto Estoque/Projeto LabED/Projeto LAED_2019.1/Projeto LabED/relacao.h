#ifndef RELACAO_H_INCLUDED
#define RELACAO_H_INCLUDED

typedef struct relacao Relacao;

Relacao* relacao_cria(void);
Relacao* relacao_insere(Relacao* p, char* nome, char* data, char* produto);
void relacao_salva(FILE* relacao, Relacao* p);
Relacao* relacao_carrega(FILE* relacao);
void relacao_imprime(Relacao* p);
void relacao_libera(Relacao* p);
int relacao_vazia(Relacao* p);

#endif // RELACAO_H_INCLUDED
