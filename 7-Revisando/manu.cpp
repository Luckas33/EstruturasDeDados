#include <iostream>
using namespace std;

struct Noh{
    int elem;
    Noh *prox;
};

struct List{
    int numero_itens;
    Noh *primeiro;

    void adicionar(int n){
        Noh *novo = new Noh;
        novo -> elem = n;
        novo -> prox = primeiro;
        primeiro = novo;
    }

    void remover(int n){
        
    }

    bool pertence(int n){
        Noh *aux = primeiro;
        while (aux!= NULL){
            if(aux->elem != n){
                aux = aux -> prox;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

struct Tab{
    List *vetor;
    int capacidade;
    int n_elementos;
    
    Tab(int cap = 10) {
        capacidade = cap;
        vetor = new List[capacidade];
        n_elementos = 0;
    }

    void redimensionar(int nova_capacidade){
        List *novo_vetor = new List[nova_capacidade];
        for (int i = 0; i < capacidade; i++) {
            Noh *aux = vetor[i].primeiro;
            while (aux != nullptr) {
                int novaPos = aux->elem % nova_capacidade;
                novo_vetor[novaPos].adicionar(aux->elem);
                aux = aux->prox;
            }
        }
        vetor = novo_vetor;
        capacidade = nova_capacidade;
    }

    int hash(int c){
        return c%capacidade;
    }

    void adicionar_tab(int n){
        if(pertence_tab(n)){
            return;
        }
        if(n_elementos == capacidade){
            redimensionar(capacidade*2);
        }
        int pos = n%capacidade;
        vetor[pos].adicionar(n);
        n_elementos++;
    }

    bool pertence_tab(int n){
        int pos = n%capacidade;
        if(vetor[pos].pertence(n)){
            return true;
        }
        else{
            return false;
        }
    }

    void remover(int elem){
        if(n_elementos == capacidade/4){
            redimensionar(capacidade / 2);
        }

        int i = elem % capacidade;
        Noh *n = vetor[i].primeiro;

        // Caso o item a ser removido seja o primeiro

        if(n -> elem == elem){
            vetor[i].primeiro = n -> prox;
            delete n;
            n_elementos--;
            return;
        }

        // Caso não seja o primeiro

        while(n -> prox != nullptr){
            if(n -> prox -> elem == elem){
                Noh *aux = n -> prox;
                n -> prox = aux -> prox;
                delete aux;
                n_elementos--;
                return;
            }

            n = n -> prox;
        }
    }
};



int main(){


    
    return 0;
}