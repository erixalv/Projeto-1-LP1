#include "Cliente.h"
#include "ClienteCadastrado.h"
#include "ClienteVip.h"
#include "GerenciaObj.h"
#include "Gerenciador.h"
#include "Objeto.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int escolherMenu() {
  int escolha;
  cout << "-----------------------\n";
  cout << "|    MENU PRINCIPAL:  |\n";
  cout << "-----------------------\n";
  cout << "1 - Gerenciar Clientes\n";
  cout << "2 - Gerenciar Objetos\n";
  cout << "3 - Sair\n";
  cout << "Escolha uma opção: ";
  cin >> escolha;
  cin.ignore();
  return escolha;
}


int main() {
  Gerenciador gerenciador;
  GerenciaObj gerenciaObj;

  int mainChoice;
  mainChoice = escolherMenu();

  switch (mainChoice) {
  case 1:
    gerenciador.menucliente();
    
    break;

  case 2:

    gerenciaObj.menu();
    
    break;
  
  case 3:
    cout << "\n Saindo... \n";
    break;

  default:
    cout << "\n Opção inválida. \n";
  }
}