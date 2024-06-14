#ifndef CLIENTEVIP_H
#define CLIENTEVIP_H

#include "Cliente.h"
#include <iostream>

using namespace std;

class ClienteVip : public Cliente {
private:
  int idade;
  string telefone;

public:
  ClienteVip(string nome, string endereco, int idade, string telefone);
  void exibirInformacoes() const override;
  void aplicarDesconto(float &preco) const;
  int getidade() const;
  string gettelefone() const;
  void setidade(int idade);
  void settelefone(string telefone);
};

#endif
