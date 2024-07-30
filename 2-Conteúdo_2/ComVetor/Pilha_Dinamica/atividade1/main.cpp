/*
Escreva uma implementação de pilha ilimitada, no sentido de que ela não deve possuir um limite conhecido a priori para o número de elementos passíveis de nela serem armazenados. Ao invés de um vetor de tamanho fixo, a "struct" deve possuir um ponteiro que, durante a execução da função de inicialização, deve receber um pequeno vetor alocado dinamicamente. Sempre que a função "empilhar" encontrar o vetor cheio, ela deve (1) alocar um vetor maior, (2) copiar para ele os elementos da pilha, (3) desalocar o vetor atual e (4) passar a utilizar o vetor maior como o vetor da pilha.

(Opcional) Com base na sintaxe ilustrada no programa abaixo para templates, reescreva a sua implementação de pilha do programa da questão anterior de forma que ela seja genérica quanto ao tipo. Em seguida, teste a sua implementação, criando e utilizando pilhas de diferentes tipos.
*/

#include <iostream>
using namespace std;

typedef int tipoItem;

class PilhaInfinita
{
private:
    int tamanho, limiteAtual;
    tipoItem *estrutura;

public:
    PilhaInfinita()
    {
        limiteAtual = 2; // Quando se tem o redimencionar para baixo o limite inicial deverá ser sempre 1 ou 2
        tamanho = 0;
        estrutura = new tipoItem[limiteAtual];
    }
    ~PilhaInfinita()
    {
        delete[] estrutura;
    }

    void adicionar(tipoItem item)
    {
        if (cheia())
        {
            redimencionar();
        }
        estrutura[tamanho] = item;
        tamanho++;
        cout << "Item " << item << " adicionado com sucesso" << endl;
        imprimir();
    }

    void redimencionar()
    {
        int limiteNovo = limiteAtual * 2;
        tipoItem *estrutura_nova = new tipoItem[limiteNovo];

        for (int i = 0; i < limiteAtual; i++)
        {
            estrutura_nova[i] = estrutura[i];
        }
        delete[] estrutura;
        limiteAtual = limiteNovo;
        estrutura = estrutura_nova;
    }
    void redimencionarAbaixo() // Opcional
    {
        int limiteNovo = limiteAtual / 2;
        tipoItem *estrutura_nova = new tipoItem[limiteNovo];
        for (int i = 0; i < limiteNovo; i++)
        {
            estrutura_nova[i] = estrutura[i];
        }
        delete[] estrutura;
        estrutura = estrutura_nova;
        limiteAtual = limiteNovo;
    }

    void removerRedimencionado() // Opcional
    {
        if (isvazio())
        {
            cout << "pilha vazia" << endl;
        }
        else
        {
            if (tamanho == limiteAtual * 0.25)
            {
                redimencionarAbaixo();
            }
            cout << "item" << estrutura[tamanho] << " removida com sucesso" << endl;
            tamanho--;
            imprimir();
        }
    }

    void remover()
    {
        if (isvazio())
        {
            cout << "pilha vazia" << endl;
        }
        else
        {
            cout << "item" << estrutura[tamanho] << " removida com sucesso" << endl;
            tamanho--;
            imprimir();
        }
    }

    bool cheia()
    {
        return tamanho == limiteAtual;
    }

    bool isvazio()
    {
        return tamanho == 0;
    }

    void imprimir()
    {
        cout << "Pilha: [";
        for (int i = 0; i < tamanho; i++)
        {
            cout << estrutura[i] << ", ";
        }
        cout << "]" << endl;
        cout << "Tamnho atual da pilha: " << limiteAtual << endl;
    }
};

int main()
{
    cout << "Bem-vindo a  pilha ilimitada" << endl;
    PilhaInfinita pilha;
    int escolha;
    tipoItem item;
    do
    {
        cout << "Digite 1 para adicionar" << endl;
        cout << "Digite 2 para remover" << endl;
        cout << "Digite 3 para imprimir" << endl;
        cin >> escolha;

        if (escolha == 1)
        {
            cout << "Digite um item para inserir" << endl;
            cin >> item;
            pilha.adicionar(item);
        }
        else if (escolha == 2)
        {
            // pilha.remover();
            pilha.removerRedimencionado();
        }
        else if (escolha == 3)
        {
            pilha.imprimir();
        }
        else
        {
            break;
        }

    } while (1);

    return 0;
}
