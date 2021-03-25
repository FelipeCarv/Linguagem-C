#ifndef ANIMAIS_H_INCLUDED
#define ANIMAIS_H_INCLUDED

    typedef struct animal Animal;

    Animal* list_AnimalCria(void);
    Animal* list_AnimalInsere(Animal* la, char* nome, char* tipo, char* raca, char* genero);
    Animal* list_AnimalRemove(Animal* la, char* nome);
    int list_AnimalVazia(Animal* la);
    int list_AnimalBusca(Animal* la, char* nome);
    void list_AnimalImprime(Animal* la);
    Animal* list_AnimalCarrega(FILE* animais);
    void list_AnimalSalva(FILE* animais, Animal* la);
    void list_AnimalLibera(Animal* la);

#endif // ANIMAIS_H_INCLUDED
