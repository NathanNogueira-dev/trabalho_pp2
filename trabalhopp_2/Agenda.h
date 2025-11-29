#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <fstream>
#include "Nodo.h"
using namespace std;
    // Encapsulamento
class Agenda {
private:
    Nodo* inicio;
    // Construtor Padrão com Lista vazia
public:
    Agenda() {
        inicio = nullptr;
    }

    // Destrutor para evitar vazamento de memória
    ~Agenda() {
        while (inicio != nullptr) {
            Nodo* lixo = inicio;
            inicio = inicio->prox;
            delete lixo;
        }
    }

    // Função buscar começando do inicio, se encontrar retorna o ponteiro pro nó caso não o ponteiro nulo
    Nodo* buscar(string nome) {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            if (aux->cont.getNome().find(nome) != string::npos) {
                return aux;
            }
            aux = aux->prox;
        }
        return nullptr;
    }
    // Se achou o mesmo nome, atualiza os dados sem duplicar
    void inserir(Contato c) {
        Nodo* achou = buscar(c.getNome());
        if (achou != nullptr) {
            achou->cont = c;
            return;
        }

        // insere no inicio caso novo nome
        Nodo* novo = new Nodo(c);
        novo->prox = inicio;
        inicio = novo;
    }

    void remover(string nome) {
        if (inicio == nullptr) return; // Se lista nula só volta

        // remover caso no inicio
        if (inicio->cont.getNome() == nome) {
            Nodo* lixo = inicio;
            inicio = inicio->prox;
            delete lixo;
            return;
        }

        // remover no meio/fim (interliga o anterior com o próximo e deleta o nó atual)
        Nodo* ant = inicio;
        Nodo* aux = inicio->prox;

        while (aux != nullptr) {
            if (aux->cont.getNome() == nome) {
                ant->prox = aux->prox;
                delete aux;
                return;
            }
            ant = aux;
            aux = aux->prox;
        }
    }
    // Percorre a lista e imprime ela inteira com o toString
    void listar() {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            cout << aux->cont.toString() << endl;
            aux = aux->prox;
        }
    }
    // Salva um contato por linha separado por ;
    void salvar(string arq) {
        ofstream out(arq);

        Nodo* aux = inicio;
        while (aux != nullptr) {
            out << aux->cont.getNome() << ";"
                << aux->cont.getTelefone() << ";"
                << aux->cont.getEndereco() << ";"
                << aux->cont.getRelacao() << "\n";

            aux = aux->prox;
        }
    }
    // Carrega o arquivo salvo
    void carregar(string arq) {
        ifstream in(arq);
        string n, t, e, r;

        // apaga lista antiga
        while (inicio != nullptr) {
            Nodo* lixo = inicio;
            inicio = inicio->prox;
            delete lixo;
        }
        // Lê 4 campos separados por ; cria um contato e insere na lista
        while (getline(in, n, ';')) {
            getline(in, t, ';');
            getline(in, e, ';');
            getline(in, r);

            inserir(Contato(n, t, e, r));
        }
    }
};

#endif

