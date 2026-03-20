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
    int get_data(Node *the_element){
        return the_element->data;
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

    Node *print_ith(Node *head, int i){
        int index{0};

        if (i<index){
            std::cout<<"invalid index" <<std::endl;
        }
        

        Node *temp=head;
        while (temp)
        {
            if(index==i){
                return temp;
            }
             temp=temp->next;
            index++;
        }
        std::cout<< "your index is invalid " <<std::endl;
        return head;
        

    }

    Node *insert_ith_elem(Node *head, int new_elem_ind){
        if (new_elem_ind<0)
        {
            std::cout<< -1 <<std::endl;
            return head;
        }
        std::cout<< "enter the elem data: " <<std::endl;
        int new_elem{0};
        std::cin>>new_elem ;
        Node *newnode= new Node (new_elem);
        
        if (new_elem_ind==0)
        {
            newnode->next=head;
            head=newnode;
            return head;
        }
        


        Node  *temp= head;
        int the_ind{0};
        while (temp)
        {

            if(the_ind==new_elem_ind-1){
                newnode->next=temp->next;
                temp->next=newnode;
                return head;
                
            }
            the_ind++;
            temp= temp->next;
        }
        std::cout<< -1 <<std::endl;
        return head;
        
    }

    Node *delete_ith_elem(Node *head, int new_elem_ind){
        if (new_elem_ind<0)
        {
            std::cout<< -1 <<std::endl;
            return head;
        }

        Node  *temp= head;
        Node  *temp2= head->next;
        if (new_elem_ind==0)
        {

            delete temp;
            std::cout<< temp->get_data(temp) <<std::endl;
            return temp2;
        }
        int the_ind{0};
        while (temp2)
        {

            if(the_ind==new_elem_ind-1){
                temp->next=temp2->next;
                delete temp2;
                return head;
                
            }
            the_ind++;
            temp= temp->next;
            temp2= temp2->next;

        }
        std::cout<< -1 <<std::endl;
        return head;
        
    }
        
};


int main(){

    int x{0};
    std::cin>>x ;

    Node *n1= new Node(x);
    Node *head=n1;
    // n1->print_it(head);
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
/*


    std::cout<< "enter the elem index you want: " <<std::endl;
    int elem_ind{0};
    std::cin>>elem_ind ;


    
    // if (elem_ind>len)
    // {
    //     std::cout<< "your index is invalid " <<std::endl;
    // }
    // else{
        Node *the_elem= n1->print_ith(head,elem_ind);
        std::cout<<"the req element is : "<< the_elem->get_data(the_elem) <<std::endl;
     
    // }
    

    std::cout<< "enter the elem index you want to put in : " <<std::endl;
    int new_elem_ind{0};
    std::cin>>new_elem_ind ;



    head=n1->insert_ith_elem(head,new_elem_ind);
    n1->print_it(head);
*/
    std::cout<< "enter the elem index you want to delete  : " <<std::endl;
    int del_elem_ind{0};
    std::cin>>del_elem_ind ;

    head=n1->delete_ith_elem(head,del_elem_ind);
    n1->print_it(head);


 
    return 0;
}





