#include <iostream>

using namespace std;

typedef int TipoItem;

class Deque
{
private:
    struct Noh
    {
        Noh *prox;
        TipoItem valor;
        Noh *ante;
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
        if (vazio)
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
            }else{
                direita->prox = nullptr;
            }
            delete aux;
            imprimir();
        }
        else
        {
            cout << "nao deu" << endl;
        }
    }

    void desenfilarEsquerda(){
        if (!vazio())
        {
            Noh *aux;
            aux = esquerda;
            esquerda = esquerda -> prox;
            if (esquerda == nullptr)
            {
                direita = nullptr;
            }else{
                esquerda -> ante = nullptr;
            }
            delete aux;
            imprimir();
        }else{
            printf("nao deu");
        }
    }

    bool vazio()
    {
        return direita == nullptr && esquerda == nullptr;
    }

    void imprimir()
    {
        if(!vazio){

        }
    }
};

int main()
{
    try
    {
        
    }
    catch(bad_alloc e)
    {
        cout << "Alocação de memória mal executada" << endl;
        std::cerr << e.what() << '\n';
    }
    return 0;
}