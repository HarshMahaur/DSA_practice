#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

class Node{
    private:
        int data;
    public:
    Node *next;
    Node(int a){
        data=a;
        next=NULL;
    }
    void print_it(Node *head){
        Node *temp=head;
        while (temp!=NULL){
            std::cout<< temp->data << " -> ";
            temp= temp->next;
        }
        std::cout<< "NULL" <<std::endl;
    }
};

int main(){
    Node *n1= new Node(1);
    Node *n2= new Node(2);
    Node *n3= new Node(3);


    n1->next=n2;
    n2->next=n3;

    Node *head=n1;
    n1->print_it(head);
    n1->print_it(head);




    return 0;
}