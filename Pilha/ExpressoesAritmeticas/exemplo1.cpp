/**
 * @author Lucas
 * @brief pilha aritmetica, pega os valores de um vetor e calcula em uma variavel
 * 
*/
#include <string.h>
#include <iostream>
#include <cctype>
using namespace std;
const int MaxItem = 10;


struct Pilha{
    string estrutura[MaxItem]; //estrutura[(1+2)-(4+7)]
    int n = 0;
};

bool vazia(Pilha &P){
    cout << "Fila vazia" << endl;
    return(P.n == 0);
}

bool cheia(Pilha &P){
    cout << "Fila cheia" << endl;
    return(P.n == MaxItem);
}

void inserir(Pilha &P,string item){
    if(cheia(P)){
    }
    else{
        P.estrutura[P.n] = item;
        P.n++;
    }
}

string remover(Pilha &P){
    if(vazia(P)){
    }else{
        cout << "Item removido: " << P.estrutura[P.n - 1];
        return P.estrutura[P.n - 1];
        P.n--;
    }
}

int calcular(Pilha &P){

    int num1,num2, total;

    if(vazia(P)){
    }else{
        for(int i;i < P.n;i++){
            string digito = P.estrutura[i];
            if(isdigit(digito[0])){
                
            }
        }
    }
    return 0;
}





int main(){
    Pilha P;


    return 0;
}