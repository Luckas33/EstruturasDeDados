// Árvore Binária de busca
// Sem tratamento de balanceamento

#include <iostream>
using namespace std;

typedef int Valoritem;

class ArvoreBinaria
{
private:
    struct Noh
    {
        Noh *FilhoEsq;
        Valoritem item;
        Noh *FilhoDir;
    };

public:
    Noh *Raiz;

    ArvoreBinaria()
    {
        Raiz = nullptr;
    }
    ~ArvoreBinaria();

    void inserir(Valoritem item) // Sempre adicionará no fim da árvore
    {
        Noh *NovoNoh = new Noh{nullptr, item, nullptr};
        Noh *procurar = Raiz;
        if (Raiz == nullptr) // Caso 1, Árvore vazia
        {
            Raiz = NovoNoh;
            return;
        }
        // Caso 2, Árvore não vazia
        while (1)
        {
            if (item < procurar->item) // Descendo pela esquerda
            {
                if (procurar->FilhoEsq == nullptr) // Quando chega no fim da árvore
                {
                    procurar->FilhoEsq = NovoNoh;
                    return;
                }
                else
                {
                    procurar = procurar->FilhoEsq;
                }
            }
            else if (item > procurar->item) // Descendo pela direita
            {
                if (procurar->FilhoDir == nullptr) // Quando chega ao final da árvore
                {
                    procurar->FilhoDir = NovoNoh;
                    return;
                }
                else
                {
                    procurar = procurar->FilhoDir;
                }
            }
        }
    }
    bool pertence(Valoritem item)
    {
        if (vazio())
            cout << "Arvore Vazia" << endl;
        return;
        Noh *procurar = Raiz;
        while (1)
        {
            if (item == procurar->item)
            {
                return true;
            }
            else
            {
                if (item < procurar->item)
                {
                    procurar = procurar->FilhoEsq;
                }
                else
                {
                    procurar = procurar->FilhoDir;
                }
            }
        }
    }
    // Terão 3 casos onde, remover folha, remover um nó com um filho e revomer um nó com 2 filhos
    void remover(Valoritem item) // principiante
    {
        if (vazio()) return;
        if (!pertence(item)) return;
        Noh* aux1 = Raiz;
        



    }
    void imprimir(Noh *n)
    {
        if (n != nullptr)
        {
            imprimir(n->FilhoEsq);
            cout << n->item << endl;
            imprimir(n->FilhoDir);
        }
    }

    bool vazio()
    {
        return Raiz == nullptr;
    }
};

int main()
{
    int escolha;
    ArvoreBinaria arvore;

    do
    {
        cout << "Digite 1 para inserir" << endl;
        cout << "Digite 2 para remover" << endl;
        cout << "Digite 3 para imprimir a árvore" << endl;
        cout << "Digite 4 para sair" << endl;
        cin >> escolha;
        int item;
        if (escolha == 1)
        {
            cout << "Digite um item para adicionar" << endl;
            cin >> item;
            arvore.inserir(item);
        }
        else if (escolha == 2)
        {
            cout << "Digite um item a remover" << endl;
            cin >> item;
            arvore.remover(item);
        }
        else if (escolha == 3)
        {
            //arvore.imprimir();
        }
        else
        {
            escolha = 4;
        }

    } while (escolha != 4);

    return 0;
}
