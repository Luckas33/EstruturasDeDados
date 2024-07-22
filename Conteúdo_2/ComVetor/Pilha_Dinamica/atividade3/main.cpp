#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef string tipoItem;

class Pilha {
private:
    int tamanho, limiteAtual;
    tipoItem *estrutura;

public:
    Pilha() {
        limiteAtual = 10;
        tamanho = 0;
        estrutura = new tipoItem[limiteAtual];
    }

    ~Pilha() {
        delete[] estrutura;
    }

    void adicionar(tipoItem item) {
        if (cheia()) {
            redimensionar();
        }
        estrutura[tamanho] = item;
        tamanho++;
    }

    tipoItem remover() {
        if (isvazio()) {
            cout << "Pilha vazia" << endl;
            return "";
        } else {
            tamanho--;
            return estrutura[tamanho];
        }
    }

    tipoItem topo() {
        if (isvazio()) {
            cout << "Pilha vazia" << endl;
            return "";
        } else {
            return estrutura[tamanho - 1];
        }
    }

    bool calcular() {
        double y = stod(remover());
        string op = remover();
        double x = stod(remover());
        double result;
        if (op == "+") {
            result = x + y;
        } else if (op == "-") {
            result = x - y;
        } else if (op == "*") {
            result = x * y;
        } else if (op == "/") {
            if (y == 0) {
                return false;
            }
            result = x / y;
        }
        adicionar(to_string(result));
        return true;
    }

    void redimensionar() {
        int limiteNovo = limiteAtual * 2;
        tipoItem *estrutura_nova = new tipoItem[limiteNovo];

        for (int i = 0; i < limiteAtual; i++) {
            estrutura_nova[i] = estrutura[i];
        }
        delete[] estrutura;
        limiteAtual = limiteNovo;
        estrutura = estrutura_nova;
    }

    bool cheia() {
        return tamanho == limiteAtual;
    }

    bool isvazio() {
        return tamanho == 0;
    }
};

void ler(Pilha &P, string expressao) {
    stringstream ss(expressao);
    string token;

    while (ss >> token) {
        if (token == ")") {
            if (!P.calcular()) {
                cout << "Erro na divisão por zero." << endl;
                return;
            }
        } else if (token != "(") {
            P.adicionar(token);
        }
    }

    cout << "Resultado: " << P.topo() << endl;
}

int main() {
    Pilha P;
    string expressao;
    cout << "Digite a expressao aritmetica: ";
    getline(cin, expressao); // Usar getline para permitir espaços na expressão
    ler(P, expressao);
    return 0;
}
