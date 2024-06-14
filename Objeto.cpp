#include "Objeto.h"
#include <iostream>
#include <string>

using namespace std;

Objeto::Objeto(string nome, string descricao, int quantidade, float valor)
    : nome(nome), descricao(descricao), quantidade(quantidade), valor(valor) {}

float Objeto::calcularTotal() const { return quantidade * valor; }

void Objeto::exibirInformacoes() const {
  cout << "Nome: " << nome << "\n";
  cout << "Descrição: " << descricao << "\n";
  cout << "Quantidade: " << quantidade << "\n";
  cout << "Valor: $" << valor << "\n";
}

string Objeto::getNome() const { return nome; }

string Objeto::getDescricao() const { return descricao; }

int Objeto::getQuantidade() const { return quantidade; }

float Objeto::getValor() const { return valor; }

void Objeto::setNome(string n) { nome = n; }

void Objeto::setDescricao(string d) { descricao = d; }

void Objeto::setQuantidade(int q) { quantidade = q; }

void Objeto::setValor(float v) { valor = v; }
