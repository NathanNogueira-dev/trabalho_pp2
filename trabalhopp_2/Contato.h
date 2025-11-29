#ifndef CONTATO_H
#define CONTATO_H

#include <iostream>
using namespace std;

class Contato {
    // Encapsulando
private:
    string nome, telefone, endereco, relacao;

    // Construtor Padrão
public:
    Contato() {
        nome = telefone = endereco = relacao = "";
    }
    // Construtor com Parametros
    Contato(string n, string t, string e, string r) {
        nome = n;
        telefone = t;
        endereco = e;
        relacao = r;
    }
    // Lê os valores privados sem poder alterar
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
    string getEndereco() const { return endereco; }
    string getRelacao() const { return relacao; }

    // Permitindo alterações com exceção de Nome (imutável)
    void setTelefone(string t) { telefone = t; }
    void setEndereco(string e) { endereco = e; }
    void setRelacao(string r) { relacao = r; }

    // Criando um toString de cada Contato
    string toString() const {
        return "Nome: " + nome +
               " | Telefone: " + telefone +
               " | Endereco: " + endereco +
               " | Relacao: " + relacao;
    }
};

#endif

