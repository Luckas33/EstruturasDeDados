#include <iostream>
#include <string.h>
using namespace std;

class Aluno2{
    public:
        int matricula; //chave
        string nome;    //valor

        Aluno2(){
            
        }

        Aluno2(int matricula, string nome){
            this->matricula = matricula;
            this->nome = nome;
        }
};