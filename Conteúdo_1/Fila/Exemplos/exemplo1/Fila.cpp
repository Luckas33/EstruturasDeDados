#include <iostream>
#include "Fila.h"

using namespace std;
int observador = 0;

Fila::Fila() {
    p = 0;
    u = 0;
    estrutura = new TipoItem[max_itens];
}

Fila::~Fila() {
    delete[] estrutura;
}

void Fila::inserir(TipoItem item) {
    if (isFull()) {
        cout << "A fila está cheia" << endl;
    } else {
        estrutura[u] = item;
        cout << "Elemento adicionado com sucesso: [" << estrutura[u] << "]" << endl;
        u = (u + 1) % max_itens;
        observador++;
    }
}

void Fila::desenfilar() {
    if (isEmpty()) {
        cout << "Fila vazia" << endl;
    } else {
        observador--;
        cout << "Elemento removido com sucesso: [" << estrutura[p] << "]" << endl;
        p = (p + 1) % max_itens;
        // Atualizar 'u' quando a fila ficar vazia
        if (isEmpty()) {
            u = p;
        }
    }
}

bool Fila::isFull() {
    return (observador == max_itens);
}

bool Fila::isEmpty() {
    return (observador == 0);
}

void Fila::imprimir() {
    if(isEmpty()){
        cout << "Fila esta vazia" << endl << endl;
    }else{
        cout << "Fila [ ";
        int i = p;
        do{
            cout << estrutura[i] << " ";
            i = (i + 1) % max_itens;
        }while (i != u);

        cout << " ]" << endl;
    }
}
