#include <bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int fibo2(int n,vector<int>& arr){
    if(n==0 || n==1){
        return n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int output= fibo2(n-1,arr)+ fibo2(n-2,arr);
    arr[n]=output; 
    return output;
}

int fibo3(int n){
    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n+1;i++){
        arr[i]= arr[i-1]+arr[i-2];
    }
    int output = arr[n];
    delete [] arr;
    return output;

}


int main(){
    int n;
    std::cin>>n ;
    vector<int> arr(n+1,-1);
    cout<< fibo2(n,arr);
    // cout<< fibo3(n);




    return 0;
}