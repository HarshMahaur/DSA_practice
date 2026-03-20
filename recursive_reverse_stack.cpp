#include <bits/stdc++.h>
using namespace std;
void insert_at_bot(stack <int> &n1,int dat);
void insert_at_bot(stack <int> &n1,int dat){
    if(n1.empty()){
        n1.push(dat);
        return;
    }
    int dat2=n1.top();
    n1.pop();
    insert_at_bot(n1,dat);
    n1.push(dat2);

}

void reverse_ing(stack <int> &n1);            
void reverse_ing(stack <int> &n1){
    if(n1.empty()){
        return;
    }
    int dat=n1.top();
    n1.pop();
    reverse_ing(n1);
    insert_at_bot(n1,dat);
  
}

void print_stk(stack <int> n1);
void print_stk(stack <int> n1){
    if(n1.empty()){
        return;
    }
    int dat=n1.top();
    n1.pop();
    print_stk(n1);
    std::cout<<  dat<<" ";
    n1.push(dat);

}

int main(){
    int n{0};
    cin>>n;
    stack <int> n1;

    for (int i=0;i<n;i++){
        int int_dat;
        std::cin>>int_dat ;
        n1.push(int_dat);
    }
    print_stk(n1);
    reverse_ing(n1);

    std::cout<< "" <<std::endl;

    print_stk(n1);

    






    return 0;
}