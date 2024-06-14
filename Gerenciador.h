#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#pragma once

#include "Cliente.h"
#include "ClienteCadastrado.h"
#include "ClienteVip.h"
#include "Objeto.h"
#include <iostream>
#include <string>

class Gerenciador {
  public:
    int menucliente();
    void cadastrarCliente();
    void exibirClientes();
    void deletarCliente();
    void procurarCliente();
    void alterarCliente();
  private:
    Cliente *cliente;
};






#endif