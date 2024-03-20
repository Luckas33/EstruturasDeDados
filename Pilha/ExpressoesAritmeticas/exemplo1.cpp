#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int MaxItem = 10;

struct Pilha {
    string estrutura[MaxItem];
    int n = 0;
};

void inserir(Pilha &P, string item) {
    P.estrutura[P.n] = item;
    P.n++;
}

string remover(Pilha &P) {
    string res = P.estrutura[P.n - 1];
    P.n--;
    return res;
}

bool calcular(Pilha &P) {
    try {
        double y = std::stod(remover(P));
        string op = remover(P);
        double x = std::stod(remover(P));
        double result;
        if (op == "+") {
            result = x + y;
        } else if (op == "-") {
            result = x - y;
        } else if (op == "*") {
            result = x * y;
        } else if (op == "/") {
            if (y == 0) {
                throw invalid_argument("Divisao por zero");
            }
            result = x / y;
        }
        inserir(P, to_string(result));
        return true;
    } catch (const invalid_argument &e) {
        cerr << "Erro: " << e.what() << endl;
        return false; // Indica que houve um erro ao calcular
    }
}

void ler(Pilha &P, string expressao) {
    stringstream ss(expressao);
    std::string token;

    while(ss >> token){
    stringstream tokenStream(token);

    if(token != "("){

        if(token == ")"){
            calcular(P);
        }
        else{
        inserir(P, token);
        }
    

    }
    
}
    cout << P.estrutura[0] << endl;
}

int main() {
    Pilha P;
    string expressao;
    cout << "Digite a expressao aritmetica: ";
    getline(cin, expressao); // Usar getline para permitir espaços na expressão
    ler(P, expressao);
    return 0;
}

