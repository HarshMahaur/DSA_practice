#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

void mergearr(int x[],int y[],int a[],int s, int e);
void mergesort(int a[],int s, int e);
void mergearr(int x[],int y[],int a[],int s, int e){
    int mid=(s+e)/2;
    int i=s, j=mid+1, k=s;
    while (i<=mid && j<=e)
    {
        if (x[i]<y[j])
        {
            a[k]=x[i];
            i++;
            k++;
        }
        else{
            a[k]=y[j];
            j++;
            k++;
        }
        
    }
    while(i<=mid){
        a[k]=x[i];
        i++;
        k++;
    }
    while(j<=e){
        a[k]=y[j];
        j++;
        k++;
    }

}

void mergesort(int a[],int s, int e){
    if(s>=e){
        return;
    }

    int mid= (s+e)/2;
    int x[100],y[100];
    for (int i=0;i<=mid;i++){
        x[i]=a[i];
    }
    for (int i=mid+1;i<=e;i++){
        y[i]=a[i];
    }
    mergesort(x,s,mid);
    mergesort(y,mid+1,e);
    mergearr(x,y,a,s,e);

}


int main(){
    int arr[]={7,8,5,8,9,1,2,3};
    mergesort(arr,0,7);


    for (int i = 0; i<7; i++)
    {
        std::cout<< arr[i] <<" ";
    }
    

    return 0;
}