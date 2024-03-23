///// Exemplo de Douglas Maioli /////
#include <iostream>
#include "fila.h"
#include <stdlib.h>

using namespace std;

int main(){
    fila fila1;
    int opcao;
    TipoItem item;

    do
    {
        cout << "Digite 0 para parar o programa" << endl;
        cout << "Digite 1 para inserir um elemento" << endl;
        cout << "Digite 2 para excluir um elemento" << endl;
        cout << "Digite 3 para imprimir a fila" << endl;
        cin >> opcao;

        if(opcao == 1){
            cout << "Digite o elemento a ser inserido na fila\n";
            cin >> item;
            fila1.inserir(item);
        }else if(opcao == 2){
            fila1.remover();
        }else if(opcao == 3){
            fila1.imprimir();
        }else{
            break;
        }

    } while (opcao != 0);
    

    system("pause");
    return 0;
}