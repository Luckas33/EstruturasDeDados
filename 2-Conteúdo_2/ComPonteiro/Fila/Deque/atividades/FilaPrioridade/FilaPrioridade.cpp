#include <iostream>
#include "FilaPrioridade.h"
using namespace std;

typedef int tipoItem;

FilaPrioridade::FilaPrioridade()
{
    inicio = nullptr;
    final = nullptr;
}
FilaPrioridade::~FilaPrioridade()
{
    while (final != nullptr)
    {
        desenfilar();
    }
    
}
void FilaPrioridade::enfilar(tipoItem valor)
{
    Noh *novo = new Noh{valor, final};
    if (vazio())
    {
        inicio = novo;
    }
    else
    {
        final->prox = novo;
    }
    final = inicio;
    imprimir();
}
void FilaPrioridade::enfilarPrioridade(tipoItem valor)
{
    Noh *novo = new Noh{valor, inicio};
    if (vazio())
        return;
    inicio = novo;
    imprimir();
}
void FilaPrioridade::desenfilar()
{
    if (vazio())
        return;
    Noh *aux = inicio;
    inicio = inicio->prox;
    delete aux;
    imprimir();
}
void FilaPrioridade::imprimir()
{
    if (vazio())
        cout << "Fila vazia" << endl;
    return;
    Noh *aux = inicio;
    cout << "[";
    short i = 0;
    while (aux != nullptr)
    {
        if (i = 0)
            cout << aux->valor;
        else
            cout << "," << aux->valor;
        aux = aux->prox;
    }
    cout << "]";
}
bool FilaPrioridade::vazio()
{
    return inicio == nullptr ;
}