/**
 * @author Lucas e Jrodri(ball3d)
 * @name dicionário 1 - unico vetor desordenado
 *
*/
#include "aluno.cpp"
#include <string.h>
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
            return "0";
        }
    }

    void remover(int c){
        if(vazio()){
            cout << "Dicionario vazio" << endl;
        }else{
            for(int i = 0;i < n;i++){
                if(estrutura[i].matricula == c){
                    estrutura[i] = estrutura[n - 1];
                    n--;
                    cout << "Chave Removida com sucesso" << endl;
                    break;
                }
            }
        }
    }
};

int main()
{
    Dicionario dic;
    int c;
    int opcao;

    do
    {
        cout << "Digite 1 para inseirir" << endl;
        cout << "Digite 2 para remover" << endl;
        cout << "Digite 3 para cconsultar um valor" << endl;
        cin >> opcao;

        if(opcao == 1){
            string valor;

            cout << "Insira uma chave e um valor para inserir " << endl;
            cin >> c;
            cin >> valor;
            dic.inserir(c,valor);
        }else if(opcao == 2){
            cout << "Digite uma chave a ser removida" << endl;
            cin >> c;
            dic.remover(c);
        }else if(opcao == 3){
            cout << "Digite uma chave para conferir o valor" << endl;
            cin >> c;
            if(dic.consultar(c) == "0"){
                cout << "Chave nao encontrada" << endl;
            }else{
                cout << "Valor encontrado: " << dic.consultar(c) << endl;
            }
        }


    } while (opcao != 0);
    


    return 0;
}