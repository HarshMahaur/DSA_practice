#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

void selection_sort(int n,int a[]);
void selection_sort(int n,int a[]){
    for(int i=0;i<=n-2;i++){
        int sml_ind=i;
        for (int j=i+1;j<=n-1;j++){
            if(a[j]<a[sml_ind]){
                sml_ind=j;
            }
        }
        swap(a[i],a[sml_ind]);
    }
    
}

int main(){
    int n{0};
    std::cin>>n ;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin>>a[i] ;
    }
    selection_sort(n,a);
    for (int i = 0; i < n; i++)
    {
        std::cout<<a[i]<<" " ;
    }




    return 0;
}