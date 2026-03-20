#include <bits/stdc++.h>
using namespace std;

void merge_sort(int a[],int s,int e);
void merge_sorted_arr(int x[],int y[],int a[],int s,int e);
void print_it(int n,int a[]);
void print_it(int n,int a[]){
    for(int i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
}


void merge_sorted_arr(int x[],int y[],int a[],int s,int e){
    int mid=(s+e)/2;
    int i{s},k{s},l{mid+1};
    while(k<=mid && l<=e)
    {
        if(x[k]<y[l]){
            a[i]=x[k];
            k++;
            i++;
        }
        else{
            a[i]=y[l];
            l++;
            i++;
        }
 
    }
    while(k<=mid){
        a[i]=x[k];
        k++;
        i++;
    }
    while(l<=e){
        a[i]=y[l];
        l++;
        i++;
    }
    
}

void merge_sort(int a[],int s,int e){
    if(s>=e) {return;}
    int mid=(e+s)/2;
    int x[100],y[100];
    for (int i = 0; i <= mid; i++)
    {
        x[i]=a[i];
    }
    for (int i = mid+1; i <=e; i++)
    {
        y[i]=a[i];
    }
    merge_sort(x,s,mid);
    merge_sort(y,mid+1,e);
    merge_sorted_arr(x,y,a,s,e);

}

int main(){
    int n{0};
    cin>>n;
    int a[n];
    for(int i=0 ;i<n;i++){
        std::cin>>  a[i];
    }
    merge_sort(a,0,n-1);

    // print_it(n,a);

    for(int i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }

    return 0;
}