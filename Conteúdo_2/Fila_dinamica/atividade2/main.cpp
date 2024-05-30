/*
Escreva uma implementação de fila ilimitada utilizando vetor (alocado dinamicamente). O vetor inicial deve ter tamanho 1 ou 2. Sempre que o vetor estiver cheio, utilize a estratégia de redimensionamento eficiente estudada na aula: substituí-lo por outro com o dobro do tamanho.
Escreva uma variação da implementação da questão anterior que, além de expandir o vetor quando ele estiver cheio, também "contraia" o vetor (isto é, substitua-o por outro menor) quando ele estiver significativamente vazio.
Atenção: pense numa estratégia eficiente de contração, que faça com que o número de cópias ao longo das operações da fila (tanto inserções quanto remoções) seja proporcional ao número de operações realizadas. A grande questão é: você irá contrair o vetor quando ele estiver quantos % vazio? E o vetor menor terá que tamanho em relação ao original? Ao responder estas perguntas, use o argumento das moedas para se convencer de que as suas escolhas são eficientes: de quantas moedas você vai precisar a cada inserção e a cada remoção?
*/

#include <iostream>
using namespace std;

typedef int tipoItem;
int limiteAtual = 1; // começar com 1 ou 2

class FilaIlimitada
{
private:
    int primeiro, ultimo;
    tipoItem *estrutura;

public:
    FilaIlimitada()
    {
        primeiro = 0;
        ultimo = 0;
        estrutura = new tipoItem[limiteAtual];
    }

    ~FilaIlimitada()
    {
        delete[] estrutura;
    }

    void inserir(tipoItem item)
    {
        if (cheia())
        {
            redimencionar();
        }
        estrutura[ultimo] = item;
        ultimo++;
        imprimir();
    }

    void remover()
    {
        if (vazio())
        {
            cout << "Fila vazia" << endl;
        }
        else
        {
            cout << "Item " << estrutura[primeiro] << " removido com sucesso" << endl;
            primeiro++;
            imprimir();
        }
    }

    void redimencionar()
    {
        int limiteNovo = limiteAtual * 2;
        tipoItem *estruturaNova = new tipoItem[limiteNovo];

        for (int i = 0; i < limiteAtual; i++)
        {
            estruturaNova[i] = estrutura[i + primeiro];
        }
        delete[] estrutura;
        estrutura = estruturaNova;
    }

    bool cheia()
    {
        return ultimo == limiteAtual;
    }

    bool vazio()
    {
        return primeiro == ultimo;
    }

    void imprimir()
    {
        cout << "Fila: [ ";
        for (int i = primeiro; i < ultimo; i++)
        {
            if (primeiro != ultimo)
            {
                cout << estrutura[i] << ", ";
            }
            else
            {
                cout << estrutura[primeiro];
            }
        }
        cout << "]" << endl;
    }
};

int main()
{
    int escolha;
    FilaIlimitada fila;
    do
    {
        cout << "Digite 1 para inserir um item" << endl;
        cout << "Digite 2 para remover um item" << endl;
        cout << "Digite 3 para imprimir a fila" << endl;
        cout << "Digite 0 para sair" << endl;
        cin >> escolha;

        if (escolha == 1)
        {
            tipoItem item;
            cout << "Digite o item a ser adicionado: ";
            cin >> item;
            fila.inserir(item);
        }
        else if (escolha == 2)
        {
            fila.remover();
        }
        else if (escolha == 3)
        {
            fila.imprimir();
        }
        else if (escolha == 0)
        {
            cout << "saindo...." << endl;
            break;
        }
        else
        {
            cout << "resposta inválida";
        }

    } while (1);

    return 0;
}