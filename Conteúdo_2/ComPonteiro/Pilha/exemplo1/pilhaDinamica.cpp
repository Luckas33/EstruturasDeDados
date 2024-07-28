#include "pilhaDinamica.h"
#include <iostream>
#include <cstddef> //NULL

using namespace std;

pilhaDinamica::pilhaDinamica()
{
    NoTopo = NULL;
}

pilhaDinamica::~pilhaDinamica()
{
    No* Notemp;
    while (NoTopo != NULL)
    {
        Notemp = NoTopo;
        NoTopo = NoTopo->proximo;
        delete Notemp;
    }
    
}

bool pilhaDinamica::estaVazio()
{
    return (NoTopo == NULL);
}

bool pilhaDinamica::estaCheio()
{

    No *NoNovo;
    try
    {
        NoNovo = new No;
        delete NoNovo;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

void pilhaDinamica::inserir(TipoItem item)
{
    if (estaCheio())
    {
        cout << "Pilha cheia" << endl;
    }
    else
    {
        No *NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->proximo = NoTopo;
        NoTopo = NoNovo;
    }
}
TipoItem pilhaDinamica::remover()
{
    if (estaVazio())
    {
        cout << "Pilha vazia" << endl;
        return 0;
    }
    else
    {
        No *NoTemp;
        NoTemp = NoTopo;
        TipoItem item = NoTopo->valor;
        NoTopo = NoTopo->proximo;
        delete NoTemp;
        return item;
    }
}
void pilhaDinamica::imprimir()
{
    No* Notemp = NoTopo;
    cout << "Pilha: [ ";

    while(Notemp != NULL){
        cout << Notemp->valor << " ";
        Notemp = Notemp->proximo;
    }
    cout << "]"<< endl;
}