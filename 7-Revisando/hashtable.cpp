#include <iostream>
#include <string>
using namespace std;

class Hashtable{
private:
    struct Node{   
        int key;
        string value;
        Node *next;
    };
    
    int tamanho;
    int numero_de_itens;
    Node **T;
    Node sentinela;

    int h(int c){
        return (c % tamanho);
    }
    
    void resize(int new_size){
        Node **U = new Node*[new_size]; //Criar um vetor com o novo tamanho
        for(int i=0; i<new_size; i++){ //Todos os índices desse vetor apontarão para o sentinela
            U[i] = &sentinela;
        }
        
        int tamanho_atual = tamanho; // salva o tamanho atual
        tamanho = new_size; // atualiza o tamanho da tabela

        for(int i=0; i<tamanho_atual; i++){
            Node *n = T[i];
            while(n != &sentinela){
                Node *next = n->next;
                int j = h(n->key);
                n->next = U[j];
                U[j] = n;
                n = next;
            }
        }
        delete[] T;
        T = U;
    }
     
public:
    Hashtable(){
        tamanho = 1;
        numero_de_itens = 0;
        T = new Node*[tamanho];
        sentinela.next = nullptr; // Opcional
        T[0] = &sentinela;
    }

    ~Hashtable(){
        for(int i = 0; i < tamanho; i++){
            Node *n = T[i];
            while(n != &sentinela){
                Node *next = n->next;
                delete n;
                n = next;
            }
        }
        delete[] T;
    }

    string search(int c){
        int i = h(c);
        Node *n = T[i];
        while(n != &sentinela){
            if(n->key == c){
                return n->value;
            }
            n = n->next;
        }
        return "";
    }

    bool pertence(int c, string v){
        return search(c) == v;
    }

    bool empty_local(int c){
        int i = h(c);
        Node *k = T[i];
        return T[i] == &sentinela; 
    }
    
    void inserir(int Chave, string Valor){
        if(pertence(Chave, Valor)) return; 
        if(tamanho == numero_de_itens) resize(2*tamanho);
        
        int i = h(Chave);
        T[i] = new Node {Chave, Valor, T[i]};

        ++numero_de_itens;
    }
    
    void remover(int c){
        if(numero_de_itens = tamanho*0.25) resize(tamanho/2);
        
        if(empty_local(c)) return; //verifica se é vazio o índice
        if(numero_de_itens == 0) return; // verifica se a tabela é vazia
        int i = h(c);
        Node *atual = T[i]; //cria um nó que vai apontar para o nó a ser excluído
        Node *anterior = &sentinela;
        
        int tamanho_antigo = tamanho;
        int numero_de_itens_old = numero_de_itens;

        while(atual != &sentinela){
            if(atual->key == c){
                if(anterior == &sentinela){
                    T[i] = atual->next;
                    delete atual;
                    -- numero_de_itens;
                    return;
                }
                anterior->next = atual->next;
                delete atual;
                -- numero_de_itens;
                return;
            }
            anterior = atual;
            atual = atual->next;
        }
        cout << "Chave: " << c << " não encontrada" << endl;
    }
    
    bool cheio(){
        return numero_de_itens == tamanho;
    }

    void display(){
        for(int i = 0; i < tamanho; i++){
            cout << "Balde " << i << ": ";
            Node *n = T[i];
            while(n != &sentinela){
                cout << "(" << n->key << ", " << n->value << ") -> ";
                n = n->next;
            }
            cout << "sentinela" << endl;
        }
    }
};



int main(){
cout << "Starting main..." << endl;
    Hashtable dict;

    // Teste de inserção
    dict.inserir(1, "one");
    dict.inserir(2, "two");
    dict.inserir(3, "three");
    dict.inserir(6, "six"); // Causa colisão com chave 1

    // Exibe o dicionário
    dict.display();

    // Teste de busca
    cout << "Search key 3: " << dict.search(3) << endl;
    cout << "Search key 10: " << dict.search(10) << endl; // Não encontrado

    // Teste de remoção
    dict.remover(2);
    cout << "After removing key 2:" << endl;
    dict.display();

    // Teste de remoção com redimensionamento
    dict.remover(1);
    cout << "After removing key 1:" << endl;
    dict.display();

    dict.remover(3);
    cout << "After removing key 3:" << endl;
    dict.display();

    return 0;
}