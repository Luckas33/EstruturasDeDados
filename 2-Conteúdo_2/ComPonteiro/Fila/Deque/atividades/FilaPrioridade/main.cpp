/*
Considere uma variação do TAD fila em que, além de remoção no início e inserção no final, seja possível também inserir no início; você pode imaginar, por exemplo, que a inserção no início seria utilizada esporadicamente, para adicionar elementos com prioridade máxima. Implemente então essa variação da fila usando lista simplesmente encadeada.
*/
#include <iostream>
#include "FilaPrioridade.h"
using namespace std;

typedef int tipoItem;

int main()
{
    try
    {
        FilaPrioridade fila;
        short escolha;
        int valor;
        do
        {
            cout << "Digite 1 para enfilar" << endl;
            cout << "Digite 2 para enfilar com Prioridade" << endl;
            cout << "Digite 3 para desenfilar" << endl;
            cout << "Digite 4 para sair" << endl;

            cin >> escolha;
            if (escolha == 1)
            {
                cin >> valor;
                fila.enfilar(valor);
            }
            if (escolha == 2)
            {
                cin >> valor;
                fila.enfilarPrioridade(valor);
            }
            if (escolha == 3)
            {
                fila.desenfilar();
            }
        } while (escolha != 4);
    }
    catch (bad_alloc e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}