#include <iostream>

using namespace std;

typedef int TipoItem;

class Deque
{
private:
    struct Noh
    {
        Noh *ante;
        TipoItem valor;
        Noh *prox;
    };

    Noh *esquerda;
    Noh *direita;

public:
    Deque()
    {
        esquerda = nullptr;
        direita = nullptr;
    }
    ~Deque()
    {
        while (!vazio())
        {
            desenfilarDireita();
        }
    }

    void enfilarEsquerda(int valor)
    {
        Noh *novo = new Noh{nullptr, valor, esquerda};
        if (esquerda == nullptr)
        {
            direita = novo;
        }
        else
        {
            esquerda->ante = novo;
        }
        esquerda = novo;
        imprimir();
    }

    void enfilarDireita(int valor)
    {
        Noh *novo = new Noh{direita, valor, nullptr};
        if (vazio())
        {
            esquerda = novo;
        }
        else
        {
            direita->prox = novo;
        }
        direita = novo;
        imprimir();
    }

    void desenfilarDireita()
    {
        if (!vazio())
        {
            Noh *aux;
            aux = direita;
            direita = direita->ante;
            if (direita == nullptr)
            {
                esquerda = nullptr;
            }
            else
            {
                direita->prox = nullptr;
            }
            delete aux;
            imprimir();
        }
        else
        {
            cout << "Fila vazia" << endl;
        }
    }

    void desenfilarEsquerda()
    {
        if (!vazio())
        {
            Noh *aux;
            aux = esquerda;
            esquerda = esquerda->prox;
            if (esquerda == nullptr)
            {
                direita = nullptr;
            }
            else
            {
                esquerda->ante = nullptr;
            }
            delete aux;
            imprimir();
        }
        else
        {
            cout << "Fila vazia" << endl;
        }
    }

    bool vazio()
    {
        return (direita == nullptr && esquerda == nullptr);
    }

    void imprimir()
    {
        int tamanho = 0;
        if (!vazio())
        {
            Noh *aux = esquerda;
            cout << "[";
            while (aux != nullptr)
            {
                if (tamanho == 0)
                {
                    cout << aux->valor;
                }else{
                    cout << "," << aux-> valor;
                }
                aux = aux-> prox;
                tamanho++;
            }
            cout << "]" << endl;
            cout << "Tamanho da fila: " << tamanho << endl;
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
        Deque deque;
        do
        {
            cout << "Digite 1 para enfilar pela esquerda" << endl;
            cout << "Digite 2 para enfilar pela direita" << endl;
            cout << "Digite 3 para desenfilar pela esquerda" << endl;
            cout << "Digite 4 para desenfilar pela direita" << endl;
            cout << "Digite 5 para sair" << endl;

            cin >> escolha;
            if (escolha == 1)
            {
                cin >> valor;
                deque.enfilarEsquerda(valor);
            }
            else if (escolha == 2)
            {
                cin >> valor;
                deque.enfilarDireita(valor);
            }
            else if (escolha == 3)
            {
                deque.desenfilarEsquerda();
            }
            else if (escolha == 4)
            {
                deque.desenfilarDireita();
            }

        } while (escolha != 5);
    }
    catch (bad_alloc &e)
    {
        cout << "Alocação de memória mal executada" << endl;
        cerr << e.what() << '\n';
    }
    return 0;
}
