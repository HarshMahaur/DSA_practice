#include <bits/stdc++.h>
using namespace std;

void insertionsort(int a[],int n){
    for(int i=0;i<n;i++){
        int key=a[i];
         int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int a[]={59,6,3,64,10,92};
    insertionsort(a,6);

    for(int i=0;i<6;i++){
        std::cout<< a[i] <<" ";
    }



    return 0;
}