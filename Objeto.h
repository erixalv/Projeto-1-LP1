#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

class Objeto {
private:
    string nome;
    string descricao;
    int quantidade;
    float valor;

public:
    Objeto(string nome, string descricao, int quantidade, float valor);
    virtual ~Objeto() {}

    float calcularTotal() const;
    virtual void exibirInformacoes() const;
    string getNome() const;
    string getDescricao() const;
    int getQuantidade() const;
    float getValor() const;
    void setNome(string n);
    void setDescricao(string d);
    void setQuantidade(int q);
    void setValor(float v);
    Objeto() : nome(""), descricao(""), quantidade(0), valor(0.0) {}
};

#endif
