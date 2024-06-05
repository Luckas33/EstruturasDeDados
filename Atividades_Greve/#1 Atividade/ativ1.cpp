/*
Exercícios de Greve #1:

A)Defina um tipo para representar uma matriz retangular m x n de double's. Como estrutura de dados, utilize um vetor para representar as "m" linhas: cada uma das suas posições deve ser um ponteiro apontando para um vetor de "n" números. Escreva funções para ler e escrever nas posições da matriz. Para testar a sua implementação, escreva um programa que leia do usuário duas matrizes de mesmas dimensões e que então calcule e imprima a soma dessas matrizes.

att: O professor nao pensou direito na hora de escrever

*/

#include <iostream>
using namespace std;

class Matriz
{
private:
  int m, n;
  double **M;

public:
  Matriz(int m, int n);
  ~Matriz();
  void escrever(double item, int m, int n);
  void ler();
  void imprimir();
  Matriz somar(Matriz rodri);
};

Matriz::Matriz(int m, int n)
{
  this->m = m;
  this->n = n;
  this->M = new double *[m];
  for (int i = 0; i < m; i++)
  {
    M[i] = new double[n];
  }
}

Matriz::~Matriz()
{
  delete[] M;
}

void Matriz::escrever(double item, int m, int n)
{
  M[m][n] = item;
}
void Matriz::ler()
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      double item;
      cout << "Escreva o item na posicao: [" << i << "," << j << "]\n";
      cin >> item;
      Matriz::escrever(item, i, j);
    }
  }
}

void Matriz::imprimir()
{
  for (int i = 0; i < m; i++)
  {

    for (int j = 0; j < n; j++)
    {
      cout << M[i][j] << " ";
    }
    cout << "\n";
  }
}

Matriz Matriz::somar(Matriz M2)
{
  double item;
  Matriz matrizNova(m, n);
  cout << "Resultado: " << endl;
  
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      item = M2.M[i][j] + M[i][j];
      matrizNova.escrever(item, i, j);
    }
  }
  return matrizNova;
}

int main()
{
  int m,n;
  cout << "Bem-vindo" << endl;
  cout << "Digite o numero de linhas e colunas m x n" << endl;
  cin >> m;
  cin >> n;
  Matriz m1(m,n);
  Matriz m2(m,n);

  cout << "Agora vamos preencha a matriz 1" << endl;
  m1.ler();
  cout << "Agora vamos preencha a matriz 2" << endl;
  m2.ler();

  Matriz soma = m1.somar(m2);
  soma.imprimir();

  return 0;
}