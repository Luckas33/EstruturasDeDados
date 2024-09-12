/*
Escreva uma variação da implementação de dicionário feita em sala que utilize lista duplamente encadeada.
Uma causa típica de erros em implementações usando listas encadeadas é tentar manipular um nó através de um ponteiro sem lembrar de testar se esse ponteiro é ou não nulo.
Esse problema aumenta quando há múltiplos ponteiros sendo testados de forma combinada, como no caso de uma lista duplamente encadeada.
Uma solução muitas vezes satisfatória para esse problema é usar um nó sentinela, que é um nó extra, feito para nunca armazenar um elemento propriamente dito da contêiner (exceto temporariamente, como auxílio em determinadas operações), tendo o propósito específico de marcar o fim da lista encadeada. Assim sendo, escreva uma variação da implementação feita em sala, de forma que o último nó aponte para um nó sentinela, ao invés de para nulo. O campo "prox" da sentinela simplesmente não precisa ser preenchido: os percursos da lista devem terminar quando o nó sentinela for atingido.
*/

#include <iostream>

using namespace std;

typedef int TipoItem;

class DiconarioDuplaEncadeado
{
private:
    struct Noh{
        Noh *ante;
        int chave;
        TipoItem item;
        Noh *prox;
    };
    Noh *inicio;
    Noh *sentinela;
    

public:
    DiconarioDuplaEncadeado();
    ~DiconarioDuplaEncadeado();
    void inserir(int chave, TipoItem valor);
    void remover(int chave);
    void imprimir();
};

DiconarioDuplaEncadeado::DiconarioDuplaEncadeado()
{
    inicio = nullptr;
    sentinela = nullptr;
}

DiconarioDuplaEncadeado::~DiconarioDuplaEncadeado()
{
}

void DiconarioDuplaEncadeado::inserir(int chave, TipoItem valor){
    inicio = new Noh{inicio,chave,valor,sentinela};
    

}

int main(){




    return 0;
}