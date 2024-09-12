#include <iostream>
using namespace std;

typedef int Valoritem;

class ArvoreBinaria
{
private:
    struct Noh{
        Noh *FilhoEsq;
        Valoritem item;
        Noh *FilhoDir;
    };

public:
    Noh *Raiz;
    
    ArvoreBinaria(){
        Raiz = nullptr;
    }
    ~ArvoreBinaria();
    void inserir(Valoritem item){
        Noh *NovoNoh = new Noh{nullptr,item,nullptr};
        Noh *procurar = Raiz;
        if (Raiz == nullptr)
        {
            Raiz = NovoNoh;
            return;
        }
        while (1)
        {
            if (item < procurar -> item)
            {
                if (procurar -> FilhoEsq == nullptr)
                {
                    procurar -> FilhoEsq = NovoNoh;
                    return;
                }else{
                    procurar = procurar -> FilhoEsq;
                }
            }else if(item > procurar -> item){
                if(procurar ->FilhoDir == nullptr){
                    procurar ->FilhoDir = NovoNoh;
                    return;
                }else{
                    procurar = procurar ->FilhoDir;
                }
            }
        }
        
    }
    bool pertence(Valoritem item){
        if(vazio()) cout << "Arvore Vazia" << endl; return;
        Noh *procurar = Raiz;
        while (1)
        {
            if (item == procurar ->item)
            {
                return true;
            }else{
                if (item  < procurar->item)
                {
                    procurar = procurar -> FilhoEsq;
                }else{
                    procurar = procurar -> FilhoDir;
                }
            }  
        }
    }
    void remover(Valoritem item){
        if (vazio()) return;
        
    }
    void imprimir();

    bool vazio(){
        return Raiz == nullptr;
    }
};







int main()
{
    return 0;
}
