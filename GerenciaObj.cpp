#include "GerenciaObj.h"
#include "Objeto.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int GerenciaObj::menu() {
    int escolha;
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Cadastrar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Deletar Produto" << endl;
        cout << "4. Buscar Produto" << endl;
        cout << "5. Alterar Produto" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha: ";
        cin >> escolha;
        cin.ignore();

        switch (escolha) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                deletarProduto();
                break;
            case 4:
                pesquisarProduto();
                break;
            case 5:
                alterarProduto();
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

void GerenciaObj::adicionarProduto() {
    fstream s;

    s.open("infoObjetos.txt", ios_base::out);

    if (!s.is_open()) {
        cout << "Arquivo não aberto";
    }

    string n, d;
    int q;
    float v;
    cout << "Digite o nome do produto: ";
    getline(cin, n);
    cout << "Digite a descrição do produto: ";
    getline(cin, d);
    cout << "Digite a quantidade do produto: ";
    cin >> q;
    cout << "Digite o valor do produto: ";
    cin >> v;

    objeto->setNome(n);
    objeto->setDescricao(d);
    objeto->setQuantidade(q);
    objeto->setValor(v);

  objeto = new Objeto(n, d, 0, 0.0f);
    s << objeto->getNome() << endl;
    s << objeto->getDescricao() << endl;
    s << objeto->getQuantidade() << endl;
    s << objeto->getValor() << endl;

    s.close();
}

void GerenciaObj::listarProdutos() {
    fstream s;
    int cont = 0;

    s.open("infoObjetos.txt", ios_base::in);

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

void GerenciaObj::deletarProduto() {
    fstream s;

    int cont = 0;
    s.open("infoObjetos.txt", ios_base::in);

    string line;
    while (getline(s, line)) {
        cont++;
    }

    string file[cont];

    for (int i = 0; i < cont; i++) {
        getline(s, file[i]);
    }

    s.close();

    string produtoDel;
    cout << "Digite o nome do produto que deseja deletar: ";
    getline(cin, produtoDel);

    for (int i = 0; i < cont; i++) {
        if (file[i] == produtoDel) {
            file[i] = "";
            file[i + 1] = "";
            file[i + 2] = "";
        }
    }

    s.open("infoObjetos.txt", ios_base::out);
    for (int i = 0; i < cont; i++) {
        s << file[i] << endl;
    }

    s.close();
}

void GerenciaObj::pesquisarProduto() {
    fstream s;
    int cont = 0;
    s.open("infoObjetos.txt", ios_base::in);

    string line;
    while (getline(s, line)) {
        cont++;
    }
    string file[cont];
    for (int i = 0; i < cont; i++) {
        getline(s, file[i]);
    }

    s.close();

    string produtoProcurado;
    cout << "Digite o nome do produto que deseja procurar: ";
    getline(cin, produtoProcurado);

    for (int i = 0; i < cont; i++) {
        if (file[i] == produtoProcurado) {
            cout << file[i] << endl;
            cout << file[i + 1] << endl;
            cout << file[i + 2] << endl;
        }
    }
}

void GerenciaObj::alterarProduto() {
    fstream s;
    int cont = 0;
    s.open("infoObjetos.txt", ios_base::in);

    string line;
    while (getline(s, line)) {
        cont++;
    }

    string file[cont];

    for (int i = 0; i < cont; i++) {
        getline(s, file[i]);
    }

    s.close();

    string produtoAlterado;
    getline(cin, produtoAlterado);

    int alteracao;

    for (int i = 0; i < cont; i++) {
        if (file[i] == produtoAlterado) {
            cout << "Digite o que deseja alterar: [1 - NOME // 2 - DESCRIÇÃO // 3 - Quantidade]" << endl;
            cin >> alteracao;
            cin.ignore();

            if (alteracao == 1) {
                string novoNome;
                cout << "Insira novo nome: " << endl;
                getline(cin, novoNome);
                file[i] = novoNome;
            }
            if (alteracao == 2) {
                string novaDescricao;
                cout << "Insira nova descrição: " << endl;
                getline(cin, novaDescricao);
                file[i + 2] = novaDescricao;
            }
            if (alteracao == 3){
                int novaQuantidade;
                cout << "Insira a nova quantidade: " << endl;
                cin >> novaQuantidade;
                file[i+3] = novaQuantidade;
            }
        }
    }

    s.open("infoObjetos.txt", ios_base::out);
    for (int i = 0; i < cont; i++) {
        s << file[i] << endl;
    }
    s.close();
}
