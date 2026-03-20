#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

int partition(int a[],int s, int e){
    int i=s;
    int pivot= a[e];
    for(int j=s;j<=e;j++){
        if(a[j]<pivot){
            swap(a[i],a[j]);
          i++  ;
        }
    }
    swap(a[i],a[e]);
    return i;
}

void quicksort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int p= partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p,e);
}


int main(){
    int a[]= {34,45,6,3,78,4,10,57};
    quicksort(a,0,7);
    for(int i=0;i<8;i++){
        std::cout<< a[i] <<" ";
    }




    return 0;
}