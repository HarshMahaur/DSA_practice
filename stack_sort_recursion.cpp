#include <bits/stdc++.h>
using namespace std;

void sort_it(stack <int> &n1, int n);  
void print_stk(stack <int> n1);
void insert_at_bot(stack <int> &n1,int dat);
int find_gr(stack <int> &n1,int gr,int n, int m);  

int find_gr(stack <int> &n1,int gr,int n,int m){



    if(m==n){
        return gr;
    }
    int temp=n1.top();
    if(temp>gr){
        gr=temp;
    }
    n1.pop();
    gr = find_gr(n1,gr,n,m+1);
    n1.push(temp);
    return gr;
 



}
void insert_at_bot(stack <int> &n1,int dat){
    if(n1.empty()){
        n1.push(dat);
        return;
    }
    int dat2=n1.top();
    n1.pop();

    insert_at_bot(n1,dat);
    if(dat2!=dat){       
        n1.push(dat2);
    }

}
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
void sort_it(stack <int> &n1, int n){
    if(n==0){
        return;
    }
    int gr= n1.top();
    gr= find_gr(n1,gr,n,0);


    insert_at_bot(n1,gr);
    sort_it(n1,n-1);
    
    
}


int main(){
    int n;
    std::cin>>n ;
    stack <int> n1;
    for (int i=0;i<n;i++){
        int int_dat;
        std::cin>>int_dat ;
        n1.push(int_dat);
    }  


     sort_it(n1,n);
     print_stk(n1);
 




    return 0;
}