#include <bits/stdc++.h>




using namespace std;

void bubble_sort(int n,int a[]);
void bubble_sort(int n,int a[]){
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
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
    bubble_sort(n,a);
    for (int i = 0; i < n; i++)
    {
        std::cout<<a[i]<<" " ;
    }




    return 0;
}



