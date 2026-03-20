#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode( T data){
        this->data= data;
    }
    ~TreeNode(){
        for (int i=0; i<children.size();i++){
            delete children.at(i);
        }
    }
    
};

template <typename T>   
void printTree(TreeNode<T>* root){
    if (root == NULL){             //edge case not a base case
        return;
    }
    std::cout<< root->data << ": ";
    

    for (int i=0; i< root->children.size();i++){
        std::cout<< root->children[i]->data << ", ";
    }
    std::cout<<endl;
    for (int i=0; i< root->children.size();i++){
        printTree(root->children.at(i));
    }

}
// template <typename T>   
// TreeNode<T>* TakeInput(){
//     T dat;
//     std::cout<< "entere the data : " ;
//     std::cin>>dat ;
//     TreeNode<T>* root = new TreeNode<T>(dat);

//     int n;
//     std::cout<< "entere the no of children : " ; 
//     std::cin>> n ; 

//     for (int i=0; i<n;i++){
//         TreeNode<T>* child= TakeInput<int>();
//         root->children.push_back(child);
//     }
//     return root;


// }
template <typename T>
TreeNode<T>* TakeInputLevelWise(){
    T dat;
    std::cout<< "enter the data" <<std::endl;
    std::cin>>dat ;
    TreeNode<T>* root= new TreeNode<T>(dat);
    queue <TreeNode<T>*> q;
    q.push(root);
 
    while (!q.empty()){
        TreeNode<T>* f= q.front();
        q.pop();

        int n;
        std::cout<< "enter the no of children of "<< f->data <<std::endl;
        std::cin>> n;
        for (int i=1; i<=n;i++){
            T chdat;
            std::cout<< "enter "<<i<<"th of "<<f->data <<std::endl;
            std::cin>> chdat;
            TreeNode<T>* child= new TreeNode<T>(chdat);
            q.push(child);
            f->children.push_back(child);
        }
        
    }
    return root;
    

}
template <typename T>
void PrintLevelWise(TreeNode<T>* root){
    std::cout<< "---------------------------" <<std::endl;
    queue <TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()){
        TreeNode<T>* f= q.front();
        q.pop();
        std::cout<< f->data << ": ";


        for (int i=0; i<f->children.size();i++){
            
            std::cout<<f->children.at(i)->data<< ", " ;

            q.push(f->children.at(i));
        
        }
        std::cout<<std::endl;
        
    }
    

}
template <typename T>
void print_preorder(TreeNode<T>* root){
    if (root== NULL){
        return ;
    }
    std::cout<< root->data<< ", " ;
    for (int i=0;i<root->children.size();i++){
        print_preorder(root->children.at(i));
    }

}
template <typename T>
void print_postorder(TreeNode<T>* root){
    if (root== NULL){
        return ;
    }
    for (int i=0;i<root->children.size();i++){
        print_postorder(root->children.at(i));
    }
    std::cout<< root->data<< ", " ;

}



template <typename T>
int CountNode(TreeNode<T>* root){
    if (root== NULL){
        return 0;
    }

    int count=0 ;
    for (int i=0;i<root->children.size();i++){
        count= count + CountNode(root->children.at(i));
    }
    return count+1;

}
template <typename T>
int TreeHeight(TreeNode<T>* root){
    if (root== NULL){
        return 0;
    }
    

    int mx=0 ;
    for (int i=0;i<root->children.size();i++){
        // int count=  CountNode(root->children.at(i));
        // if (count>max){
        //     mx= count;
        // }
        mx = max(mx,TreeHeight(root->children.at(i)));
    }
    return mx+1;

}

template <typename T>
void KthNode(TreeNode<T>* root, int k){
    if (root== NULL){
        return;
    }
    
    if(k==0){
        std::cout<< root->data <<std::endl;
    }
    else{
        for(int i=0;i<root->children.size();i++){
            KthNode(root->children.at(i),k-1);
        }
    }
}

template <typename T>
int CountLeaf(TreeNode<T>* root){

    int val{0};
    int flag=0;
    for (int i=0;i<root->children.size();i++){
        val+=CountLeaf(root->children.at(i));
        flag=1;
    }
    if(flag==0){
        return val+1;
    }
    else{
        return val;
    }
}

template <typename T>
void delete_tree(TreeNode<T>* root){
    if (root== NULL){
        return ;
    }
    for (int i=0;i<root->children.size();i++){
        delete_tree(root->children.at(i));
    }
    delete root; ;

}



// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0


int main(){
    // TreeNode<char>* root= new TreeNode<char>('t');
    // TreeNode<char>* n1= new TreeNode<char>('n');
    // TreeNode<char>* n2= new TreeNode<char>('i');

    // root->children.push_back(n1);
    // root->children.push_back(n2);
    TreeNode<char>* root = TakeInputLevelWise<char>();
    PrintLevelWise(root);
    std::cout<< "--------------------------" <<std::endl;
    std::cout<< CountNode(root) <<std::endl;
    std::cout<< "--------------------------" <<std::endl;
    std::cout<< TreeHeight(root) <<std::endl;
    std::cout<< "--------------------------" <<std::endl;
    KthNode(root,2);
    std::cout<< "--------------------------" <<std::endl;
    std::cout<< CountLeaf(root) <<std::endl;
    
    std::cout<< "--------------------------" <<std::endl;
    print_postorder(root);
    // delete_tree(root);
    delete root;  // will call the distructor that delete the child as well.



    return 0;
}