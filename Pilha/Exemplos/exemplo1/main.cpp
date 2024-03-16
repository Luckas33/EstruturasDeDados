#include <iostream>
#include <string>
#include "pilha.h"

using namespace std;


int main()
{
    pilha pilha1;
    TipoItem item;
    short resposta;

    do
    {

        cout << "\n\nvoce deseja inserir ou tirar itens da pilha?" << endl;
        cout << "Digite 1 para inserir e 2 para remover ou 3 para sair" << endl;
        
        cin >> resposta;

        if (resposta == 1)
        {
            cout << "Digite um elemento: " << endl;
            cin >> item;
            pilha1.inserir(item);
        }
        else if (resposta == 2)
        {
            pilha1.remover();
        }else{
            cout << "Encerrando escolhas. . ." << endl;
            break;
        }
    }while(resposta != 0);

    cout << "Elementos da pilha: " << endl;
    pilha1.imprimir();

    cout << "Tamanho total: " << pilha1.obterTamanho() << endl;

    system("pause");
    return 0;
}