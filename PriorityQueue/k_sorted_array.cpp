#include <bits/stdc++.h>
using namespace std;

//code by me

void kSortedArray(int *input, int k, int n){
    priority_queue<int> pq;
    int i{0};
    while(i<k){
        pq.push(input[i]);
        i++;
    }
    int start=0;
    while(i<n){
        
        input[start]= pq.top();
        pq.pop();
        pq.push(input[i]);
        i++;
        start++;
    }
    while(!pq.empty()){
        input[start]=pq.top();
        pq.pop();
        start++;
    }
}

int main(){
    int input[]= {10,12,6,7,9};
    int k = 3;
    kSortedArray(input,5,k);
    for(auto c:input){
        std::cout<< c <<" " ;
    }

    




    return 0;
}