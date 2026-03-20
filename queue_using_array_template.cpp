#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Queue{
    T *arr;
    int nextIndex;
    int frontIndex;
    int size;
    int capacity ;

    public:
        Queue(){
            capacity=5;
            arr= new T[capacity];
            frontIndex=-1;
            nextIndex=0;
            size=0;
        }
        Queue(int cap){
            capacity=cap;
            arr= new T[capacity];
            frontIndex=-1;
            nextIndex=0;
            size=0; 
        } 
        int get_size(){
            return size;
        }
        bool is_empty(){
            return size==0; 
        }
        // insert the element
        void push(T data){
            if (capacity==size){
                T *arr2 =new T[2*capacity];
                int j=0;
                for(int i =0 ; i<size;i++){
                    arr2[j]= arr[(nextIndex+i)%capacity];
                    j++;

                }
                frontIndex=0;
                nextIndex=capacity;
                capacity*=2;
                delete []arr;
                arr=arr2;
                

            }
            arr[nextIndex]=data;
            nextIndex= (nextIndex+1)%capacity;
            if(frontIndex==-1){
                frontIndex= 0;
            }
            size++;
        }   
        T front(){
            if (is_empty()){
                return 0;
            }
            return arr[frontIndex];
        }  
        void pop(){
            frontIndex= (frontIndex+1)%capacity;
            size--;
            // if (size==0){
            //     //reset the values bro
            //     //this is optional
            //     frontIndex= -1;
            //     nextIndex=0;
            // }
        }   
        



};


int main(){
    Queue <int> niga(4);
    niga.push(100);    
    niga.push(200);    
    niga.push(300);    
    niga.push(500);   
    niga.push(600); 
    std::cout<< niga.get_size() <<std::endl;  
    niga.push(700);   
    niga.push(900);  
    niga.push(309);    
    niga.push(509);   
    
    std::cout<< niga.get_size() <<std::endl;  
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





    
    
    
    
    return 0;
}