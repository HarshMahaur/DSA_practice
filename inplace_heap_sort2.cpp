//inplace heap sort by sir

#include <bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int *pq, int n){
    for(int i =0;i<n;i++){
        int cI=i;
        while(cI>0){
            int pI= (cI-1)/2;
            if(pq[cI]<pq[pI]){
                swap(pq[cI],pq[pI]);
                cI=pI;

            }
            else{
                break;
            }
        }
    }
    

    int size=n;
    while(size>=1){
        swap(pq[0],pq[size-1]);
        size--;
        int pi =0;
        while(true){
            int lci = 2*pi+1;
            int rci= 2*pi+2;
            int mini= pi;
            if(size && pq[lci]<pq[mini]){
                mini= lci;
            }
            if(size && pq[rci]<pq[mini]){
                mini= rci;
            }
            if(mini ==pi){
                break;
            }
            swap(pq[pi],pq[mini]);
            pi=mini;
        }
    }

}

int main(){
    int input[]= {3,64,2,35,99,67,81};
    inplaceHeapSort(input,7);
    for(auto c : input ){
        std::cout<< c <<" ";
    }
    return 0;
}