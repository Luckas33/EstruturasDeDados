#include <iostream>

using namespace std;

class Dicionario
{
    struct Noh
    {
        int chave;
        char valor;
        Noh *prox;
    };

    struct ResConsulta
    {
        bool achou;
        string valor;
    };

    ResConsulta consultar(int c)
    {
        ResConsulta ret;
        Noh *n = inicio;
        while (n != nullptr)
        {
            if (n->chave == c)
            {
                ret.achou = true;
                ret.valor = n->valor;
                return ret;
            }
            n = n->prox;
        }
        ret.achou = false;
        return ret;
    }

    Noh *inicio;

public:
    Dicionario()
    {
        inicio = nullptr;
    }

    ~Dicionario(){
       Noh *n = inicio;
       while (inicio != nullptr)
       {
        inicio = inicio -> prox;
        delete n;
        n = inicio;
       }
        
    }
    void inserir(int chave, char valor)
    {
        inicio = new Noh{chave, valor, inicio};
        // novo -> chave = chave;
        // novo -> valor = valor;
        // novo->prox = inicio;
        // inicio = novo;
    }

    void inserir_se_novo(int c, char valor)
    {
        ResConsulta r = consultar(c);
        if (not r.achou)
        {
            inserir(c, valor);
        }
    }
    void remover(int chave)
    {

        Noh *n = inicio;
        if (n == nullptr)
            return;
        if (n->chave == chave)
        {
            inicio = inicio->prox;
            delete n;
            return;
        }
        while (n -> prox != nullptr)
        {
            if (n->prox->chave == chave)
            {
                Noh *p = n->prox;
                n->prox = p->prox;
                delete p;
                return;
            }
            n = n ->prox;
        }
    }
};

int main()
{
    
    return 0;
}