#ifndef CLIENTECADASTRADO_H
#define CLIENTECADASTRADO_H

#pragma once

#include "Cliente.h"
#include <iostream>
#include <string>

using namespace std;

class ClienteCadastrado : public Cliente {
public:
  ClienteCadastrado(string n, string e, string rg, string cp);
  void exibirInformacoes() const;
  void aplicaDesconto(float &preco) const;

  string getCpf() const;
  void setCpf(string cpf);

  string getRG() const;
  void setRG(string rg);
private:
  string cpf;
  string rg;
};

#endif