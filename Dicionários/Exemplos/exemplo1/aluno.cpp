#include <iostream>
#include <string.h>
using namespace std;

class Aluno{
    public:
        int matricula; //chave
        string nome;    //valor

        Aluno(){
            
        }

        Aluno(int matricula, string nome){
            this->matricula = matricula;
            this->nome = nome;
        }
};