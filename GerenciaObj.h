#ifndef GERENCIAOBJ_H
#define GERENCIAOBJ_H

#include "Objeto.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GerenciaObj {
private:
    Objeto *objeto;

public:
    int menu();
    void adicionarProduto();
    void listarProdutos();
    void pesquisarProduto();
    void alterarProduto();
    void deletarProduto();
};

#endif 
