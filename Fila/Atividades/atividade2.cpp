/**
 * @name Atividade 2
 * @author Lucas Sobral
 * @brief Escreva uma implementação alternativa de Fila Limitada, com capacidade para até 10 elementos armazenados simultaneamente, que utilize 2 vetores de 5 elementos. (Utilizar um único vetor de 10 elementos seria provavelmente mais simples, mas a proposta deste exercício é viabilizar a implementação num contexto em que algumas restrições sobre a memória disponível fossem estabelecidas previamente à implementação da estrutura.)
 */
#include <iostream>

using namespace std;

const int Max_Itens = 10;
typedef int Tipo_Var; // Tipo_var == int

class Fila
{
private:
    // Atributos //
    int p, u, n, count;
    Tipo_Var *estrutura1;
    Tipo_Var *estrutura2;

public:
    // Declaração dos Métodos //
    Fila();  // Construtor
    ~Fila(); // Destrutor
    void inserir(Tipo_Var item);
    void desenfilar();
    bool cheio();
    bool vazio();
    void imprimir();
};

// Implementtação dos Métodos //
Fila::Fila()
{
    p = 0, u = 0, n = 0, count = 0;
    estrutura1 = new Tipo_Var[Max_Itens / 2];
    estrutura2 = new Tipo_Var[Max_Itens / 2];
}

Fila::~Fila()
{
    delete[] estrutura1;
    delete[] estrutura2;
}

bool Fila::cheio()
{
    return (n == Max_Itens);
}
bool Fila::vazio()
{
    return (n == 0);
}
void Fila::inserir(Tipo_Var item)
{
    if (cheio())
    {
        cout << "Fila cheia" << endl;
    }
    else
    {
        if (n < Max_Itens / 2)
        {
            estrutura1[u] = item;
            u = (u + 1) % (Max_Itens / 2);
        }
        else
        {
            estrutura2[u] = item;
            u = (u + 1) % (Max_Itens / 2);
        }
        n++;
        cout << "Item adicionado: " << item << endl;
    }
}

void Fila::desenfilar()
{
    if (vazio())
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        p = (p + 1) % (Max_Itens / 2); // Atualiza o marcador para o próximo elemento
        n--;
    }
}
void Fila::imprimir()
{
    if (vazio())
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        cout << "Fila: [";

        // Imprime os elementos da estrutura1
        for (int i = p; i < p + n && i < Max_Itens / 2; i++)
        {
            cout << estrutura1[i % (Max_Itens / 2)] << " ";
        }

        // Imprime os elementos da estrutura2
        for (int i = 0; i < n - (Max_Itens / 2) && i < Max_Itens / 2; i++)
        {
            cout << estrutura2[i] << " ";
        }

        cout << "]" << endl;
    }
}


int main()
{

    Fila fila1;
    int opcao, item;

 
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