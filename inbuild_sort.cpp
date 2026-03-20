#include <bits/stdc++.h>




using namespace std;



int main(){
    int n{0};
    std::cin>>n ;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin>>a[i] ;
    }
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        std::cout<<a[i]<<" " ;
    }




    return 0;
}



