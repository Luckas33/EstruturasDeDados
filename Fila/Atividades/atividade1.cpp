///// Atividade 1, fazer uma fila sem usar o marcador u, somente p e n /////
/**
 * @author Lucas Sobral
 * @brief Escreva uma implementação alternativa de Fila Limitada via Vetor, na qual o índice do último seja substituído pela quantidade "n" de elementos presentes na fila. Os demais campos devem permanecer, de forma que os campos da nova implementação serão: "primeiro" (índice do primeiro elemento), "n" (quantidade de elementos correntemente armazenados) e "vetor" (vetor para os elementos da fila).
 * @bug Algoritmo incompleto, a função vazia está errada, como fazer o n detectar que esta vazia?
 */

#include <iostream>

using namespace std;

typedef int tipoItem;
const int Max_valor = 5;

class Fila
{
private:
    int p, n, c = 1;
    tipoItem *estrutura = new tipoItem[Max_valor];

public:
    Fila()
    {
        p = 0;
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
        }
        else if(c % 2 == 0 )
        {
            cout << "Item adicionado à fila: " << item << endl;
            estrutura[(p + n) % Max_valor] = item;
            n++;
        }
    }

    void desenfilar()
    {
        if (vazia())
        {
            cout << "Fila vazia" << endl;
        }
        else
        {
            cout << "Item removido: " << estrutura[p] << endl;
            p = (p + 1) % Max_valor;
            n--;
        }
    }
    void imprimir()
    {
        if (vazia())
        {
            cout << "Fila vazia" << endl;
        }
        else
        {

            int i = p;
            cout << "[ ";
            do
            {
                cout << estrutura[i] << " ";
                i = (i + 1) % Max_valor;
            } while (i != (p + n) % Max_valor);
            cout << " ]" << endl;
        }
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

    system("pause");
    return 0;
}