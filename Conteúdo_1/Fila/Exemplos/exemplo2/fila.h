typedef int TipoItem;
const int MAX_ITENS = 50;

class fila{
    private:
        int primeiro, ultimo;
        TipoItem* estrutura;

    public:
        fila();
        ~fila();
        bool estaVazio();
        bool estaCheio();
        void inserir(TipoItem item);
        TipoItem remover();
        void imprimir();
};
