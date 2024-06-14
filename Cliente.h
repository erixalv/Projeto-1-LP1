#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente {
protected:
    string nome;
    string endereco;

public:
    Cliente(string nome, string endereco);
    virtual ~Cliente() {}

    virtual void exibirInformacoes() const;
    string getNome() const;
    void setNome(string n);
    string getEndereco() const;
    void setEndereco(string ad);
};

#endif
