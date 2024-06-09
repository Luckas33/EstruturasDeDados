/*
a) Escreva uma função "int remover_ocorrencias (double v, int n, double x)" que, recebendo um (ponteiro apontando para um) vetor "v" de "n" double's e um double "x", remova as eventuais ocorrências de "x" nas "n" posições do vetor. A função também deve informar a quantidade de números restantes no vetor. Exemplo:
   · Se "n" for 10,
   · "v" possuir os números { 10, 2, -7, 4, 2, 2, 9, 2, 3, 2 }
   · e "x" for 2,
então o estado final do vetor deve ser { 10, -7, 4, 9, 3, ?, ?, ?, ?, ? } e a função deve retornar 5.

b) Analogamente ao exercício anterior, escreva um programa para testar a função acima: leia a entrada do usuário e imprima o resultado ao final.
*/
#include <iostream>

int remover_ocorrencias(double vetor[], int tamanho, double item_a_remover)
{
   int resultado = 0;
   for (int i = 0; i < tamanho; i++)
   {
      if (vetor[i] == item_a_remover)
      {
         vetor[i] = -18022005;
         resultado++;
      }
   }
   double vetorNovo[tamanho - resultado];
   int j = 0;

   for (int i = 0; i < tamanho; i++)
   {
      if (vetor[i] != -18022005)
      {
         vetorNovo[j] = vetor[i];
         j++;
      }
   }

   for (int i = 0; i < tamanho - resultado; i++)
   {
      std::cout << "[" << vetorNovo[i] << "] ";
   }

   std::cout << std::endl;
   return resultado;
}

int main()
{
   double vetor[5] = {5, 5, 5, 8, 8};
   int tamanho = 5;
   double item_a_remover;
   std::cout << "Digite o item a ser removido: " << std::endl;
   std::cin >> item_a_remover;

   std::cout << remover_ocorrencias(vetor, tamanho, item_a_remover) << std::endl;
   return 1;
}
