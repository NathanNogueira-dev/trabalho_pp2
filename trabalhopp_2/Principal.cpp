#include <iostream>
#include "Agenda.h"
using namespace std;

int main() {

    Agenda agenda;

    agenda.inserir(Contato("Fulano", "99999999", "Rua A", "UFF"));
    agenda.inserir(Contato("Ciclano", "88888888", "Rua B", "Cederj"));
    agenda.inserir(Contato("Beltrano", "88889999", "Rua C", "Infancia"));

    cout << "Agenda inicial:\n";
    agenda.listar();

    agenda.inserir(Contato("Fulano", "77777777", "Rua D", "UFF"));

    agenda.remover("Ciclano");

    cout << "\nAgenda apos alteracoes:\n";
    agenda.listar();

    // opcional pra reacessar é agenda.carregar("contatos.t
    agenda.salvar("contatos.txt");

    return 0;
}
