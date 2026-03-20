#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Node{
    public:
        T data;
        Node<T>* next;

        Node(T data){
            this-> data =data;
            next =NULL;

        }
};
template <typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
        Queue(){
            head=NULL;
            tail=NULL;
            size=0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size==0;
        }

        void push(T elem){

            Node<T>* newnode=new Node<T>(elem);
            if (isEmpty()){
                head= newnode;
                tail= newnode;
                size++;
                return;
            }
            tail->next = newnode;
            tail=tail->next;
            size++;
            return; 



        } 
        T front(){
            if (isEmpty()){
                std::cout<< "queue is empty" <<std::endl;
                return 0;
            }
            return head->data;
        }

        void pop(){
            if (isEmpty()){
                std::cout<< "queue is empty" <<std::endl;
                return;
            }
            Node<T>* temp = head;
            head= head->next;
            delete temp;
            size--;


        }

};

int main(){
    
    Queue <int> niga;
    niga.push(100);    
    niga.push(200);    
    niga.push(300);    
    niga.push(500);   
    niga.push(600); 
    std::cout<< niga.getSize() <<std::endl;  
    niga.push(700);   
    niga.push(900);  
    niga.push(309);    
    niga.push(509);   
    
    std::cout<< niga.getSize() <<std::endl;  
    std::cout<< "-----------------------------------------" <<std::endl;    
    // std::cout<< niga.front() <<std::endl;   
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 
    // niga.pop();
    // std::cout<< niga.front() <<std::endl; 

    while (!niga.isEmpty())     
    {
        std::cout<< niga.front() <<std::endl;
        niga.pop();
    }
    std::cout<< niga.getSize() <<std::endl;
    

    return 0;
}