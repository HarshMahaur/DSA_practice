#include <bits/stdc++.h>
using namespace std;
template < typename T>
class BTNode{
    public:
        T data;
        BTNode* left;
        BTNode* right;

        BTNode(T dat){
            data=dat;
            left= NULL;
            right= NULL;
        }
        ~BTNode(){
            delete left;
            delete right;
        }

};
template < typename T>
void printBT(BTNode<T>* root){  // this was my way to print the tree but same logic  taught later
    if (root==NULL){
        return;
    }

    std::cout<< root->data<< " : " ;
    if(root->left){
        std::cout<<""<<root->left->data;
    }
    if(root->right){
        std::cout<<" , "<< root->right->data;
    }
    std::cout <<std::endl;
    printBT(root->left);
    printBT(root->right);


}
template < typename T>
void printBT_bysir(BTNode<T>* root){  // this was by the sir.
    if (root==NULL){
        return;
    }
    std::cout<< root->data<<endl;
    printBT_bysir(root->left);
    printBT_bysir(root->right);


}
template <typename T>
BTNode<T>* TakeInput(){ // this code too is soly done by me first
    T data;
    // std::cout<< "enter the data" <<std::endl;
    std::cin>>data ;
    BTNode<T>* root = new BTNode<T>(data);
    if (data==-1){
        return NULL; 
    }
    root->left= TakeInput<T>();
    root->right = TakeInput<T>();
    return root;

}
template <typename T>
BTNode<T>* TakeInputLevelWise(){ // this code too is soly done by me first
    T data;
    std::cout<< "enter the data:" <<std::endl;
    std::cin>>data ;
    BTNode<T>* root = new BTNode<T>(data);
    queue<BTNode<T>*> q;
    q.push(root);
    
    while (!q.empty()){
        BTNode<T>* f= q.front();
        q.pop();
        std::cout<< "enter the left child of "<<f->data <<std::endl;
        T chdatL;
        std::cin>>chdatL ;
        BTNode<T>* leftch= new BTNode<T>(chdatL);
        
        if(chdatL==-1) {
            leftch= NULL;
        }
        std::cout<< "enter the right child of "<<f->data <<std::endl;
        T chdatR;
        std::cin>>chdatR ;
        BTNode<T>* rightch= new BTNode<T>(chdatR);
        if(chdatR==-1) {
            rightch= NULL;
        }
        if (leftch){q.push(leftch);} 
        if (rightch){q.push(rightch);} 
        f->left= leftch;
        f->right= rightch;   
    }
    return root;
}
template <typename T>
void printLevelWise(BTNode<T>* root){ // this code too is soly done by me first
    queue<BTNode<T>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<T>* f= q.front();
        q.pop();
        std::cout<< f->data <<std::endl;
        if(f->left){ q.push(f->left);}
        if(f->right){ q.push(f->right);}
    }    
}
template <typename T>
bool findNode(BTNode<T>* root,  T key){
    if (root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    return findNode(root->left, key) || findNode(root->right,key);
}

template <typename T>
int minVal(BTNode<T>* root){
    if (root==NULL){
        return INT_MAX;
    }
    int l= root->data;
    if(root->left) l= min(l,minVal(root->left));
    if(root->right) l= min(l,minVal(root->right));
    return l;

}
template <typename T>
int maxVal(BTNode<T>* root){
    if (root==NULL){
        return INT_MIN;
    }
    int l= root->data;
    if(root->left) l= max(l,maxVal(root->left));
    if(root->right) l= max(l,maxVal(root->right));
    return l;

}
 
template <typename T>
int noOfLeaf(BTNode<T>* root){
    if (root==NULL){
        return 0;
    }
    int l{0};
    if (root->left) l= l+noOfLeaf(root->left);
    if (root->right) l= l+noOfLeaf(root->right);

    if (root->left==NULL && root->right==NULL){
        return 1;
    }
    return l;
}


template <typename T>
bool getPath(BTNode<T>* root, int val, vector<int> &v ){
    if (root==NULL){
        return false;
    }
    v.push_back(root->data);
    if (root->data==val){
        return true;
    }
    else{
        if (getPath(root->left,val,v) || getPath(root->right,val,v)){
            return true; 
        } 
        else{
            v.pop_back();
            return false;
        } 
    }
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BTNode<int>* root = TakeInputLevelWise<int>();
    // printLevelWise(root);
    // std::cout<< "------------------------------------------" <<std::endl;
    // cout<<findNode(root, 28)<<endl;
    // std::cout<< "------------------------------------------" <<std::endl;
    // cout<<minVal(root)<<endl;
    // std::cout<< "------------------------------------------" <<std::endl;
    // cout<<maxVal(root)<<endl;
    // std::cout<< "------------------------------------------" <<std::endl;
    // cout<<noOfLeaf(root)<<endl;
    std::cout<< "------------------------------------------" <<std::endl;
    vector<int> v1;
    if (getPath(root, 9, v1)){
        std::cout<< "we got em" <<std::endl;
        for(int i=0;i<v1.size();i++){
            std::cout<< v1[i]<<" -> ";
        }
    }
    else{
        std::cout<< " not found " <<std::endl;
    }
    




    return 0;
}