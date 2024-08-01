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
    ~Pilha()
    {
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
            imprimir();
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
        int count = 0;
        if (!vazia())
        {
            Noh *aux = topo;
            cout << "[";
            while (aux != nullptr)
            {
                cout << " " << aux->valor;
                aux = aux->proximo;
                count++;
            }
            cout << "]" << endl;
            if (count == 0)
            {
                cout << "Pilha ficou vazia" << endl;
            }

            cout << "Elementos na Pilha: " << count << endl;
        }
        
    }
};

int main()
{
    int escolha;
    item valor;
    Pilha pilha;
    try
    {
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
            }
            if (escolha == 2)
            {
                pilha.desempilhar();
            }

        } while (escolha != 3);
    }
    catch (bad_alloc)
    {
        cout << "Não foi possível alocar memória" << endl;
    }
    return 2;
}