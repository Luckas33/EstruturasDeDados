#include <iostream>

using namespace std;

typedef string item;

class Dicionario
{
    struct Noh
    {
        int chave;
        item valor;
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

public:
    Noh *inicio;

    Dicionario()
    {
        inicio = nullptr;
    }

    ~Dicionario()
    {
        Noh *n = inicio;
        while (inicio != nullptr)
        {
            inicio = inicio->prox;
            delete n;
            n = inicio;
        }
    }
    void inserir(int chave, item valor)
    {
        inicio = new Noh{chave, valor, inicio};
        imprimir();
        // novo -> chave = chave;
        // novo -> valor = valor;
        // novo->prox = inicio;
        // inicio = novo;
    }

    void inserir_se_novo(int chave, item valor)
    {
        ResConsulta r = consultar(chave);
        if (not r.achou)
        {
            inserir(chave, valor);
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
            imprimir();
            return;
        }
        while (n->prox != nullptr)
        {
            if (n->prox->chave == chave)
            {
                Noh *p = n->prox;
                n->prox = p->prox;
                delete p;
                return;
            }
            n = n->prox;
        }
    }
    void imprimir()
    {
        int count = 0;
        Noh *aux = inicio;
        cout << "[";
        while (aux != nullptr)
        {
            cout << " " << aux->chave;
            aux = aux->prox;
            count++;
        }
        cout << " ]" << endl;

        cout << "Elementos no dicionário: " << count << endl;
    }
};

int main()
{
    int escolha;
    Dicionario dic;
    int chave;
    item valor;
    try
    {
        do
        {
            cout << "Digite 1 para inserir" << endl;
            cout << "Digite 2 para desempilhar" << endl;
            cout << "Digite 3 para consultar o valor de uma chave" << endl;
            cout << "Digite 4 para sair" << endl;
            cin >> escolha;
            if (escolha == 1)
            {
                cout << "Digite a chave e o valor" << endl;
                cin >> chave;
                cin >> valor;
                dic.inserir_se_novo(chave, valor);
            }
            if (escolha == 2)
            {
                cout << "Digite a chave e o valor para remover" << endl;
                cin >> chave;
                dic.remover(chave);
            }
            if (escolha == 3)
            {
                /*
                cout << "Digite a chave para saber o seu valor" << endl;
                cin >> chave;
                Dicionario::ResConsulta resultado = dic.consultar(chave);
                if (resultado.achou)
                {
                    cout << "Valor: " << resultado.valor << endl;
                }
                else
                {
                    cout << "Chave não encontrada" << endl;
                }
                */
            }
        } while (escolha != 4);
    }
    catch (bad_alloc e)
    {
        cout << "Não foi possível alocar memória" << endl;
    }

    return 0;
}