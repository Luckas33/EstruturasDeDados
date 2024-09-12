// Tabela Hash com colisões
// Por conta destas colisões se faz necessário o Tratamento de Colisões por Encadeamento
// Já foi observado que o mesmo endereço-base pode ser encontrado para chaves diferentes, como resultado da função de dispersão, o que é chamado de colisão. Define-se como fator de carga de uma tabela de dispersão o valor α = n/m, onde n é o número de chaves armazenadas. Um método para diminuir colisões é então reduzir o fator de carga; à medida que este cresce, a possibilidade de ocorrerem colisões também cresce. Essa precaução deve ser tomada, uma vez que o número de colisões cresce rapidamente quando o fator de carga aumenta, mas não resolve o problema. Uma nova chave sempre pode encontrar o seu endereço-base já ocupado. Por esse motivo, o emprego de tabelas de dispersão implica, necessariamente, a previsão de algum método de tratamento de colisões.

// Uma ideia natural para tratar colisões consiste em armazenar as chaves sinônimas em listas encadeadas. Há duas alternativas. As listas podem se encontrar no exterior da tabela ou compartilhar o mesmo espaço da tabela.

//Neste código utilizarei o encadeamento exterior

#include <iostream>
using namespace std;
typedef char tipoItem;

class TabelaHash
{
private:
    struct Noh
    {
        Noh *prox;
        tipoItem item;
    };

    Noh **Tabela;
    int tamanhoAtual, totalItens;

public:
    TabelaHash(){
        tamanhoAtual = 1;
        totalItens = 0;
        Tabela = new Noh*[tamanhoAtual];
    }
    ~TabelaHash();
    void inserir(int chave, tipoItem item);
    void remover(int chave, tipoItem item);
    void FuncaoHash(int chave, tipoItem item){
        Tabela[chave&tamanhoAtual];
        
    }
    void redimencionarDobrar(){
        int tamanhoNovo = tamanhoAtual * 2;
        Noh **TabelaNova = new Noh*[tamanhoNovo];
        for (int i = 0; i < tamanhoAtual; i++)
        {
            TabelaNova[i] = Tabela[i];
        }
        tamanhoAtual = tamanhoNovo;
        delete[] Tabela;
        Tabela = TabelaNova;
    }
    void redimencionarDividir(){
        int tamanhoNovo = tamanhoAtual / 2;
        Noh **tabelaNova = new Noh*[tamanhoNovo];
        for (int i = 0; i < tamanhoAtual; i++)
        {
            tabelaNova[i] = Tabela[i];
        }
        tamanhoAtual = tamanhoNovo;
        delete[] Tabela;
        Tabela = tabelaNova;
    }
    bool vazio(){
        return totalItens == 0;
    }
    bool cheio(){
        return totalItens == tamanhoAtual;
    }
};















int main(){







    return 0;
}