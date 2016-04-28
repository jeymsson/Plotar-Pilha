#ifndef MANIPULACOES_H
#define MANIPULACOES_H

#include "pilha.h"
#include "funcoes.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std ;

Pilha * importar_pilha(string & texto);
vector<string> split(string str, char delimiter);

#endif // MANIPULACOES_H
