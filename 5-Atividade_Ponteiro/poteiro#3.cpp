/*
Implementar um procedimento de remoção em lista simplesmente encadeada que não necessite testar se o nó removido é o primeiro da lista (sendo portanto apontado pelo ponteiro inicial da lista) ou se não é (nesse caso sendo apontado pelo campo "prox" do nó anterior).
*/
#include <iostream>

struct Noh
{
    Noh *prox;
    int valor;
};
Noh *inicio;

class Lista
{
private:
    
public:
    Lista(){
        inicio = nullptr;
    }
    ~Lista();
    void inserir(int item){
        Noh *n = new Noh{inicio,item};
        inicio = n; 
    }
    void remover(int item){
        Noh *n = inicio;
        Noh **anterior = &inicio;
        while (n != nullptr)
        {
            if (n->valor == item)
            {
             break;  
            }
            anterior = &n->prox;
            n = n->prox;
        }
        *anterior = n->prox;
        delete n;
    }
};


int main(){



    return 0;
}