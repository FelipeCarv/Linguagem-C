#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int LeOpcao(int menorValor, int maiorValor);
int LeInteiro(void);
float LeFloat(void);
char* LeString(void);
void ApresentaMenu(int nItens, int menorOpcao, ...);
void LimpaBuffer(void);

#endif // MENU_H_INCLUDED
