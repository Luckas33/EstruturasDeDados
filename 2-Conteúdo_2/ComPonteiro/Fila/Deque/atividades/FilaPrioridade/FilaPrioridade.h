#include <iostream>

using namespace std;

typedef int tipoItem;

class FilaPrioridade
{
private:
    struct Noh
    {
        tipoItem valor;
        Noh *prox;
    };
    Noh *inicio;
    Noh *final;

public:
    FilaPrioridade();
    ~FilaPrioridade();
    void enfilar(tipoItem valor);
    void enfilarPrioridade(tipoItem valor);
    void desenfilar();
    void imprimir();
    bool vazio();
};