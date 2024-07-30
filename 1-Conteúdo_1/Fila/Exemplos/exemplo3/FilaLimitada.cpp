///// Exemplo 1 do Professor Pablo ////////

#include <iostream>

using namespace std;

struct Fila
{
    static constexpr int tam_v = 5;

    char v[tam_v];
    int p,u;
};

void inicializar(Fila &F){
    F.p = -1;
}

bool vazia(Fila &F){
    return (F.p == -1);
}

bool cheia (Fila &F){
    if(F.p == -1) return false;

    return (F.u + 1) % F.tam_v == F.p;
}

bool enfilar (Fila &F, char c){
    if(cheia(F)) return false;

    if(F.p == -1){
        F.p = F.u = 0;
    }else{
        F.u = (F.u + 1) % F.tam_v;
    }
    F.v[F.u] = c;
    return true;
}

bool primeiro (Fila &F){
    return F.v[F.p];
}

bool desenfilar (Fila &F){
    if(F.p == -1) return false;

    if(F.u == F.p) F.p = -1;
    else            F.p = (F.p + 1) % F.tam_v;
    return true;
}



int main(){
    Fila F;
    inicializar(F);


    for(;;){
        cout << "Operação(Enfilar, Desenfilar, Primeiro, Sair): " << endl;
        char opcao;
        cin >> opcao;

        if(opcao == 'E'){
            cout << "Elemento a inserir ";
            char elemento;
            cin >> elemento;

            if(enfilar(F, elemento)) cout << "Enfilado" << endl;
            else                     cout << "Cheia" << endl; 
        }else if(opcao == 'D'){
            if (vazia(F)) cout << "Inviável, vazia" << endl;
            else   cout << "Vai ser desenfilado: " << primeiro(F) << endl;
            desenfilar(F);
            
            
            
        }else if(opcao == 'P'){
            if(vazia(F)) cout << "Inviável, vazia" << endl;
            else cout << "Primeiro: " << primeiro(F) << endl;
        }else if(opcao == 'S'){
            break;
        }else{
            cout << "opção invalida" << endl;
        }



    }

    return 0;
}