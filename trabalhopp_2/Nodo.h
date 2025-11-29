#ifndef NODO_H
#define NODO_H

#include "Contato.h"

class Nodo {
    // Armazena um contato como conteúdo e um ponteiro para o proximo nó inicialmente vazio
public:
    Contato cont;
    Nodo* prox;
    // Pondo o contato no nó
    Nodo(Contato c) {
        cont = c;
        prox = nullptr;
    }
};

#endif

