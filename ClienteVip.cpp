#include "ClienteVip.h"

ClienteVip::ClienteVip(string nome, string endereco, int idade, string telefone)
    : Cliente(nome, endereco), idade(idade), telefone(telefone) {}

void ClienteVip::exibirInformacoes() const {
  Cliente::exibirInformacoes();
  cout << "Idade: " << idade << "\n";
  cout << "Telefone: " << telefone << "\n";
  cout << "Parabéns você recebeu um desconto de 30% no valor total da compra!\n";
}

void ClienteVip::aplicarDesconto(float &preco) const { preco -= (preco * 0.3); }

int ClienteVip::getidade() const {
  return idade;
}

string ClienteVip::gettelefone() const {
  return telefone;
}

void ClienteVip::setidade(int i){
  idade = i;
}

void ClienteVip::settelefone(string t){
  telefone = t;
}