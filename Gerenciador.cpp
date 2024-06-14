#include "Gerenciador.h"
#include "Cliente.h"
#include "ClienteCadastrado.h"
#include "ClienteVip.h"
#include "Objeto.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

 int Gerenciador::menucliente(){
  int escolha;
      do {
          cout << "===== MENU =====" << endl;
          cout << "1. Cadastrar Cliente" << endl;
          cout << "2. Exibir Clientes" << endl;
          cout << "3. Deletar Cliente" << endl;
          cout << "4. Buscar Cliente" << endl;
          cout << "5. Alterar Cliente" << endl;
          cout << "6. Sair" << endl;
          cout << "Escolha: ";
          cin >> escolha;
          cin.ignore(); 

          switch (escolha) {
              case 1:
                  cadastrarCliente();
                  break;
              case 2:
                  exibirClientes();
                  break;
              case 3:
                  deletarCliente();
                  break;
              case 4:
                  procurarCliente();
                  break;
              case 5:
                  alterarCliente();
                  break;
              case 6:
                  cout << "Encerrando o programa..." << endl;
                  break;
              default:
                  cout << "Escolha inválida. Tente novamente." << endl;
          }
      } while (escolha != 6);
   return escolha;
 }

   
void Gerenciador::cadastrarCliente() {
  fstream s;

  s.open("info.txt", ios_base::out | ios_base::app);

  if (!s.is_open()) {
    cout << "Arquivo não aberto";
  }

  string n, ad;
  int tipo;
  cout << "Digite o nome do cliente: ";
  getline(cin, n);
  cout << "Digite o endereço do cliente: ";
  getline(cin, ad);
  cout << "Digite o TIPO do cliente [1 - Comum // 2 - VIP // 3 - CADASTRADO]"
       << endl;
  cin >> tipo;
  cin.ignore();

  cliente->setNome(n);
  cliente->setEndereco(ad);

  if (tipo == 1) {
    cliente = new Cliente(n, ad);
    s << cliente->getNome() << endl;
    s << "CLIENTE SEM DESCONTO" << endl;
    s << cliente->getEndereco() << endl;
  }
  if (tipo == 2) {
    int age;
    string tel;
    cout << "Digite a idade do cliente: ";
    cin >> age;
    cin.ignore();
    cout << "Digite o telefone do cliente: ";
    getline(cin, tel);
    cliente = new ClienteVip(n, ad, age, tel);

    ClienteVip *temp = (ClienteVip *)cliente;
    s << cliente->getNome() << endl;
    s << "CLIENTE VIP, DESCONTO DE 15%" << endl;
    s << cliente->getEndereco() << endl;
    s << temp->getidade() << endl;
    s << temp->gettelefone() << endl;
  }
  if (tipo == 3) {
    string r, c;
    cout << "Digite o RG do cliente: ";
    getline(cin, r);
    cout << "Digite o CPF do cliente: ";
    getline(cin, c);
    cliente = new ClienteCadastrado(n, ad, r, c);

    ClienteCadastrado *temp = (ClienteCadastrado *)cliente;
    s << cliente->getNome() << endl;
    s << "CLIENTE CADASTRADO, DESCONTO DE 30%" << endl;
    s << cliente->getEndereco() << endl;
    s << temp->getRG() << endl;
    s << temp->getCpf() << endl;
  }
  s.close();
}

void Gerenciador::exibirClientes() {
  fstream s;
  int cont = 0;

  s.open("info.txt", ios_base::in);

  if (!s.is_open()) {
    cout << "Arquivo não aberto";
  }

  string line;
  while (getline(s, line)) {
    cont++;
  }

  string file[cont];

  for (int i = 0; i < cont; i++) {
    getline(s, file[i]);
  }

  for (int i = 0; i < cont; i++) {
    cout << file[i] << endl;
  }
  
  s.close();
}

void Gerenciador::deletarCliente() {
  fstream s;
  
  int cont = 0;
  s.open("info.txt", ios_base::in);

  string line;
  while (getline(s, line)) {
    cont++;
  }

  string file[cont];

  for (int i = 0; i < cont; i++) {
    getline(s, file[i]);
  }

  s.close();

  string clienteDel;
  cout << "Digite o nome do cliente que deseja deletar: ";
  getline(cin, clienteDel);

  for (int i = 0; i < cont; i++) {
    if (file[i] == clienteDel) {
      if(file [i+1] == "CLIENTE SEM DESCONTO") {
        file[i] = "";
        file[i+1] = "";
        file[i+2] = "";
      }

      if(file[i+1] == "CLIENTE VIP, DESCONTO DE 15%") {
        file[i] = "";
        file[i+1] = "";
        file[i+2] = "";
        file[i+3] = "";
        file[i+4] = "";
      }

      if(file[i+1] == "CLIENTE CADASTRADO, DESCONTO DE 30%") {
        file[i] = "";
        file[i+1] = "";
        file[i+2] = "";
        file[i+3] = "";
        file[i+4] = "";
      }
    }
  }

  s.open("info.txt", ios_base::out);
  for (int i = 0; i < cont; i++) {
    s << file[i] << endl;
  }

  s.close();
}

