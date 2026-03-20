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

    Node *insert_at_head(Node *head,int data){
        Node *newnode= new Node(data);




        newnode->next=head;
 
        return newnode;

        
    }

    void print_it(Node *head){
        Node *temp=head;
        while (temp!=NULL){
            std::cout<< temp->data << " -> ";
            temp= temp->next;
        }
        std::cout<< "NULL" <<std::endl;
    }

    int give_len(Node *head){
        int count{0};
        while (head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
        
};


int main(){
    
    





    int x{0};
    std::cin>>x ;
    Node *n1= new Node(x);
    Node *head=n1;
    n1->print_it(head);
    std::cout<< "------------------------" <<std::endl;
    std::cin>>x ;
    while (x!=-1)
    {
        
        head=n1->insert_at_head(head,x);
        // n1->print_it(head);
        // std::cout<< "------------------------" <<std::endl;
        std::cin>>x ;
    }
    



    n1->print_it(head);
    int len{n1->give_len(head)};
    std::cout<< "the length is : " << len <<std::endl;
    




    return 0;
}









