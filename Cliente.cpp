#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(string nome, string endereco)
    : nome(nome), endereco(endereco) {}

void Cliente::exibirInformacoes() const {
    cout << "Nome: " << nome << "\n";
    cout << "Endereco: " << endereco << "\n";
}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getEndereco() const {
  return endereco;
}

void Cliente::setNome(string n){
  nome = n;
} 

void Cliente::setEndereco(string ad) {
  endereco = ad;
}