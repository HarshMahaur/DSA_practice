#include <bits/stdc++.h>
using namespace std;
class PriorityQ{
    vector<int> pq;
    PriorityQ(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty){
            return 0; // pq is zero
        }
        return pq[0];
    }
    void removeMin(){
// this is my implimentation of code not by the sir- will varify later if it works;
        // int n = pq.size();
        // if(n==0){
        //     return;
        // }
        // pq[0]= pq[n-1];
        // pq.pop_back();
        // n= pq.size();
        // int i{0};
        // while((2*i+1<n && pq[i]>pq[2*i+1]) || (2*i+2<n && pq[i]>pq[2*i+2])){

        //     if(2*i+2<n && pq[2*i+1]>pq[2*i+2]){
        //         swap(pq[i], pq[2*i+2]);
        //         i=2*i+2;
        //     }
        //     else{
        //         swap(pq[i], pq[2*i+1]);
        //         i=2*i+1;
        //     }


        // }
        
    }
    void insert(int val){
        // this insert function code is mine not sir; needed to check if works
        pq.push_back(val);
        int n= pq.size();

        if(n==1){
            return;
        }
        int childInd= n-1;
        int parentInd=(childInd-1)/2;
        while(childInd>0 && pq[parentInd]>pq[childInd]){
            swap(pq[parentInd],pq[childInd]);
            childInd= parentInd;
            parentInd=(childInd-1)/2;
        }

//this is code by sir
        // pq.push_back(val);
        // int n= pq.size();
        // int cI= n-1;
        // while(childInd>0 ){
        //     int pI = (cI-1)/2;
        //     if(pq[cI]<pq[pI]){
        //         swap(pq[cI],pq[pI]);
        //         cI= pI;
        //     }
        //     else{
        //         break;
        //     }
        // }


    }
};


int main(){
    




    return 0;
}