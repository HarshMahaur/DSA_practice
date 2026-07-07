#include <bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int fibo2(int n,int *arr){
    if(n==0 || n==1){
        return n;
    }
    if(arr[n]!=0){
        return arr[n];
    }
    int output= fibo2(n-1,arr)+ fibo2(n-2,arr);
    arr[n]=output; 
    return output;
}


int main(){
    int n;
    std::cin>>n ;
    int arr[n];
    cout<< fibo2(n,arr);




    return 0;
}