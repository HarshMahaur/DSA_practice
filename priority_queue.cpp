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
        return pq[0];
    }
    void removeMin(){
        
        int n = pq.size();
        if(n==0){
            return;
        }
        pq[0]= pq[n-1];
        pq.pop_back();
        n= pq.size();
        int i{0};
        while((2*i+1<n && pq[i]>pq[2*i+1]) || (2*i+2<n && pq[i]>pq[2*i+2])){

            if(2*i+2<n && pq[2*i+1]>pq[2*i+2]){
                swap(pq[i], pq[2*i+2]);
                i=2*i+2;
            }
            else{
                swap(pq[i], pq[2*i+1]);
                i=2*i+1;
            }


        }
        
    }
};


int main(){
    




    return 0;
}