void Gerenciador::procurarCliente() {
  fstream s;
  int cont = 0;
  s.open("info.txt", ios_base::in);

  string line;
  while (getline(s, line)) {
    cont++;
  }
  string file[cont];
  for (int i = 0; i < cont; i++) {
    getline(s, file[i]);
  }

  s.close();

  string clienteProcurado;
  cout << "Digite o nome do cliente que deseja procurar: ";
  getline(cin, clienteProcurado);

  int aux = 0;

  for (int i = 0; i < cont; i++) {
    if (file[i] == clienteProcurado) {
      aux++;
      
      if(file[i+1] == "CLIENTE SEM DESCONTO") {
        cout << file[i] << endl;
        cout << file[i+1] << endl;
        cout << file[i+2] << endl;
      }

      if(file[i+1] == "CLIENTE VIP, DESCONTO DE 15%") {
        cout << file[i] << endl;
        cout << file[i+1] << endl;
        cout << file[i+2] << endl;
        cout << file[i+3] << endl;
        cout << file[i+4] << endl;
      }

      if(file[i+1] == "CLIENTE CADASTRADO, DESCONTO DE 30%") {
        cout << file[i] << endl;
        cout << file[i+1] << endl;
        cout << file[i+2] << endl;
        cout << file[i+3] << endl;
        cout << file[i+4] << endl;
      }
    }
  }
  if(aux == 0) {
    cout << "Cliente não encontrado" << endl;
  }
}

void Gerenciador::alterarCliente() {
  fstream s;
  int cont = 0;
  s.open("info.txt", ios_base::in);
  
  string line;
  while (getline(s, line)) {
    cont++;
  }

  string file[cont];

  for (int i = 0; i < cont; i++) {
    getline(s, file[i]);
  }

  s.close();

  string clienteAlterado;
  getline(cin, clienteAlterado);

  int alteracao;

  for (int i = 0; i < cont; i++) {
    if (file[i] == clienteAlterado) {
      if(file[i+1] == "CLIENTE SEM DESCONTO") {
        cout << "Digite o que deseja alterar: [1 - NOME // 2 - ENDEREÇO]" << endl;
        cin >> alteracao;
        cin.ignore();

        if(alteracao == 1) {
          string novoNome;
          cout << "Insira novo nome: " << endl;
          getline(cin, novoNome);
          file[i] = novoNome;
        }
        if(alteracao == 2) {
          string novoEndereco;
          cout << "Insira novo endereço: " << endl;
          getline(cin, novoEndereco);
          file[i+2] = novoEndereco;
        }
      }

      if(file[i+1] == "CLIENTE VIP, DESCONTO DE 15%") {
        cout << "Digite o que deseja alterar: [1 - NOME // 2 - ENDEREÇO // 3 - IDADE // 4 - TELEFONE" << endl;
        cin >> alteracao;
        cin.ignore();

        if(alteracao == 1) {
          string novoNome;
          cout << "Insira o novo nome: " << endl;
          getline(cin, novoNome);
          file[i] = novoNome;
        }
        if(alteracao == 2) {
          string novoEndereco;
          cout << "Insira o novo endereço: " << endl;
          getline(cin, novoEndereco);
          file[i+2] = novoEndereco;
        }
        if(alteracao == 3) {
          int novaIdade;
          cout << "Insira a nova idade: " << endl;
          cin >> novaIdade;
          cin.ignore();
          file[i+3] = novaIdade;
        }
        if(alteracao == 4) {
          string novoTel;
          cout << "Insira o novo telefone: " << endl;
          getline(cin, novoTel);
          file[i+4] = novoTel;
        }
      }

      if(file[i+1] == "CLIENTE CADASTRADO, DESCONTO DE 30%") {
        cout << "Digite o que deseja alterar: [1 - NOME // 2 - ENDEREÇO // 3 - RG // 4 - CPF" << endl;
        cin >> alteracao;
        cin.ignore();

        if(alteracao == 1) {
          string novoNome;
          cout << "Insira o novo nome: " << endl;
          getline(cin, novoNome);
          file[i] = novoNome;
        }
        if(alteracao == 2) {
          string novoEndereco;
          cout << "Insira o novo endereço: " << endl;
          getline(cin, novoEndereco);
          file[i+2] = novoEndereco;
        }
        if(alteracao == 3) {
          string novoRG;
          cout << "Insira o novo RG: " << endl;
          getline(cin, novoRG);
          file[i+3] = novoRG;
        }
        if(alteracao == 4) {
          string novoCPF;
          cout << "Insira o novo CPF: " << endl;
          getline(cin, novoCPF);
          file[i+4] = novoCPF;
        }
      }
    }
  }

  s.open("info.txt", ios_base::out);
  for (int i = 0; i < cont; i++) {
    s << file[i] << endl;
  }
  s.close();
}