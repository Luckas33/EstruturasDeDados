#include <iostream>

using namespace std;

typedef int Tipoitem;

class FilaEncadeada
{
private:
    struct Noh
    {
        Tipoitem valor;
        Noh *prox;
    };
    Noh *inicio;
    Noh *fim;

public:
    FilaEncadeada()
    {
        inicio = nullptr;
        fim = nullptr;
    }
    ~FilaEncadeada()
    {
        while (inicio != nullptr)
        {
            desenfilar();
        }
    }

    void enfilar(Tipoitem valor)
    {
        Noh *novo = new Noh{valor, nullptr};
        if (vazio())
        {
            inicio = novo;
        }
        else
        {
            fim->prox = novo;
        }
        fim = novo;
        imprimir();
    }

    void desenfilar()
    {
        if (vazio())
        {
            cout << "Fila vazia" << endl;
        }
        else
        {
            Noh *aux = inicio;
            inicio = inicio->prox;
            delete aux;
            imprimir();
        }
    }

    bool vazio()
    {
        return inicio == nullptr;
    }

    void imprimir()
    {
        if (!vazio())
        {
            Noh *aux = inicio;
            int count = 0;
            cout << "[";
            while (aux != nullptr)
            {
                cout << " " << aux->valor;
                aux = aux->prox;
                count++;
            }
            cout << "]" << endl;
            cout << "Elementos na Fila: " << count << endl;
        }
        else
        {
            cout << "Fila vazia" << endl;
        }
    }
};

int main()
{
    try
    {
        int escolha, valor;
        FilaEncadeada fila;
        do
        {
            cout << "Digite 1 para enfilar" << endl;
            cout << "Digite 2 para desenfilar" << endl;
            cout << "Digite 3 para sair" << endl;
            cin >> escolha;
            if (escolha == 1)
            {
                cin >> valor;
                fila.enfilar(valor);
            }
            if (escolha == 2)
            {
                fila.desenfilar();
            }
        } while (escolha != 3);
    }
    catch (bad_alloc e)
    {
        cout << "Não foi possível alocar memória" << endl;
        std::cerr << e.what() << '\n';
    }
    return 1;
}