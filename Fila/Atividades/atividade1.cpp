#include <iostream>

using namespace std;

typedef int tipoItem;
const int Max_valor = 5;

class Fila
{
private:
    int p, n;
    tipoItem *estrutura = new tipoItem[Max_valor];

public:
    Fila()
    {
        p = 0; // Inicialmente o primeiro elemento está na posição 0
        n = 0;
    }

    ~Fila()
    {
        delete[] estrutura;
    }

    bool vazia()
    {
        return (n == 0);
    }

    bool cheia()
    {
        return (n == Max_valor);
    }

    void inserir(tipoItem item)
    {
        if (cheia())
        {
            cout << "Fila cheia" << endl;
            return;
        }

        int posicao = (p + n) % Max_valor; // Calcula a posição correta para inserir
        estrutura[posicao] = item;
        n++;
    }

    void desenfilar()
    {
        if (vazia())
        {
            cout << "Fila vazia" << endl;
            return;
        }

        p = (p + 1) % Max_valor; // Atualiza o marcador para o próximo elemento
        n--;
    }

    void imprimir()
    {
        if (vazia())
        {
            cout << "Fila vazia" << endl;
            return;
        }

        cout << "[ ";
        for (int i = 0; i < n; i++)
        {
            int posicao = (p + i) % Max_valor; // Calcula a posição correta para imprimir
            cout << estrutura[posicao] << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    Fila fila1;
    int opcao;
    tipoItem item;

    do
    {
        cout << "Digite: \n1 para Adicionar um item\n2 para desenfilar um item\n3 para Sair " << endl;
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Digite o item: ";
            cin >> item;
            fila1.inserir(item);
            fila1.imprimir();
        }
        else if (opcao == 2)
        {
            fila1.desenfilar();
            fila1.imprimir();
        }
        else if (opcao == 3)
        {
            break;
        }
    } while (opcao != 0);

    return 0;
}
