/**
 * @name Atividade 2
 * @author Lucas Sobral
 * @brief Escreva uma implementação alternativa de Fila Limitada, com capacidade para até 10 elementos armazenados simultaneamente, que utilize 2 vetores de 5 elementos. (Utilizar um único vetor de 10 elementos seria provavelmente mais simples, mas a proposta deste exercício é viabilizar a implementação num contexto em que algumas restrições sobre a memória disponível fossem estabelecidas previamente à implementação da estrutura.)
*/
#include <iostream>

using namespace std;

const int Max_Itens = 10;
typedef int Tipo_Var;


class Fila
{
private:
    int p,u;
    Tipo_Var* estrutura1;
    Tipo_Var* estrutura2;
public:
    Fila(/* args */);
    ~Fila();
};


int main (){


    return 0;
}