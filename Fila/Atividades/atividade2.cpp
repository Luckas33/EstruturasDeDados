/**
 * @name Atividade 2
 * @author Lucas Sobral, João Rodrigo e Cearamor
 * @brief Escreva uma implementação alternativa de Fila Limitada, com capacidade para até 10 elementos armazenados simultaneamente, que utilize 2 vetores de 5 elementos. (Utilizar um único vetor de 10 elementos seria provavelmente mais simples, mas a proposta deste exercício é viabilizar a implementação num contexto em que algumas restrições sobre a memória disponível fossem estabelecidas previamente à implementação da estrutura.)
 * 

 */
#include <iostream>

using namespace std;

const int Max_Itens = 10;
typedef int Tipo_Var; // Tipo_var == int

class Fila
{
private:
    // Atributos //
    int p, p2, u, n, count;
    Tipo_Var *estrutura1;
    Tipo_Var *estrutura2;
    Tipo_Var *estrutura3;

public:
    // Declaração dos Métodos //
    Fila();  // Construtor
    ~Fila(); // Destrutor
    void inserir(Tipo_Var item);
    void desenfilar();
    bool cheio();
    bool vazio();
    void imprimir();
    int getU();
    int getP();
};

// Implementtação dos Métodos //
Fila::Fila()
{
    p = 0, p2 = 0, u = 0, n = 0, count = 0;
    estrutura1 = new Tipo_Var[Max_Itens / 2];
    estrutura2 = new Tipo_Var[Max_Itens / 2];
    estrutura3 = new Tipo_Var[Max_Itens];
}

Fila::~Fila()
{
    delete[] estrutura1;
    delete[] estrutura2;
}

bool Fila::cheio()
{
    return (n == Max_Itens);
}
bool Fila::vazio()
{
    return (n == 0);
}
void Fila::inserir(Tipo_Var item)
{
    if (cheio())
    {
        cout << "Fila cheia" << endl;
    }
    else
    {
        if (count < Max_Itens / 2) ///
        {
            estrutura1[u] = item;
            u = (u + 1) % (Max_Itens / 2);
            count++; ////
        }
        else
        {
            estrutura2[u] = item;
            u = (u + 1) % (Max_Itens / 2);
            count = (count + 1) % Max_Itens;
        }
        n++;
        cout << "Item adicionado: " << item << endl;
    }
}

void Fila::desenfilar()
{
    if (vazio())
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        p = (p + 1) % (Max_Itens / 2); // Atualiza o marcador para o próximo elemento
        p2 = (p2 + 1) % Max_Itens;
        n--;
    }
}
void Fila::imprimir()
{
    if (vazio())
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        int count = 0;
        
        for(int i = 0; i < (Max_Itens / 2); i++){
        estrutura3[i] = estrutura1[i];
        count++;
    } 
    if(count >= Max_Itens / 2){
        for(int i = 0; i < (Max_Itens / 2); i++){
            estrutura3[i + (Max_Itens / 2)] = estrutura2[i];
        }
    }

        cout << "[ ";
        for (int i = 0; i < n; i++)
        {
            int posicao = (p2 + i) % Max_Itens; // Calcula a posição correta para imprimir
            cout << estrutura3[posicao] << " ";
            
        }
        cout << "]" << endl;
    }

}
    int Fila::getU(){
        return u;
    }
    int Fila::getP(){
        return p;
    }
    


int main()
{

    Fila fila1;
    int opcao, item;

 
    do
    {
        cout << "Digite: \n1 para Adicionar um item\n2 para desenfilar um item\n3 para imprimir\n4 para sair " << endl;
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Digite o item: ";
            cin >> item;
            fila1.inserir(item);
            fila1.imprimir();
            
             
        }
        else if (opcao == 2)
        {
            fila1.desenfilar();
            fila1.imprimir();
            
            
            
        }
        else if(opcao == 3){
            fila1.imprimir();
        }
        else if (opcao == 4)
        {
            break;
        }
    } while (opcao != 0);
    return 0;
}



