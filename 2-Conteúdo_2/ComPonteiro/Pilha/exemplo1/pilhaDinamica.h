typedef int TipoItem;


struct No
{
    TipoItem valor;
    No* proximo;
};




class pilhaDinamica
{
private:
    No* NoTopo;

public:
    pilhaDinamica();
    ~pilhaDinamica();
    bool estaVazio();
    bool estaCheio();
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
};

