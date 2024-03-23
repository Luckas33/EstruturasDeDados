//// Feito por mim Lucas////
#include <iostream>
#include <stdlib.h>
#include "Fila.h"

using namespace std;

int main(){
    Fila fila1;
    short resposta;
    TipoItem item;
    do
    {
        cout << "Digite 1 para adicionar elementos a fila" << endl;
        cout << "Digite 2 para tirar elementos da fila " << endl;
        cout << "Digite 3 para sair" << endl;
        cin  >> resposta;

        if(resposta == 1){
            cout << "Numero: ";
            cin >> item;
            fila1.inserir(item);
            fila1.imprimir();
        }else if (resposta ==  2)
        {
            fila1.desenfilar();
            fila1.imprimir();
        }else if(resposta == 3){
            break;
        }

    } while (resposta != 0);
    
    fila1.imprimir();

    cin >> resposta;

    system("pause");
    return 0;
}