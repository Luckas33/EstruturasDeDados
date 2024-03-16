/**
 *
 * @attention Escreva uma variação do algoritmo de busca binária que, ao invés de informar se o elemento "x" está ou não presente, informe a posição em que o elemento deveria ser inserido; essa posição é aquela imediatamente após o último dos elementos menores que "x" (caso haja; se não houver nenhum menor, a posição é zero). Naturalmente, essa versão alternativa do algoritmo não tem como propósito ser usada na função "pertence" de uma implementação de conjunto; no caso, o intuito seria aproveitá-la para realizar uma versão um pouco mais eficiente da função de inserção, que usaria busca binária no lugar de busca linear para descobrir o local onde o elemento deve ser inserido.
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
    int posicaoInserir(TipoItem item);
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

int Conjunto::posicaoInserir(TipoItem item)
{
    if(vazio()){
        return 0;
    }
    int i = 0, f = n - 1;
    if(item < estrutura[0]) return 0;
    
    while (i <= f)
    {
        int m = (i + f) / 2;
        if (item == estrutura[m])
            return m;
        if (item < estrutura[m])
            f = m - 1;
        else
            i = m + 1;
    }
    return i;
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
