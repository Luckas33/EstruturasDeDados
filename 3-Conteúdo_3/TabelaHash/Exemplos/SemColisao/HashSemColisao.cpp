//Método Método da Divisão(Sem colisão)
// Este método é particularmente fácil e eficiente, sendo por isso muito empregado. A chave x é dividida pela dimensão da tabela m, e o resto da divisão é usado como endereço-base. Isto é,

// h(x) = h mod m,

// resultando em endereços no intervalo [0, m – 1].

// Nesse caso, alguns valores de m são melhores que outros. Por exemplo, se m é um número par, h(x) será par quando x for par e ímpar quando x for ímpar, o que certamente não satisfaz. A situação é ainda pior se m for potência de 2, caso em que h(x) dependerá apenas de alguns dígitos de x. Suponha m = 2j e a chave armazenada numa palavra de memória de 16 bits. Se j = 5, a função h(x) produzirá endereços que resultam dos últimos cinco bits da chave, isto é, h(x) não levará nunca em consideração os dígitos mais significativos de x. Para chaves geradas a partir da concatenação de informações, esse divisor é pouco adequado.

// Diversos resultados teóricos são conhecidos sobre o assunto. Entretanto, estas análises baseiam-se no conhecimento prévio de algumas características das chaves. Existem alguns critérios que têm sido aplicados com bons resultados práticos, como escolher m de modo que seja um número primo não próximo a uma potência de 2. Ou, então, escolher m tal que não possua divisores primos menores que 20. A Figura 10.3 apresenta um exemplo de armazenamento de algumas chaves em uma tabela de dispersão de dimensão 23. A Figura 10.3(a) mostra o resultado do mapeamento utilizando o método da divisão: 44 mod 23 = 21, 46 mod 23 = 0, e assim sucessivamente.

#include <iostream>
using namespace std;

class HashSemColisao
{
private:
    int M[10];
public:
    void funcaoHash(int item){ //Função hash utilizando do método da divisão sem colisão
        M [item%10] = item;
    }
    void imprimir(){
        cout << "[";
        for (int i = 0; i < 10; i++)
        {
            cout << M[i] <<",";
        }
        cout <<"]"<<endl;
    }
};

int main(){
    HashSemColisao hash;
    hash.funcaoHash(0);
    hash.funcaoHash(1);
    hash.funcaoHash(2);
    hash.funcaoHash(3);
    hash.funcaoHash(4);
    hash.funcaoHash(5);
    hash.funcaoHash(6);
    hash.funcaoHash(7);
    hash.funcaoHash(8);
    hash.funcaoHash(9);
    hash.imprimir();

    return 0;
}


