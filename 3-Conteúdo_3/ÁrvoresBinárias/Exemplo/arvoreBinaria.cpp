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

    void destruir(Noh *n){
        if(n == nullptr) return;

        destruir(n -> FilhoEsq);
        destruir(n -> FilhoDir);
        delete n;
    }

public:
    Noh *Raiz;

    ArvoreBinaria()
    {
        Raiz = nullptr;
    }
    ~ArvoreBinaria(){
        while (vazio())
        {
            destruir(Raiz);
        }
        
    }

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
        if (vazio()){
            cout << "Arvore Vazia" << endl;
            return false;
        }
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
    void remover(Valoritem item) // Avançado
    {
        if (vazio())
            return;
        if (!pertence(item))
            return;
        Noh *aux1 = Raiz;
        Noh **pai = &Raiz;
        while (1)
        {
            if (item == aux1->item) // Achou
            {
                break;
            }
            else
            {

                if (item < aux1->item)
                {
                    pai = &aux1 ->FilhoEsq; 
                    aux1 = aux1->FilhoEsq;
                }

                if (item > aux1->item)
                {
                    pai = &aux1 ->FilhoDir;
                    aux1 = aux1->FilhoDir;
                }
            }
        }
        if (aux1->FilhoEsq == nullptr) // Nó com 1 filho ou com nenhum
        {
            *pai = aux1->FilhoDir;
            // TODO delete aux1;
        }else if (aux1->FilhoDir == nullptr) // Nó com 1 filho ou com nenhum
        {
            *pai = aux1->FilhoEsq;
        }
        else // Nó com 2 filhos
        {
            Noh* aux2 = aux1 -> FilhoEsq;
            Noh** pai2 = &aux2;
            while(aux2 != nullptr)
            {
                pai2 = &aux2->FilhoDir;
                aux2 = aux2->FilhoDir;
            }
            *pai = aux2;
            aux2->FilhoDir = aux1->FilhoDir;
            aux2->FilhoEsq = aux1->FilhoEsq;
            *pai2 = aux2->FilhoEsq;
        }
        delete aux1;
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
            if(arvore.vazio()){
                cout << "arvore vazia" << endl;
                break;
            }
            cout << "Digite um item a remover" << endl;
            cin >> item;
            arvore.remover(item);
        }
        else if (escolha == 3)
        {
            if(arvore.vazio()){
                cout << "Arvore vazia" << endl;
                break;  
            }
            arvore.imprimir(arvore.Raiz);
        }
        else
        {
            escolha = 4;
        }

    } while (escolha != 4);

    return 0;
}
