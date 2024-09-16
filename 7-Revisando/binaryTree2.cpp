#include <iostream>
using namespace std;

class Tree{
    struct Node{
        Node *left;
        int value;
        Node *right;
    }

    void destroyTree(){

    }



    public:

    Node *root;
    int height

    Tree(){
        root == nullptr;
        height = 0;
    }

    bool empty(){
        return root == nullptr;
    }

    ~Tree(){

    }

    insertLeaf(int e){
        Node *leaf = new Node{nullptr, e, nullptr} 
        if(empty()){
            height = 1
            root = leaf;
            return;
        }
        
    }


}