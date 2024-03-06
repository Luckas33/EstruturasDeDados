typedef int TipoItem;
const int max_itens = 5;


class Fila{
    private:
        int p,u;
        TipoItem *estrutura;
    public:
        Fila();
        ~Fila();
        void inserir(TipoItem item);
        void desenfilar();
        bool isFull();
        bool isEmpty();
        void imprimir();
};