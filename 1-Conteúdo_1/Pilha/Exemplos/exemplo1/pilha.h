

typedef int TipoItem;
const int max_itens = 100;

class pilha
{
private:
    int tamanho;
    TipoItem *estrutura;

public:
    pilha();        // Construtor
    ~pilha();       // Destrutor
    bool isFull();  // Verifica se a pilha está cheia
    bool isEmpty(); // verifica se a pilha está vazia
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
    int obterTamanho();
};
