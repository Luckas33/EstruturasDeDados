/**
 * @author Lucas e Jrodri(ball3d)
 * @name dicionário 1 - unico vetor desordenado
 *
*/
#include "aluno.cpp"
#include <string>
#include <iostream>
using namespace std;

typedef Aluno TipoItem;
const int MaxItem = 10;

class Dicionario
{
private:
    int n;
    TipoItem *estrutura;

public:
    Dicionario(){
        n = 0;
        estrutura = new TipoItem [MaxItem];
    }
    ~Dicionario(){
        delete[] estrutura;
    }
    bool cheio(){
        return(n == MaxItem);
    }
    bool vazio(){
        return(n == 0);
    }
    void inserir(int c, string v){
        if(cheio()){

        }else{
            Aluno aluno1(c,v);            

            estrutura[n] = aluno1;
            n++;
        }
    }

    string consultar(int c)
    {
        if(vazio()){
            return nullptr;
        }else{
            for(int i = 0;i < n;i++){
                if(estrutura[i].matricula == c){
                    return (estrutura[i].nome);
                }
            }
        }
    }

    void remover(int c){
        if(vazio()){
            cout << "Dicionario vazio" << endl;
        }else{
            for(int i = 0;i < n;i++){
                if(estrutura[i].matricula = c){
                    estrutura[i] = estrutura[n - 1];
                }
            }
        }
    }
};

int main()
{
    Dicionario dick1;
    int opcao;

    do
    {
        cout << "Digite 1 para inseirir" << endl;
        cout << "Digite 2 para remover" << endl;
        cout << "Digite 3 para se foder" << endl;
        cin >> opcao;


    } while (opcao != 0);
    


    return 0;
}