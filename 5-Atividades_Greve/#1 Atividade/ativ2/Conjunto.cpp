#include <iostream>
#include "Conjunto.h"

const int Tam_Max = 10;
typedef int TipoItem;

Conjunto::Conjunto(){
    estrutura = new TipoItem[Tam_Max];
    n = 0;
}
Conjunto::~Conjunto(){
    delete[] estrutura;
}
void Conjunto::inserir(TipoItem item){
    if(cheio()){
        cout << "Conjunto cheio" << endl;
    }else{
        cout << "Item inserido" << endl;
        estrutura[n] = item;
        n++;
    }
}
bool Conjunto::vazio(){
    return n == 0;
}
bool Conjunto::cheio(){
    return n == Tam_Max;
}