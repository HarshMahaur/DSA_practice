#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BSTreeNode{
    private:
    T data;
    public:
    BSTreeNode* left;
    BSTreeNode* right;

    BSTree(T a){
        this->data = a;
        left  = NULL;
        right = NULL;
    }
    ~BSTree{
        delete left;
        delete right;
    }
}

class BST{
    public:
    
    BST(){

    }
}
int main(){




    return 0;
}