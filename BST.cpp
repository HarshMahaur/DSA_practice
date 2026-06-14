#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BSTreeNode{

    
    
    public:
    T data;  
    BSTreeNode* left;
    BSTreeNode* right;



    BSTreeNode(T a){
        this->data = a;
        left  = NULL;
        right = NULL;
    }
    ~BSTreeNode(){
        delete left;
        delete right;
    }

};

class BST{
    private:
    BSTreeNode<int>* root; 
    void printLevelWise(BSTreeNode<int>* root){ // this code too is soly done by me first
    queue<BSTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BSTreeNode<int>* f= q.front();
        q.pop();
        std::cout<< f->data <<std::endl;
        if(f->left){ q.push(f->left);}
        if(f->right){ q.push(f->right);}
        } 
    } 

    bool hasData(BSTreeNode<int>* node , int data){
        if (node==NULL){
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
  
    BSTreeNode<int>* insert_data(BSTreeNode<int>* root, int data){
        if (!root){
            return new BSTreeNode<int>(data);
            
        }
        if(root->data<data){
            root->right = insert_data(root->right, data);
        }
        else{
            root->left = insert_data(root->left, data);

        }
        return root;
    }
    //========================================
    //convert BST to sorted Linked list
    void printRight(BSTreeNode<int>* head) {
        if (head == nullptr) {
            return;
        }

        std::cout << head->data << " ";
        printRight(head->right);
    }



    std::pair<BSTreeNode<int>*, BSTreeNode<int>*> converter(BSTreeNode<int>* head){
        if (head== NULL){
            return {nullptr,nullptr};
        }
        if (head->left==NULL && head->right==NULL){
            return {head,head};
        }
        else if(head->left!=NULL){
            pair<BSTreeNode<int>*, BSTreeNode<int>*> lefter ;
            lefter = converter(head->left);
            if(head->right == NULL){
                
                lefter.second->right= head;
                lefter.second->left= NULL;
                head->left = NULL;

                lefter.second = head;
                head->left = NULL;
                return lefter;

            }
            pair<BSTreeNode<int>*, BSTreeNode<int>*> righter ;
            righter = converter(head->right);
            lefter.second->right= head;
            lefter.second->left = NULL;
            head->right= righter.first;
            head->left = NULL;
            return {lefter.first, righter.second};


        }
        else{
            pair<BSTreeNode<int>*, BSTreeNode<int>*> righter ;
            righter = converter(head->right);
            head->right = righter.first;
            righter.first= head;
            head->left = NULL;
            return righter;

        }


    }
    //========================================



    //=======================================================
    //this code of deletion was soly done by me
    

    BSTreeNode<int>* get_right_min(BSTreeNode<int>* root){
        if (root->left == nullptr){
            return root;
        }
        return get_right_min(root->left);
    }
    BSTreeNode<int>* delete_data(BSTreeNode<int>* root, int data){
        if (root==nullptr){
            std::cout<< "no data found" <<std::endl;
            return NULL;
        }
        if (root->data==data){
            if(root->right){
                if (!root->left){
                BSTreeNode<int>* temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;                    
                }
                BSTreeNode<int>* temp = get_right_min(root->right);
                root->data= temp->data; 
                root->right=delete_data(root->right,temp->data);

            }else if (root->left){
                if(!root->right){
                    BSTreeNode<int>* temp = root->left;
                    root->left= nullptr;  // this is important as our distructor is recursive 
                    delete root;
                    return temp;               
                }
            }else{
                delete root;
                return nullptr;
            }

        }
        else if (root->data>data){
            root->left = delete_data(root->left,data);
        }
        else{
            root->right = delete_data(root->right,data);
        }
        return root;
    }
    //================================================================ 
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
    bool finder(int data){
        return hasData(root,data);
    }
    void  insert(int data){
        root= insert_data(root,data);
    }
    void  delete_it(int data){
        root= delete_data(root,data);
    }
    BSTreeNode<int>* toLinkedList() {
        return converter(root).first;
    }
    void printLL(BSTreeNode<int>* root){
        printRight(root);

    }
};
int main(){
    BST b;
    b.insert(10);
    b.insert(67);
    b.insert(55);
    b.insert(22);
    b.insert(32);
    b.insert(99);
    b.insert(72);
    b.insert(100);
    b.insert(81);



    b.delete_it(67);
    b.print();
    BSTreeNode<int>* head = b.toLinkedList(); 
    b.printLL(head);

    //other changes


    return 0;
}