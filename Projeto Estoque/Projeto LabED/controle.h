#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED

void apresentacao(char* mensagem);
void msgm_desp(char* mensagem);
void limpa_tela(void);
void limpa_buffer(void);
void apresenta_menu(int n_itens, int menor_opcao, ...);
int le_opcao(int menor_valor, int maior_valor);
char* le_string(void);

#endif // CONTROLE_H_INCLUDED
