#include "ClienteCadastrado.h"
#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;
ClienteCadastrado::ClienteCadastrado(string nome, string endereco, string rg, string cpf) : Cliente(nome, endereco), cpf(cpf), rg(rg) {}


void ClienteCadastrado::aplicaDesconto(float& preco) const {
    preco -= (preco * 0.15);
}


void ClienteCadastrado::exibirInformacoes() const {
    cout << "Tipo: Cliente CADASTRADO, Desconto de 15 %" << endl;
}

string ClienteCadastrado::getRG() const {
  return rg;    
}

string ClienteCadastrado::getCpf() const {
  return cpf;
}

void ClienteCadastrado::setRG(string r) {
  rg = r;
}

void ClienteCadastrado::setCpf(string c) {
  cpf = c;
}

