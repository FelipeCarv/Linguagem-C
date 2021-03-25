#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

    typedef struct relatorio Relatorio;

    Relatorio* list_RelatorioCria(void);
    Relatorio* list_RelatorioInsere(Relatorio* lr, char* nome, char* t, char* endereco, char* animal);
    int list_RelatorioVazia(Relatorio* lr);
    void list_RelatorioImprime(Relatorio* lr);
    Relatorio* list_RelatorioCarrega(FILE* relatorio);
    void list_RelatorioSalva(FILE* relatorio, Relatorio* lr);
    void list_RelatorioLibera(Relatorio* lr);

#endif // RELATORIO_H_INCLUDED
