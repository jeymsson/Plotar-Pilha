#ifndef PILHA_H
#define PILHA_H

#include "Nol.h"
#include "funcoes.h"
using namespace std;

class Pilha{

private:
    Nol * Header;
    Nol * Trailer;

    void insert_before(Nol * noh, int idade, string & texto);
    void remove(Nol * noh);
    void push_back(int idade, string & nome);
public:
    Pilha();
    ~Pilha();
    Nol * getHeader();
    Nol * getTrailer();
    bool empty();


    void Push_back_Org(int idade, string & nome);
    void pop_back();
    string Print();

};

#endif // PILHA_H
