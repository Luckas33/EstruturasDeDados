///// Atividade 1, fazer uma fila sem usar o marcador u, somente p e n /////
/**
 * @author Lucas Sobral
 * @brief Fila limitada sem usar marcador ultimo
 * @bug Algoritmo incompleto, a função vazia está errada, como fazer o n detectar que esta vazia?
*/

#include <iostream>

using namespace std;

typedef int tipoItem;
const int Max_valor = 5;

class Fila{
    private:
        int p, n ;
        tipoItem* estrutura = new tipoItem[Max_valor];

    public:

        Fila(){
            p = 0;
            n = 0;
        }

        ~Fila(){
            delete[] estrutura;
        }
        bool vazia(){
            return(n == 0);
        }

        bool cheia(){
            return(n == Max_valor);
        }

        void inserir(tipoItem item){
            if(cheia()){
                cout << "Fila cheia" << endl;
            }else{
                cout << "Item adicionado a fila: " << item << endl;
                estrutura[n] = item;
                n = (n + 1) % Max_valor;
            }
        }

        void desenfilar(){
            if(vazia()){
                cout << "Fila vazia" << endl;
            }else{
                cout << "Item removido: " << estrutura[p] << endl;
                p = (p + 1) % Max_valor;
            }
        }
        void imprimir(){
            if(vazia()){
                cout << "Fila vazia" << endl;
            }else{

                int i = p;
                cout << "[ ";
                do
                {
                    cout << estrutura[i] << " ";
                    i = (i + 1) % Max_valor;
                }while(i != n);
                cout << " ]" << endl;
            }
        }
};


int main(){
    Fila fila1;
    int opcao;
    tipoItem item;

    do
    {
        cout << "Digite: \n1 para Adicionar um item\n2 para desenfilar um item\n3 para Sair " << endl;
        cin >> opcao;

        if(opcao == 1){
            cout << "Digite o item: ";
            cin >> item;
            fila1.inserir(item);
            fila1.imprimir();

        }else if(opcao == 2){
            fila1.desenfilar();
            fila1.imprimir();

        }else if(opcao == 3){
            break;
        }
    } while (opcao != 0);
    
    system("pause");
    return 0;
}