#include <iostream>
using namespace std;

class Tree
{
    struct Node
    {
        int value;
        Node *left;
        Node *right;
    };

public:
    Node *root;
    int height;

    Tree()
    {
        root = nullptr;
        height = 0;
    }

    ~Tree()
    {
        destroyTree(root);
    }

    void destroyTree(Node *node)
    {
        if (node == nullptr)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    bool empty()
    {
        return root == nullptr;
    }

    int H(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        int left_height = H(n->left);
        int right_height = H(n->right);
        return 1 + max(left_height, right_height);
    }

    void insert(int item)
    {
        Node *leaf = new Node{
            item,
            nullptr,
            nullptr,
        };
        if (empty())
        { // Caso arvore vazia
            root = leaf;
            height = 1;
        }
        // Caso arvore nao vazia
        Node *temp = root;
        while (true)
        {
            if (item < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = leaf;
                    height = H(root);
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = leaf;
                    height = H(root);
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void remove(int item)
    {
        if (!belongs(item))
        {
            cout << "Erro!" << endl;
            return;
        }
        Node *n = root;
        Node **up = &root;

        while (n != nullptr)
        {
            if (item < n->value)
            {
                up = &n->left;
                n = n->left;
            }
            else if (item > n->value)
            {
                up = &n->right;
                n = n->right;
            }
            else
                break;
        }

        if (n == nullptr)
            return;

        if (n->right == nullptr)
        {
            *up = n->left;
        }
        else if (n->left == nullptr)
        {
            *up = n->right;
        }
        else
        { // two childs
            Node *s = n->right;
            Node **up_s = &n->right;
            while (s->left != nullptr)
            {
                up_s = &s->left;
                s = s->left;
            }

            *up_s = s->right;
            *up = s;
            s->left = n->left;
            s->right = n->right;
        }
        delete n;
    }
    void insert_if_new(int item)
    {
        if (!belongs(item))
        {
            insert(item);
        }
    }
    bool belongs(int e)
    {
        Node *n = root;
        while (n != nullptr)
        {
            if (n->value == e)
                return true;
            if (e < n->value)
                n = n->left;
            else
                n = n->right;
        }
        return false;
    }

    void display(Node *node)
    {
        if (root == nullptr)
            return;
        display(node->left);
        cout << node->value << " ";
        display(node->right);
    }
};

int main()
{
    Tree tree;

    // Testando inserções
    cout << "Inserindo elementos: 5, 3, 7, 2, 4, 6, 8" << endl;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Verificando se os elementos foram inseridos
    cout << "Elementos da árvore (em ordem): ";
    tree.display(tree.root); // Corrigido para tree.root
    cout << endl;

    // Testando a função insert_if_new
    cout << "Inserindo o elemento 3 novamente (deve ser ignorado):" << endl;
    tree.insert_if_new(3);
    cout << "Elementos da árvore (em ordem): ";
    tree.display(tree.root);
    cout << endl;

    // Testando busca
    cout << "Verificando se 6 está na árvore: " << (tree.belongs(6) ? "Sim" : "Não") << endl;
    cout << "Verificando se 10 está na árvore: " << (tree.belongs(10) ? "Sim" : "Não") << endl;

    // Testando remoção
    cout << "Removendo o elemento 5 (raiz):" << endl;
    tree.remove(5);
    cout << "Elementos da árvore (em ordem): ";
    tree.display(tree.root);
    cout << endl;

    cout << "Removendo o elemento 3:" << endl;
    tree.remove(3);
    cout << "Elementos da árvore (em ordem): ";
    tree.display(tree.root);
    cout << endl;

    cout << "Removendo o elemento 7:" << endl;
    tree.remove(7);
    cout << "Elementos da árvore (em ordem): ";
    tree.display(tree.root);
    cout << endl;

    return 0;
}