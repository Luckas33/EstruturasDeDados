/*
Usando a sua implementação de pilha ilimitada dos exercícios da aula 07, implemente um programa para avaliar expressões aritméticas nos moldes do final da aula 05. A expressão digitada pode ser arbitrariamente grande, a critério do(a) usuário(a) (daí o uso da pilha ilimitada), mas sempre possuirá exatamente um par de parênteses para cada operador nela presente, como em "((0 - 40) * (1 / 100))" (lembrando que as aspas não fazem parte da entrada). 

Dicas: (a) numa primeira implementação, você pode supor que os elementos presentes na expressão (parênteses, números e operadores) estarão todos separados por pelo menos um espaço em branco, como em "( ( 0 - 40 ) * ( 1 / 100 ) )";

assim sendo, cada comando "cin >> s", sendo "s" uma string, lerá apenas um elemento (parêntese, número ou operador); (b) as funções stod e to_string convertem facilmente entre double e string, de forma que você pode implementar e usar uma pilha de strings e converter os seus elementos de e para "double" sempre que necessário.

Escreva um programa que avalie expressões aritméticas digitadas usando operadores pré-fixos, ou seja, que aparecem antes dos seus operandos, como em "/ 6000 * 5 / 1410 94", que na notação infixa seria escrita como "6000 / (5 * (1410/94))". Observe que, nessa notação polonesa, os parênteses são dispensáveis, pois nunca há ambiguidade, desde que o número de operandos de cada operador seja respeitado. Outro exemplo de entrada possível: "/ * + 3 5 7 - 20 6", que na notação infixa é "((3 + 5) * 7) / (20 - 6)".
*/
#include <iostream>;
using namespace std;

class Pilhuda
{
private:
    /* data */
public:
    Pilhuda(/* args */);
    ~Pilhuda();
};


int main(){



    return 0;
}