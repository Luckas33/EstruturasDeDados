/*
b)Uma funcionalidade básica de conjuntos é a de poder percorrê-los. Uma maneira comum de implementar essa funcionalidade é utilizar iteradores. Um iterador é um tipo (ou seja, um struct/class) que representa uma maneira abstrata de se referir a um elemento de uma coleção. Em C++, a convenção é que um contêiner possui 2 funções básicas relativas a iteradores: uma função -- tipicamente chamada "início/begin" -- retorna um iterador "apontando" para o primeiro elemento do contêiner e outra -- tipicamente chamada "fim/end" -- retorna um contêiner "apontando" para "logo após o último elemento"; a ideia é que, começando do primeiro elemento, seja possível iterar sobre os sucessivos elementos até chegar ao fim, como no código a seguir (observe que, como "fim" retorna um iterador "apontando" para "logo depois do último elemento", então todos os elementos são impressos na tela, inclusive o último):

Conjunto C;

// Aqui: Inserir elementos no conjunto.

Iterador f = fim(C);  // ou C.fim(); // Idem para "inicio".

for (Iterador it = inicio(C); sao_diferentes(it,f); avancar(it)){
  {
   cout << acessar_elemento(it) << '\n';
  }
}

Observe que, além das funções "inicio" e "fim", que recebem um conjunto e retornam um "iterador", o código acima utiliza 3 outras funções essenciais: a função "avancar", que faz o iterador passar a "apontar" para o próximo elemento, a função "acessar_elemento", que retorna o elemento atualmente "apontado" pelo iterador (desde que o iterador não tenha chegado ao "fim"), e a função "sao_diferentes" que informa se dois iteradores apontam ou não para o mesmo "local" (ou seja, ela retorna verdadeiro caso ambos apontem para o mesmo elemento ou caso ambos apontem para o "fim" do contêiner).

Escreva então uma implementação de conjunto que permita um percurso como no código acima. A grande questão aqui é: como você vai definir o struct/class "Iterador", de forma a conseguir viabilizar o percurso pelos elementos do conjunto?
*/
#include <iostream>
#include "Conjunto.h"
#include "Interador.h"
using namespace std;

int main()
{
  printf("Bem-vindo\n");
  cout << "Preencha o conjunto";
  int resposta;
  Conjunto conjunto;
  do
  {
    cout << "Digite 1 para inserir" << endl;
    cout << "Digite 2 para sair" << endl;
    cin >> resposta;
    if (resposta == 1)
    {
      int item;
      cout << "Digite o item a ser inserido" << endl;
      cin >> item;
      conjunto.inserir(item);
    }
    else
    {
      break;
    }
  } while (1);

  Interador F;
  Interador it;
  F.Fim(conjunto);

  for (it.Inicio(conjunto); it.sao_diferentes(it, F); it.avancar(it))
  {
    {
      cout << it.acessar_elemento(it) << '\n';
    }
  }

  return 0;
}