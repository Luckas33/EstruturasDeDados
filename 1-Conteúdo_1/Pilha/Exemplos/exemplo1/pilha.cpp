#include "pilha.h"
#include <iostream>

using namespace std;

pilha::pilha() // Construtor
{
    tamanho = 0;
    estrutura = new TipoItem[max_itens];
}

pilha::~pilha() // Destrutor
{
    delete[] estrutura;
}

bool pilha::isFull() // Verifica se a pilha está cheia
{
    return (tamanho == max_itens);
}

bool pilha::isEmpty() // Verifica se a pilha está vazia
{
    return (tamanho == 0);
}

void pilha::inserir(TipoItem item)
{
    if (isFull())
    {
        cout << "A pilha está cheia" << endl;
    }
    else
    {
        cout << "elemento inserido com sucesso: " << item << endl;
        estrutura[tamanho] = item;
        tamanho++;
    }
}

TipoItem pilha::remover()
{
    if (isEmpty())
    {
        cout << "A pilha está vazia" << endl;
        return 0; // ou um valor padrão para TipoItem
    }
    else
    {
        tamanho--;
        cout << "Elemento removido: " << estrutura[tamanho] << endl;
        return estrutura[tamanho];
    }
}

void pilha::imprimir()
{
    cout << "Pilha: [";
    for (int i = 0; i < tamanho; i++)
    {
        cout << estrutura[i] << " ";
    }
    cout << " ]\n";
}

int pilha::obterTamanho()
{
    return tamanho;
}
