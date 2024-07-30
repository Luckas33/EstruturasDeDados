/**
 * @author Lucas
 * @brief Conjunto desordenado
 * @example vantagem: remover mais eficiente // desavantagem: nao tem busca binária
*/

#include <iostream>
using namespace std;

typedef int TipoItem;
const int Max_Itens = 10;

class Conjunto
{
private:
    TipoItem *estrutura;
    int n;

public:
    Conjunto();
    ~Conjunto();
    bool pertence(TipoItem x);
    void inserir_novo(TipoItem x);
    void inserir_se_novo(TipoItem x);
    void remover(TipoItem x);
    void imprimir();
};

Conjunto::Conjunto()
{
    estrutura = new TipoItem[Max_Itens];
    n = 0;
}
Conjunto::~Conjunto()
{
    delete[] estrutura;
}
bool Conjunto::pertence(TipoItem x)
{
    for (int i = 0; i < n; i++)
    {
        if (estrutura[i] == x)
        {
            return true;
        }
    }
    return false;
}
void Conjunto::inserir_novo(TipoItem x)
{
    if (n == Max_Itens)
    {
        cout << "Conjunto cheio" << endl;
    }
    else
    {
        estrutura[n] = x;
        n++;

        cout << "Item inserido com sucesso: " << x << endl;
    }
}
void Conjunto::inserir_se_novo(TipoItem x)
{
    if (pertence(x))
    {
        cout << "Item ja existente" << endl;
    }
    else
    {
        inserir_novo(x);
    }
}
void Conjunto::remover(TipoItem x)
{
    if (n == 0)
    {
        cout << "Conjunto vazio" << endl;
    }
    else if (pertence(x))
    {
        for (int i = 0; i < n; i++)
        {
            if (estrutura[i] == x)
            {
                estrutura[i] = estrutura[n - 1];
                n--;
                break;
            }
        }
    }
    else
    {
        cout << "Conjunto nao pertence" << endl;
    }
}
void Conjunto::imprimir()
{
    cout << "Conjunto: [ ";
    for (int i = 0; i < n; i++)
    {
        cout << estrutura[i] << " ";
    }
    cout << "] " << endl;
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