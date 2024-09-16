/*
Escrever uma variação da nossa implementação de árvore em que não haja duplicação do processo de procurar um nó. Mais especificamente, você pode escrever uma função privada que sirva para procurar um nó, mas que retorne um ponteiro apontando para o ponteiro da árvore que aponta para o nó (que pode ser o ponteiro raiz ou um ponteiro de filho esquerdo ou direito), caso o nó exista (e se o nó não existir?). Nesse caso, essa função pode ser utilizada para evitar a repetição do procedimento de busca realizado pelas funções "inserir", "pertence" e "remover".
*/
#include <iostream>
using namespace std;

class ArvoreBinaria
{
private:
    struct Noh
    {
        int valor;
        Noh *prox;
    };
    
    Noh *raiz;

public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void inserir();
    void remover();
    bool procurar();
    bool vazia();
};

int main(){



    return 0;
}