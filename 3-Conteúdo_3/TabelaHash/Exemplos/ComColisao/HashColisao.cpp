// Tabela Hash com colisões
// Por conta destas colisões se faz necessário o Tratamento de Colisões por Encadeamento
// Já foi observado que o mesmo endereço-base pode ser encontrado para chaves diferentes, como resultado da função de dispersão, o que é chamado de colisão. Define-se como fator de carga de uma tabela de dispersão o valor α = n/m, onde n é o número de chaves armazenadas. Um método para diminuir colisões é então reduzir o fator de carga; à medida que este cresce, a possibilidade de ocorrerem colisões também cresce. Essa precaução deve ser tomada, uma vez que o número de colisões cresce rapidamente quando o fator de carga aumenta, mas não resolve o problema. Uma nova chave sempre pode encontrar o seu endereço-base já ocupado. Por esse motivo, o emprego de tabelas de dispersão implica, necessariamente, a previsão de algum método de tratamento de colisões.

// Uma ideia natural para tratar colisões consiste em armazenar as chaves sinônimas em listas encadeadas. Há duas alternativas. As listas podem se encontrar no exterior da tabela ou compartilhar o mesmo espaço da tabela.

// Neste código utilizarei o encadeamento exterior
//Agradecimentos ao bom jardim

#include <iostream>
using namespace std;
typedef char tipoItem;

class TabelaHash
{
private:
    struct Noh
    {
        int chave;
        tipoItem item;
        Noh *prox;
    };

    Noh sentinela;
    Noh **Tabela;
    int tamanhoAtual, totalItens;

    struct ResConsulta
    {
        bool achou;
        string valor;
    };
    ResConsulta consultar(int chave)
    {
        ResConsulta res;
        int i = FuncaoHash(chave);

        Noh *n = Tabela[i];
        while (n != &sentinela)
        {
            if (n->chave == chave)
            {
                res.achou = true;
                res.valor = n->item;
                return res;
            }
            n = n->prox;
        }

        res.achou = false;
        return res;
    }

public:
    TabelaHash()
    {
        tamanhoAtual = 1;
        totalItens = 0;
        Tabela = new Noh *[tamanhoAtual];
        Tabela[0] = &sentinela;
    }
    ~TabelaHash();
    void inserir(int chave, tipoItem item)
    {
        ResConsulta consulta = consultar(chave);
        if (consulta.achou == true)
        {
            return;
        }
        
        int i;
        if (cheio())
        {
            redimencionarTamanho(tamanhoAtual * 2);
        }
        i = FuncaoHash(chave);
        Tabela[i] = new Noh{chave, item, Tabela[i]};
        totalItens++;
    }
    int FuncaoHash(int chave)
    {
        return (chave % tamanhoAtual);
    }
    void remover(int c){
        if(totalItens = tamanhoAtual*0.25) redimencionarTamanho(tamanhoAtual/2);
        
        if(totalItens == 0) return; // verifica se a tabela é vazia
        int i = FuncaoHash(c);
        Noh *atual = Tabela[i]; //cria um nó que vai apontar para o nó a ser excluído
        Noh *anterior = &sentinela;
        
        int tamanho_antigo = tamanhoAtual;
        int numero_de_itens_old = totalItens;

        while(atual != &sentinela){
            if(atual->chave == c){
                if(anterior == &sentinela){
                    Tabela[i] = atual->prox;
                    delete atual;
                    -- totalItens;
                    return;
                }
                anterior->prox = atual->prox;
                delete atual;
                -- totalItens;
                return;
            }
            anterior = atual;
            atual = atual->prox;
        }
        cout << "Chave: " << c << " não encontrada" << endl;
    }

    void redimencionarTamanho(int tamanhoNovo)
    {
        Noh **TabelaNova = new Noh *[tamanhoNovo];
        int m = tamanhoAtual;
        tamanhoAtual = tamanhoNovo;

        for (int i = 0; i < m; i++) // nova tabela recebe sentinela todos os índices
        {
            TabelaNova[i] = &sentinela;
        }

        for (int j = 0; j < tamanhoAtual; j++) // Adicionar os elementos antigos a nova tabela
        {
            Noh *aux1 = Tabela[j];
            while (aux1 != &sentinela) // Percorre  a lista encadeada do índice da tabela
            {
                Noh *aux2 = aux1->prox;
                int indice = FuncaoHash(aux1->chave);
                aux1->prox = TabelaNova[indice];
                TabelaNova[indice] = aux1;
                aux1 = aux2;
            }
        }

        delete[] Tabela;
        Tabela = TabelaNova;
    }

    void imprimir(){
        for(int i = 0; i < tamanhoAtual; i++){
            cout << "Balde " << i << ": ";
            Noh *n = Tabela[i];
            while(n != &sentinela){
                cout << "(" << n->chave << ", " << n->item << ") -> ";
                n = n->prox;
            }
            cout << "sentinela" << endl;
        }
    }
    bool vazio()
    {
        return totalItens == 0;
    }
    bool cheio()
    {
        return totalItens == tamanhoAtual;
    }
};

int main()
{
    TabelaHash hash;
    unsigned short escolha;
    do
    {
        cout << "Digite 1 para inserir" << endl;
        cout << "Digite 2 para remover" << endl;
        cout << "Digite 3 para sair" << endl;
        cin >> escolha;
        int chave;
        tipoItem item;

        if (escolha == 1)
        {
            cout << "Digite uma chave e um item a ser armazenado" << endl;
            cin >> chave;
            cin >> item;
            hash.inserir(chave, item);
        }
        else if (escolha == 2)
        {
            cout << "Digite uma chave e valor a serem deletados";
            cin >> chave;
            cin >> item;
            hash.remover(chave);       
        }
        else
        {
            escolha = 3;
        }

    } while (escolha != 3);

    return 0;
}