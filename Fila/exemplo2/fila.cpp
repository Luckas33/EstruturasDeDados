#include <iostream>
#include "fila.h"

using namespace std;

fila::fila(){
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[MAX_ITENS];
}
fila::~fila(){
    delete[] estrutura;
}
bool fila::estaVazio(){
    return(primeiro == ultimo);
}
bool fila::estaCheio(){
    return(ultimo - primeiro == MAX_ITENS);
}
void fila::inserir(TipoItem item){
    if(estaCheio()){
        cout << "A fila esta cheia" << endl;
    }else{
        estrutura[ultimo % MAX_ITENS] = item;
        ultimo++;
    }
}
TipoItem fila::remover(){
    if(estaVazio()){
        cout << "A fila esta vazia" << endl;
        return 0;
    }else{
        cout << "Item removido: " << estrutura[primeiro] << endl;
        primeiro++;
        return estrutura[(primeiro - 1) % MAX_ITENS];
    }
}
void fila::imprimir(){
    cout << "Fila: [";
    for ( int i = primeiro; i < ultimo; i++)
    {
        cout << estrutura[i % MAX_ITENS] << " ";
    }
    cout << "]";
}