#include <iostream>
#include "pilhaDinamica.h"
using namespace std;

int main(){
    pilhaDinamica pilha1;
    TipoItem item;
    short resposta;

    do
    {

        cout << "\n\nvoce deseja inserir ou tirar itens da pilha?" << endl;
        cout << "Digite 1 para inserir e 2 para remover ou 3 para imprimir" << endl;
        
        cin >> resposta;

        if (resposta == 1)
        {
            cout << "Digite um elemento: " << endl;
            cin >> item;
            pilha1.inserir(item);
            pilha1.imprimir();
        }
        else if (resposta == 2)
        {
            pilha1.remover();
            cout << "Elemento Removido " << item << endl;
            pilha1.imprimir();
        }else if(resposta == 3){
            pilha1.imprimir();
        }
        else{
            cout << "Encerrando escolhas. . ." << endl;
            break;
        }
    }while(resposta != 0);

    cout << "Elementos da pilha: " << endl;
    pilha1.imprimir();

    system("pause");
    return 0;
}