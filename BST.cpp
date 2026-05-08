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
    private:
    BSTreeNode* root; 
    void printLevelWise(BTNode<int>* root){ // this code too is soly done by me first
    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<T>* f= q.front();
        q.pop();
        std::cout<< f->data <<std::endl;
        if(f->left){ q.push(f->left);}
        if(f->right){ q.push(f->right);}
        } 
    } 

    bool hasData(BTNode<int>*node , int data){
        if (node===NULL){
            return false;
        }
        if (node->data== data){
            return true;
        }
        if (node->data>data){
            return hasData(root->right,data);
        }
        if (node->data<data){
            return hasData(root->left,data);
        }
    }
    public:

    BST(){
        root= NULL;
    }
    ~BST(){
        delete root;
    }
    void print(){
        printLevelWise(root);
    }
    bool hasData(int data){
        return hasData(root,data);
    }
}
int main(){




    return 0;
}