#include <iostream>
#include "Conjunto.h"
using namespace std;

typedef int TipoItem;

class Interador{
public:
    TipoItem *point;
    Interador();
    ~Interador();
    Interador Inicio(Conjunto conjunto);
    Interador Fim(Conjunto conjunto);
    void avancar(Interador inicio);
    TipoItem acessar_elemento(Interador it);
    bool sao_diferentes(Interador inicio, Interador fim);
};

