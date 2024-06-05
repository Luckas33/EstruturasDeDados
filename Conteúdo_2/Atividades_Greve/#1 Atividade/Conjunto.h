#include <iostream>
using namespace std;

typedef int TipoItem;

class Conjunto{
public:
    int n;
    TipoItem *estrutura;
    Conjunto();
    ~Conjunto();
    void inserir(TipoItem item);
    bool vazio();
    bool cheio();
};
