/*
a) Escreva uma função "void inverter (double *p, int n)" que inverta a ordem dos "n" elementos do vetor (cujo primeiro elemento é) apontado por "p", ou seja, o último número deve passar a estar na primeira posição, o penúltimo na segunda, etc. Utilize a indexação de ponteiros abordada no final da aula de hoje.

b) Escreva em C++ um programa que comece lendo do usuário um inteiro positivo "n", que deve ser no máximo 10. Em seguida, o programa deve ler "n" double's do usuário, armazenando-os num vetor (que, neste exercício, pode ter tamanho exatamente 10, mesmo que apenas as "n" primeiras posições sejam utilizadas). 

Em seguida, o programa deve inverter a ordem dos "n" números gravados no vetor, chamando a função do item anterior. Por fim, os "n" números do vetor devem ser impressos na tela (ou seja, serão impressos em ordem inversa em relação à ordem de leitura). Importante: embora o efeito externo do programa seja apenas imprimir os números na ordem inversa da leitura, o programa deve funcionar conforme explicado neste enunciado; a intenção do exercício é escrever e testar a função "inverter".
*/

#include <iostream>
using namespace std;

void inverter(int *p, int n)
{
    int ultimo = n - 1;
    int rodri[1];

    for (int inicio = 0; inicio <= (n / 2); inicio++)
    {
        rodri[0] = p[ultimo];
        p[ultimo] = p[inicio];
        p[inicio] = rodri[0];
        ultimo--;
    }
}

void imprimir(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << vetor[i] << "] ";
    }
    cout<<endl;
}

int main(void)
{
    int n;
    cout << "Digite o tamanho do vetor" << endl;
    cin >> n;
    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o elemento [" << i + 1 << "]";
        cin >> vetor[i];
    }
    imprimir(vetor,n);
    int *p = &vetor[0]; 
    inverter(p, n);
    imprimir(p,n);
}