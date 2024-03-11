#include <iostream>
using namespace std;

typedef int TipoItem;
const int max_itens = 10 + 1;

class Conjunto{
    private:
        TipoItem* estrutura;
        int n;

    public:
        Conjunto(); 
        ~Conjunto();
        bool pertece(TipoItem x);
        void inserir_novo(TipoItem x);
        void inserir_se_novo(TipoItem x);
        void remover(TipoItem x);
        void imprimir();
};

        Conjunto::Conjunto(){
            estrutura = new TipoItem[max_itens];
            n = -1;
        }
        Conjunto::~Conjunto(){
            delete[] estrutura;
        }
        bool Conjunto::pertece(TipoItem x){
            int i = 0, f = n - 1;
            while (i <=f)
            {
                int m = (i + f) / 2;
                if(x == estrutura[m]) return true;
                if(x < estrutura[m]) f = m - 1;
                else                 i = m + 1;
            }
            return false;
            
        }
        void Conjunto::inserir_novo(TipoItem x){
            if(n == max_itens - 1){
                cout << "Conjunto cheio" << endl;
            }else{
                n++;
                estrutura[n] = x;
                
                cout << "Item inserido com sucesso: " << x << endl;
            }
        }
        void Conjunto::inserir_se_novo(TipoItem x){
            if(pertece(x)){
                cout << "Item ja existente" << endl;
            }else{
                inserir_novo(x);
            }
        }
        void Conjunto::remover(TipoItem x){
            if (n == 0)
            {
                cout << "Conjunto vazio" << endl;
            }else if(pertece(x)){
               for(int i = 0;i < n;i++){
                    if(estrutura[i] == x){
                        estrutura[i] = n;
                        n--;
                        break;
                    }
               }
            } 
        }
        void Conjunto::imprimir(){
            cout << "Conjunto: [ ";
            for (int i = 0; i <= n; i++)
            {
                cout << estrutura[i] << " ";
            }
            cout << "] " << endl;
            
        }


int main(){
    int opcao;
    TipoItem item;
    Conjunto conjt1;
    do
    {
        cout << "Digite 1 para adicionar um item ao conjunto" << endl;
        cout << "Digite 2 para remover um item do conjunto" << endl;
        cout << "Digite 3 para imprimir um item do conjunto" << endl << endl;
        cin >> opcao;

        if(opcao == 1){
            cout << "Digite o item que deseja inserir" << endl;
            cin >> item;
            conjt1.inserir_se_novo(item);
        }else if(opcao == 2){
            cout << "Digite o item que deseja excluir" << endl;
            cin >> item;
            conjt1.remover(item);
        }else if(opcao == 3){
            conjt1.imprimir();
        }else{
            break;
        }

    } while (opcao != 0);
    

    system("pause");
    return 0;
}