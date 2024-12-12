/**
 * @author Lucas
 * @brief Implemente em C++ um conjunto limitado via vetor ordenado, utilizando na função "pertence" o algoritmo de busca binária discutido em sala. Inclua as funções vazio e cheio.
 */
#include <iostream>
using namespace std;

typedef int TipoItem;
const int MaxItem = 10;

class Conjunto
{
private:
    int n;
    int *estrutura;

public:
    Conjunto();
    ~Conjunto();
    bool cheio();
    bool vazio();
    bool pertence(TipoItem item);
    void inserir_novo(TipoItem item);
    void inserir_se_novo(TipoItem item);
    void remover(TipoItem item);
    void imprimir();
};
Conjunto::Conjunto()
{
    n = 0;
    estrutura = new TipoItem[MaxItem];
}
Conjunto::~Conjunto()
{
    delete[] estrutura;
}
bool Conjunto::cheio()
{
    return (n == MaxItem);
}
bool Conjunto::vazio()
{
    return (n == 0);
}
bool Conjunto::pertence(TipoItem item)
{
    int i = 0, f = n - 1;
    while (i <= f)
    {
        int m = (i + f) / 2;
        if (item == estrutura[m])
            return true;
        if (item < estrutura[m])
            f = m - 1;
        else
            i = m + 1;
    }
    return false;
}

void Conjunto::inserir_se_novo(TipoItem item)
{
    if (pertence(item))
    {
        cout << "Item ja existente" << endl;
    }
    else
    {
        inserir_novo(item);
    }
}
void Conjunto::inserir_novo(TipoItem item)
{
    if (cheio())
    {
        cout << "Conjunto cheio" << endl;
    }
    else if (vazio())
    {
        estrutura[n] = item;
        n++;
        cout << "Item inserido com sucesso: " << item << endl;
    }
    else
    {
        int i = 0, j;
        for (i = 0; i < n; i++, j++)
        {
            if (item < estrutura[i])
                break;
        }
        for (j = n; j > i; j--)
        {
            estrutura[j] = estrutura[j - 1];
        }
        estrutura[j] = item;
        cout << "Item inserido com sucesso: " << item << endl;
        n++;
    }
}

void Conjunto::remover(TipoItem item)
{
    if (vazio())
    {
        cout << "Conjunto vazio" << endl;
    }
    else
    {
        if (pertence(item))
        {
            int i = 0;
            for (i = 0; i <= n; i++)
            {
                if (estrutura[i] == item)
                {
                    for (; i < n; i++)
                    {
                        estrutura[i] = estrutura[i + 1];
                    }
                    n--;
                    break;
                }
            }
        }
        else
        {
            cout << "Item invalido" << endl;
        }
    }
}
void Conjunto::imprimir()
{
    if (vazio())
    {
        cout << "Conjunto vazio" << endl;
    }
    else
    {
        cout << "Conjunto: [ ";
        for (int i = 0; i < n; i++)
        {
            cout << estrutura[i] << " ";
        }
        cout << "] " << endl;
    }
}

int main()
{
    int opcao;
    TipoItem item;
    Conjunto conjt1;
    do
    {
        cout << "Digite 1 para adicionar um item ao conjunto" << endl;
        cout << "Digite 2 para remover um item do conjunto" << endl;
        cout << "Digite 3 para imprimir um item do conjunto" << endl
             << endl;
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Digite o item que deseja inserir" << endl;
            cin >> item;
            conjt1.inserir_se_novo(item);
        }
        else if (opcao == 2)
        {
            cout << "Digite o item que deseja excluir" << endl;
            cin >> item;
            conjt1.remover(item);
        }
        else if (opcao == 3)
        {
            conjt1.imprimir();
        }
        else
        {
            break;
        }

    } while (opcao != 0);
    return 0;
}
