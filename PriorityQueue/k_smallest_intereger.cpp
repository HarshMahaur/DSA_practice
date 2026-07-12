#include <bits/stdc++.h>
using namespace std;

//ocde with me
void kSmallestELem(int *a,int k, int n){
    int i{0};
    priority_queue<int> pq;
    while(i<k){
        pq.push(a[i]);
        i++;
    }

    //this is approach 1 with min pq
    // while(i<n){
    //     if(a[i]<pq.top()){
    //         pq.pop();
    //         pq.push(a[i]);
    //     }
    //     i++;
    // }


    //approach 2
    // while(i<n){
    //     pq.push(a[i]);
    //     if(pq.size()>k){
    //         pq.pop();
    //     }
    //     i++;

    // }


    // now to answer the elem;
    while(!pq.empty()){
        std::cout<< pq.top() <<" " ;
        pq.pop();
    }
}


int main(){
    int a[]= {5,6,9,12,3,13,2};
    kSmallestELem(a,3,7);
    




    return 0;
}