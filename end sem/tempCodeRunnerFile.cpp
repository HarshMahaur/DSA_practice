#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int dat){
        data=dat;
        left= nullptr;
        right=nullptr;

    }

};
Node* insert(Node* head,int a){
    Node* curr=new Node(a);
    if(!head){

        return curr;
    }
    if(a>head->data){
        head->right=insert(head->right,a);
    }
    else{
        head->left=insert(head->left,a);
    }
    return head;
}
void inorder(Node* head){
    if(!(head)){
        return;
    }
    inorder(head->left);
    cout<<head->data<< " ";
    inorder(head->right);


}

int main(){
    int a;

    Node* head;

    while(1){
        cin>>a;
        if(a==-1){
            break;
        }
        head=insert(head,a);
        
    }

    inorder(head);



    return 0;
}
