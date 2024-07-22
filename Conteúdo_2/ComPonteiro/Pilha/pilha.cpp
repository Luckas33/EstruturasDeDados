#include <iostream>

using namespace std;

typedef int item;

class Pilha
{
    struct Noh
    {
        item valor;
        Noh *proximo;
    };
    Noh *topo;

public:
    Pilha()
    {
        topo = nullptr;
    }
    ~Pilha(){
        while (topo != nullptr)
        {
            desempilhar();
        }
        
    }
    void empilhar(item valor)
    {
        topo = new Noh{valor, topo};
        imprimir();
    }
    void desempilhar()
    {
        if (!vazia())
        {
            Noh *aux = topo;
            topo = topo->proximo;
            delete aux;
            return;
        }
        cout << "Pilha vazia" << endl;
    }
    bool vazia()
    {
        return topo == nullptr;
    }
    void imprimir()
    {
        if (!vazia())
        {
            Noh *aux = topo;
            while (aux != nullptr)
            {
                cout << " " << aux->valor;
                aux = aux->proximo;
            }
        }
    }
};

int main()
{
    int escolha;
    item valor;
    Pilha pilha;
    do
    {
        cout << "Digite 1 para inserir" << endl;
        cout << "Digite 2 para desempilhar" << endl;
        cout << "Digite 3 para sair" << endl;
        cin >> escolha;
        if (escolha == 1)
        {
            cin >> valor;
            pilha.empilhar(valor);
            //pilha.imprimir();
        }
        if (escolha == 2)
        {
            pilha.desempilhar();
            pilha.imprimir();
        }
        else
        {
            break;
        }

    } while (escolha != 3);
    return 2;
}