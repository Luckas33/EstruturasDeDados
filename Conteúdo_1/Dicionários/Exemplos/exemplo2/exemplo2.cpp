/**
 * @author Lucas
 * @name Dicionário 2 - dois vetores desordenado
 *
 *
 */
#include "Aluno2.cpp"
#include <iostream>
#include <string.h>
using namespace std;

const int Max_itens = 10;

class Dicionario
{
private:
    int n;
    int *estrutura1;
    string *estrutura2;

public:
    Dicionario();
    ~Dicionario();
    bool cheio();
    bool vazio();
    void inserir(int c, string v);
    string consultar(int c);
    void remover(int c);
};

Dicionario::Dicionario()
{
    n = 0;
    estrutura1 = new int[Max_itens];
    estrutura2 = new string[Max_itens];
}
Dicionario::~Dicionario()
{
    delete[] estrutura1;
    delete[] estrutura2;
}
bool Dicionario::cheio()
{
    return (n == Max_itens);
}
bool Dicionario::vazio()
{
    return (n == 0);
}
void Dicionario::inserir(int c, string v)
{
    if (cheio())
    {
        cout << "Dicionario cheio" << endl;
    }
    else
    {
        Aluno2 aluno1(c, v);
        estrutura1[n] = aluno1.matricula;
        estrutura2[n] = aluno1.nome;
        n++;
    }
}
string Dicionario::consultar(int c)
{
    if (vazio())
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (estrutura1[i] == c)
            {
                return estrutura2[i];
            }
        }
    }
    return "0";
}

void Dicionario::remover(int c)
{
    if (vazio())
    {
        cout << "Dicionario vazio" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (estrutura1[i] == c)
            {
                estrutura1[i] = estrutura1[n - 1];
                estrutura2[i] = estrutura2[n - 1];
                n--;
                break;
            }
        }
    }
}

int main()
{
    Dicionario dic;
    int c;
    int opcao;

    do
    {
        cout << "Digite 1 para inserir" << endl;
        cout << "Digite 2 para remover" << endl;
        cout << "Digite 3 para cconsultar um valor" << endl;
        cin >> opcao;

        if (opcao == 1)
        {
            string valor;

            cout << "Insira uma chave e um valor para inserir " << endl;
            cin >> c;
            cin >> valor;
            dic.inserir(c, valor);
        }
        else if (opcao == 2)
        {
            cout << "Digite uma chave a ser removida" << endl;
            cin >> c;
            dic.remover(c);
        }
        else if (opcao == 3)
        {
            cout << "Digite uma chave para conferir o valor" << endl;
            cin >> c;
            if (dic.consultar(c) == "0")
            {
                cout << "Chave nao encontrada" << endl;
            }
            else
            {
                cout << "Valor encontrado: " << dic.consultar(c) << endl;
            }
        }

    } while (opcao != 0);
    return 0;
}